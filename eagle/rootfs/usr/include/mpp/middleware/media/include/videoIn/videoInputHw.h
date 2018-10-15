#ifndef __VIDEOINPUT_HW__
#define __VIDEOINPUT_HW__

//ref platform headers
#include <plat_defines.h>
#include <plat_errno.h>
#include <plat_math.h>
#include <plat_type.h>

//media api headers to app
#include <mm_common.h>
#include <mm_component.h>
#include <tmessage.h>
#include <tsemaphore.h>

#include "mm_comm_vi.h"
#include <mm_comm_region.h>

#include "isp_manage.h"

#include <OsdGroups.h>
#include "anti-shake.h"

#define VI_CSI_NUM_MAX 2
// #define VI_DEV_NUM_MAX 2
// #define VI_CHN_NUM_MAX 4
#define VI_ISP_NUM_MAX 2
#define VI_VIPP_NUM_MAX 4
#define VI_VIRCHN_NUM_MAX 4
#define VI_HIGH_FRAMERATE_STANDARD (60)    //>60 is high frame rate.
#define MEDIA_DEVICE "/dev/media0"

//typedef enum VI_CHANNEL_PORT_DEFINE_E {
//	VI_CHN_PORT_INDEX_CAP_IN = 0,
//	VI_CHN_PORT_INDEX_FILE_IN, /* FILE_IN : Decode H26x,mpeg data, or yuv file input*/
//	VI_CHN_PORT_INDEX_OUT,
//	VI_CHN_MAX_PORTS,
//} VI_CHANNEL_PORT_DEFINE_E;

typedef struct VI_CHN_MAP_S {
    int mThdRunning;
    // VI_DEV mViDev;             
	/* DevX = SensorX; // X = 0,1,2,3 */
	/* ChnX = ScaleX;  // X = 0,1,2...16 */
    VI_CHN mViChn;             
    MM_COMPONENTTYPE *mViComp; /* video vi component instance */
    cdx_sem_t mSemCompCmd;
    MPPCallbackInfo mCallbackInfo;
    struct list_head mList;
} VI_CHN_MAP_S;

typedef struct {
	pthread_t threadid;
	pthread_t threadid_gyro;
	pthread_t threadid_videoPorcess;
	VI_DEV  vipp_dev_id; /* vipp id num */
	int	vipp_enable; /* 1:enable; 0:disable. default=0. */
    struct list_head mChnList;  //element type: VI_CHN_MAP_S
    pthread_mutex_t mLock;

	int 	refs[32];
    VIDEO_FRAME_INFO_S	VideoFrameInfo[32];
    pthread_mutex_t mRefsLock;

    //osd manage    
    pthread_mutex_t mRegionLock;
    struct list_head mOverlayList;    //ChannelRegionInfo
    struct list_head mCoverList;    //ChannelRegionInfo

    //for osd reconstruct
    OsdGroups *mpOsdGroups;
    RGN_FLIP_FLAG_E mRgnFlipFlag;

    // for video stabilization
    int mEnableVideoStabilization; // 0:disable, 1:enable
    /* int mProcessStep;*/ /* 1:VideoStabilizationProcessThread 
                         2:VideoStabilizationCapThread */
    video_stabilization_t mVideoStabilization;
    cdx_sem_t videostabilization_sync_exit;
     // pthread_cond_t q_cnd_gyro;
     // pthread_cond_t q_cnd_save;
     // pthread_cond_t q_cnd_sync;
     // pthread_mutex_t q_mtx;
} viChnManager;

typedef struct VIDevManager
{
    pthread_mutex_t             mManagerLock;
    viChnManager                *gpVippManager[VI_VIPP_NUM_MAX];
    struct hw_isp_media_dev     *media;
    BOOL                        mSetFrequency; //TRUE:had set .  FALSE: ready to set.
    unsigned int                mClockFrequency; //
}VIDevManager;

//extern struct hw_isp_media_dev *media;

ERRORTYPE videoInputHw_Construct(int vipp_id);
ERRORTYPE videoInputHw_Destruct(int vipp_id);
ERRORTYPE videoInputHw_addChannel(int vipp_id, VI_CHN_MAP_S *pChn);
ERRORTYPE videoInputHw_removeChannel(int vipp_id, VI_CHN_MAP_S *pChn);
ERRORTYPE videoInputHw_searchExistDevVirChn(VI_DEV vipp_id,VI_CHN ViChn, VI_CHN_MAP_S **ppChn);
MM_COMPONENTTYPE *videoInputHw_GetChnComp(VI_DEV ViDev, VI_CHN ViChn);
VI_CHN_MAP_S *videoInputHw_CHN_MAP_S_Construct();
void videoInputHw_CHN_MAP_S_Destruct(VI_CHN_MAP_S *pChannel);

