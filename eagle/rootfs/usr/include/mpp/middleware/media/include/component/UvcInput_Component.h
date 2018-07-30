/******************************************************************************
  Copyright (C), 2001-2016, Allwinner Tech. Co., Ltd.
 ******************************************************************************
  File Name     : UvcInput_Component.h
  Version       : Initial Draft
  Author        : Allwinner BU3-PD2 Team
  Created       : 2016/10/15
  Last Modified :
  Description   : mpp component implement
  Function List :
  History       :
******************************************************************************/
#ifndef __UVCINPUT_COMPONENT_H__
#define __UVCINPUT_COMPONENT_H__

//ref platform headers
#include "plat_type.h"
#include "plat_errno.h"
#include "plat_defines.h"
#include "plat_math.h"
#include <linux/videodev2.h>

//media api headers to app
#include "mm_common.h"
#include "mm_comm_uvc.h"
#include "mpi_uvcin.h"

//media internal common headers.
//#include "media_common.h"
#include "mm_component.h"
//#include "ComponentCommon.h"
#include "tmessage.h"
//#include "tsemaphore.h"
//#include "vdecoder.h"

//#define IMAGE_SIZE (IMAGE_WIDTH * IMAGE_HEIGHT)
#define BUFFER_COUNT 4
#define UVC_FIFO_LEVEL 80

#define MAX_UVCODER_PORTS (2)
#define ALIGN_4K(x) (((x) + (4095)) & ~(4095))
#define ALIGN_1K(x) (((x) + (1023)) & ~(1023))
#define ALIGN_32B(x) (((x) + (31)) & ~(31))
#define ALIGN_16B(x) (((x) + (15)) & ~(15))
#define ALIGN_8B(x) (((x) + (7)) & ~(7))

#define NUM_OF_PICTURES_KEEP_IN_LIST 3
#define NUM_OF_PICTURES_KEEPPED_BY_DEINTERLACE 2
#define NUM_OF_PICTURES_KEEPPED_BY_ROTATE 0
#define NUM_OF_PICTURES_FOR_EXTRA_SMOOTH 3/* no data in buffer */
#define ERR_UVCInput_BUF_EMPTY  -1

/*
typedef struct V4L2BUF_t
{
    char *addrPhyY;		// physical Y address of this frame
    char *addrVirY;		// virtual Y address of this frame
    char *addrPhyC;
    char *addrVirC;
    unsigned int width;
    unsigned int height;
    int index;			// DQUE id number
    long long timeStamp;		// time stamp of this frame, unit:us
    int format; //V4L2_PIX_FMT_NV12
    int mColorSpace;	//enum v4l2_colorspace, V4L2_COLORSPACE_JPEG
    void *overlay_info;
    int refCnt; 		// used for releasing this frame
    unsigned int bytesused;      // used by compressed source
    unsigned int isDecodeSrc;
    int frameNum;
    int frameOffset;
    int fps;

}V4L2BUF_t;
*/

/*typedef struct UVCVideo_FRAME_BUF_INFO_S
{
    int   u32PoolId;
    unsigned int  u32Width;
    unsigned int  u32Height;
    int     ePixelFormat;
    char*   pData0;
    char*   pData1;
    size_addr phyYBufAddr;
    size_addr phyCBufAddr;
    int     nFrameRate;
} UVCVideo_FRAME_BUF_INFO_S;*/

typedef struct camera_info
{
    unsigned char *buf;
    unsigned int Image_Size;
    int64_t frameTimestamp;
    struct list_head app_info_node;
}camera_info;

typedef struct jpeg_info
{
    int jpeg_data_length;
    char *jpeg;
    int64_t frameTimestamp;
}jpeg_info;

/*typedef struct UvcCompOutputBuffer
{
  //  VideoPicture *pvbuf;
    //V4L2BUF_t *v4l2_buf;
    VideoPicture *pvbuf;
    struct list_head app_info_node;

}UvcCompOutputBuffer;*/

/*typedef struct LibInit_Info
{
    int capfmt;
    int outfmt;
    int w;
    int h;
    int *subw;
    int *subh;
    int fps;
    int *scl;
}LibInit_Info;*/

/*typedef struct LibDecoder_Info
{
    void *data_in;
    int data_size;
    int64_t pts;
}LibDecoder_Info;*/

typedef struct UVC_InputBuffer
{
    struct list_head IdleFrameList;    //VideoFrameInfoNode
    struct list_head ReadyFrameList;
    int buf_unused; //ENC_FIFO_LEVEL
}UVC_InputBuffer;

typedef struct UVC_OutputBuffer
{
    struct list_head IdleFrameList;    //VideoFrameInfoNode
    struct list_head ReadyFrameList;
    struct list_head UsedFrameList;
    int buf_unused; //ENC_FIFO_LEVEL
}UVC_OutputBuffer;

typedef struct DecodeHandle{
	//ve_mutex_t	mDecoderMutex ;
	VideoDecoder* mDecoder; //cedarv_decoder_t
	VideoStreamInfo mStream_info;  //cedarv_stream_info_t
	VConfig mDecoderConfig;
	VideoStreamDataInfo mData_info; //cedarv_stream_data_info_t
}DecodeHandle;

typedef struct UVCDATATYPE
{
    UVC_CHN_ATTR_S *UvcChnInfo;
    //UVC_CHN_ATTR_S *pComponentConfigStructure;
    COMP_CALLBACKTYPE *pCallbacks;
    void* pAppData;
    COMP_HANDLETYPE hSelf;
    unsigned int Qbuffer_Length;
    MPP_CHN_S mMppChnInfo;
    cdx_sem_t SemCompCmd;
    pthread_mutex_t mutex_fifo_ops_lock;
    pthread_cond_t InputFrameFullCondition;
    pthread_mutex_t InputFrameListMutex;
    UVC_InputBuffer Input_Buffer;
    pthread_mutex_t mutex_output_lock;
    pthread_cond_t OutputFrameFullCondition;
    BOOL mWaitOutFrameFlag;
    BOOL mWaitOutFrameFullFlag;
    UVC_OutputBuffer Output_OriginalImageBuffer; 
    UVC_OutputBuffer Output_ScaleImageBuffer; 
    int mOriginalImageFrameNodeNum;
    int mScaleImageFrameNodeNum;
    camera_info *pImageFrame; 
    jpeg_info *jpegFrame;
    DecodeHandle *Jpeg_DecoderHandle;
    VideoPicture *TunnelDecoderBuffer;
    pthread_mutex_t TunnelFrameListMutex;
    struct list_head mVideoInputFrameList;      //VEncCompOutputBuffer
    struct list_head mVideoInputFrameUsedList;
    unsigned int UVC_Image_Size;
    UvcMsgType Get_Thread_Flag;
    UvcMsgType Process_Thread_Flag;
    struct ScMemOpsS *mMemOps;
    unsigned int fps;
    BOOL is_open_uvc; 
    BOOL is_init_encoder; 
    COMP_STATETYPE state;
    message_queue_t  process_thread_cmd_queue;
    message_queue_t  get_thread_cmd_queue;
    COMP_STATETYPE process_thread_state;
    COMP_STATETYPE get_thread_state;
    COMP_PORT_PARAM_TYPE sPortParam;
    //COMP_PARAM_PORTDEFINITIONTYPE sInPortDef;
    COMP_PARAM_PORTDEFINITIONTYPE sOutPortDef;
    //COMP_INTERNAL_TUNNELINFOTYPE sInPortTunnelInfo;
    COMP_INTERNAL_TUNNELINFOTYPE sOutPortTunnelInfo;   
    COMP_PARAM_BUFFERSUPPLIERTYPE sPortBufSupplier[MAX_UVCODER_PORTS];
    //BOOL mInputPortTunnelFlag;
    BOOL mOutputPortTunnelFlag;   //TRUE: tunnel mode; FALSE: non-tunnel mode.
    BOOL UVCExitFlag;
    BOOL UsedScale;
   // BOOL StartGetUVCImage;
    pthread_t id_1;
    pthread_t id_2;
}UVCDATATYPE;

typedef struct PREVIEWINFO_t
{
    int left;
    int top;
    int width;			// preview width
    int height;			// preview height
}PREVIEWINFO_t, RECT_t;

typedef struct fmt_type
{
    unsigned int type;
    char *name;
} fmt_type;

ERRORTYPE UVCInputComponentInit(void *hComponent);
ERRORTYPE UVCInputComponentDeInit(void *hComponent);
ERRORTYPE UVCInputComponentStartRecvPic(void *hComponent);
ERRORTYPE UVCInputComponentStopRecvPic(void *hComponent);
ERRORTYPE UVCInputComponentGetStream(void *hComponent,int streamIdx,VIDEO_FRAME_INFO_S *pstFrameInfo,int nMilliSec);
ERRORTYPE UVCInputComponentReleaseStream(void *hComponent,int streamIdx,VIDEO_FRAME_INFO_S *pstFrameInfo);

#endif /*__UVCINPUT_COMPONENT_H__*/