ERRORTYPE videoInputHw_initVipp(VI_DEV Vipp_id);
ERRORTYPE videoInputHw_setVippEnable(VI_DEV Vipp_id);
ERRORTYPE videoInputHw_setVippDisable(VI_DEV Vipp_id);
ERRORTYPE videoInputHw_SetVippShutterTime(VI_DEV Vipp_id, VI_SHUTTIME_CFG_S *pShutTime);
ERRORTYPE videoInputHw_searchVippStatus(VI_DEV Vipp_id, int *pStatus);

ERRORTYPE videoInputHw_Open_Media(); /*Open Media+ISP+CSI Device*/
ERRORTYPE videoInputHw_Close_Media(); /*Close Media+ISP+CSI Device*/
ERRORTYPE videoInputHw_ChnInit(int vipp_id); /*Open /dev/video[0~3] node*/
ERRORTYPE videoInputHw_ChnExit(int vipp_id); /*Close /dev/video[0~3] node*/
ERRORTYPE videoInputHw_SetChnAttr(VI_DEV vipp_id, VI_ATTR_S *pstAttr); /*Set /dev/video[0~3] node attr*/
ERRORTYPE videoInputHw_GetChnAttr(VI_DEV vipp_id, VI_ATTR_S *pstAttr); /*Get /dev/video[0~3] node attr*/
ERRORTYPE videoInputHw_SetVIFreq(VI_DEV ViDev, int nFreq);
ERRORTYPE videoInputHw_ChnEnable(int vipp_id); /*Enable /dev/video[0~3] node*/
ERRORTYPE videoInputHw_ChnDisable(int vipp_id); /*Disable /dev/video[0~3] node*/
//ERRORTYPE videoInputHw_SetOsdMaskRegion(int *pvipp_id, VI_OsdMaskRegion *pstOsdMaskRegion);
//ERRORTYPE videoInputHw_UpdateOsdMaskRegion(int *pvipp_id, int onoff);
ERRORTYPE videoInputHw_SetRegionFlipFlag(VI_DEV vipp_id, RGN_FLIP_FLAG_E FlipFlag);
ERRORTYPE videoInputHw_SetRegion(VI_DEV vipp_id, RGN_HANDLE RgnHandle, RGN_ATTR_S *pRgnAttr, const RGN_CHN_ATTR_S *pRgnChnAttr, BITMAP_S *pBmp);
ERRORTYPE videoInputHw_DeleteRegion(VI_DEV vipp_id, RGN_HANDLE RgnHandle);
ERRORTYPE videoInputHw_UpdateOverlayBitmap(VI_DEV vipp_id, RGN_HANDLE RgnHandle, BITMAP_S *pBitmap);
ERRORTYPE videoInputHw_UpdateRegionChnAttr(VI_DEV ViDev, RGN_HANDLE RgnHandle, const RGN_CHN_ATTR_S *pRgnChnAttr);
ERRORTYPE videoInputHw_RefsReduceAndRleaseData(int vipp_id, VIDEO_FRAME_INFO_S *pstFrameInfo, int step);

ERRORTYPE videoInputHw_GetFrameSyncStart(int *pvipp_id, int *pExpTime, int *pFrameid, int nMilliSec);

ERRORTYPE videoInputHw_IspAe_SetMode(int *pvipp_id, int value);
ERRORTYPE videoInputHw_IspAe_SetExposureBias(int *pvipp_id, int value);
ERRORTYPE videoInputHw_IspAe_SetExposure(int *pvipp_id, int value);
ERRORTYPE videoInputHw_IspAe_SetExposureMs(int *pvipp_id, int value);
ERRORTYPE videoInputHw_IspAe_SetISOSensitiveMode(int *pvipp_id, int mode);
ERRORTYPE videoInputHw_IspAe_SetISOSensitive(int *pvipp_id, int value);
ERRORTYPE videoInputHw_IspAe_SetMetering(int *pvipp_id, int value);
ERRORTYPE videoInputHw_IspAe_SetGain(int *pvipp_id, int value);
ERRORTYPE videoInputHw_IspAwb_SetMode(int *pvipp_id, int value);
ERRORTYPE videoInputHw_IspAwb_SetColorTemp(int *pvipp_id, int value);
ERRORTYPE videoInputHw_Isp_SetFlicker(int *pvipp_id, int value);
ERRORTYPE videoInputHw_Isp_SetMirror(int *pvipp_id, int value);
ERRORTYPE videoInputHw_Isp_SetFlip(int *pvipp_id, int value);
ERRORTYPE videoInputHw_Isp_SetBrightness(int *pvipp_id, int value);
ERRORTYPE videoInputHw_Isp_SetContrast(int *pvipp_id, int value);
ERRORTYPE videoInputHw_Isp_SetSaturation(int *pvipp_id, int value);
ERRORTYPE videoInputHw_Isp_SetSharpness(int *pvipp_id, int value);
ERRORTYPE videoInputHw_Isp_SetHue(int *pvipp_id, int value);
ERRORTYPE videoInputHw_Isp_SetGainCfg(int *pvipp_id, struct gain_cfg *pstGainCfg);
ERRORTYPE videoInputHw_Isp_SetSensorFps(int *pvipp_id, int iVal);

ERRORTYPE videoInputHw_IspAe_GetMode(int *pvipp_id, int *pvalue);
ERRORTYPE videoInputHw_IspAe_GetExposureBias(int *pvipp_id, int *pvalue);
ERRORTYPE videoInputHw_IspAe_GetExposure(int *pvipp_id, int *pvalue);
ERRORTYPE videoInputHw_IspAe_GetExposureMs(int *pvipp_id, int *pvalue);
ERRORTYPE videoInputHw_IspAe_GetISOSensitiveMode(int *pvipp_id, int *mode);
ERRORTYPE videoInputHw_IspAe_GetISOSensitive(int *pvipp_id, int *value);
ERRORTYPE videoInputHw_IspAe_GetMetering(int *pvipp_id, int *pvalue);
ERRORTYPE videoInputHw_IspAe_GetGain(int *pvipp_id, int *pvalue);
ERRORTYPE videoInputHw_IspAwb_GetMode(int *pvipp_id, int *pvalue);
ERRORTYPE videoInputHw_IspAwb_GetColorTemp(int *pvipp_id, int *pvalue);
ERRORTYPE videoInputHw_Isp_GetFlicker(int *pvipp_id, int *pvalue);
ERRORTYPE videoInputHw_Isp_GetMirror(int *pvipp_id, int *pvalue);
ERRORTYPE videoInputHw_Isp_GetFlip(int *pvipp_id, int *pvalue);
ERRORTYPE videoInputHw_Isp_GetBrightness(int *pvipp_id, int *pvalue);
ERRORTYPE videoInputHw_Isp_GetContrast(int *pvipp_id, int *pvalue);
ERRORTYPE videoInputHw_Isp_GetSaturation(int *pvipp_id, int *pvalue);
ERRORTYPE videoInputHw_Isp_GetSharpness(int *pvipp_id, int *pvalue);
ERRORTYPE videoInputHw_Isp_GetHue(int *pvipp_id, int *pvalue);
ERRORTYPE videoInputHw_Isp_GetGainCfg(int *pvipp_id, struct gain_cfg *pstGainCfg);
ERRORTYPE videoInputHw_Isp_SetHighLT(int *pvipp_id, int value);/* value: [-32, 32]*/
ERRORTYPE videoInputHw_Isp_GetHighLT(int *pvipp_id, int *value);
ERRORTYPE videoInputHw_Isp_SetBackLT(int *pvipp_id, int value);/* value: [-32, 32]*/
ERRORTYPE videoInputHw_Isp_GetBackLT(int *pvipp_id, int *value);
ERRORTYPE videoInputHw_IspAwb_SetRGain(int *pvipp_id, int value);  /*value: [256, 256 * 64]*/
ERRORTYPE videoInputHw_IspAwb_GetRGain(int *pvipp_id, int *value);
ERRORTYPE videoInputHw_IspAwb_SetBGain(int *pvipp_id, int value);  /*value: [256, 256 * 64]*/
ERRORTYPE videoInputHw_IspAwb_GetBGain(int *pvipp_id, int *value);
ERRORTYPE videoInputHw_IspAwb_SetGrGain(int *pvipp_id, int value);  /*value: [256, 256 * 64]*/
ERRORTYPE videoInputHw_IspAwb_GetGrGain(int *pvipp_id, int *value);
ERRORTYPE videoInputHw_IspAwb_SetGbGain(int *pvipp_id, int value);  /*value: [256, 256 * 64]*/
ERRORTYPE videoInputHw_IspAwb_GetGbGain(int *pvipp_id, int *value);

ERRORTYPE videoInputHw_Isp_SetWDR(int *pvipp_id, int value);
ERRORTYPE videoInputHw_Isp_GetWDR(int *pvipp_id, int *value);
ERRORTYPE videoInputHw_Isp_SetNR(int *pvipp_id, int value);
ERRORTYPE videoInputHw_Isp_GetNR(int *pvipp_id, int *value);
ERRORTYPE videoInputHw_Isp_Set3DNR(int *pvipp_id, int value);
ERRORTYPE videoInputHw_Isp_Get3DNR(int *pvipp_id, int *value);
ERRORTYPE videoInputHw_Isp_GetIspDigGain(int *pvipp_id, int *value);

#endif
