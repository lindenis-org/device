/******************************************************************************
  Copyright (C), 2001-2016, Allwinner Tech. Co., Ltd.
 ******************************************************************************
  File Name     : VideoVI_Component.h
  Version       : Initial Draft
  Author        : Allwinner BU3-PD2 Team
  Created       : 2016/05/09
  Last Modified :
  Description   : mpp component implement
  Function List :
  History       :
******************************************************************************/

#ifndef __IPCLINUX_VIDEOVI_COMPONENT_H__
#define __IPCLINUX_VIDEOVI_COMPONENT_H__

//ref platform headers
#include "plat_defines.h"
#include "plat_errno.h"
#include "plat_math.h"
#include "plat_type.h"

//media api headers to app
#include "mm_comm_vi.h"
#include "mm_comm_video.h"
#include "mm_common.h"

//media internal common headers.
#include "ComponentCommon.h"
#include "media_common.h"
#include "mm_component.h"
#include "tmessage.h"
#include "tsemaphore.h"
#include "vencoder.h"

#include <VideoVirViCompPortIndex.h>
#include "../videoIn/videoInputHw.h"
#include "../videoIn/videoInputBufferManager.h"

// ===========================================================================
#define MAX_VI_PORTS (2)
#define VI_FIFO_LEVEL 10

typedef struct VideoFrameInfo {
    VIDEO_FRAME_INFO_S VFrame;
    struct list_head mList;
} VideoFrameInfo;

typedef struct bufQ {
    struct list_head mIdleFrameList;  //VideoFrameInfoNode
    struct list_head mReadyFrameList;
    int buf_unused;  //ENC_FIFO_LEVEL
} bufQ;

#define VI_MAXPATHSIZE (1024)
typedef struct {
    COMP_STATETYPE state;
    pthread_mutex_t mStateLock;
    COMP_CALLBACKTYPE* pCallbacks;
    void* pAppData;
    COMP_HANDLETYPE hSelf;
	
    COMP_PORT_PARAM_TYPE sPortParam;
    COMP_PARAM_PORTDEFINITIONTYPE sPortDef[VI_CHN_MAX_PORTS];
    COMP_INTERNAL_TUNNELINFOTYPE sPortTunnelInfo[VI_CHN_MAX_PORTS];
    COMP_PARAM_BUFFERSUPPLIERTYPE sPortBufSupplier[VI_CHN_MAX_PORTS];
    BOOL mInputPortTunnelFlag;
    BOOL mOutputPortTunnelFlag;  //TRUE: tunnel mode; FALSE: non-tunnel mode.

    MPP_CHN_S mMppChnInfo;
    pthread_t thread_id;
    // CompInternalMsgType eTCmd;
    message_queue_t cmd_queue;

    pthread_mutex_t mutex_fifo_ops_lock;
    bufQ mBufQ;  //used for managing camera frame, for uncompressed video frame.

	volatile int mWaitingCapDataFlag;
	cdx_sem_t mAllFrameRelSem;
    volatile int mWaitAllFrameReleaseFlag;
	
    VideoInputBufferManager* mpCapMgr;
    cdx_sem_t mSemWaitInputFrame;
    int mInputBufsNum;
    int mBufsCacheMax;
    int mBufsCacheCnt;

    BOOL mbStoreFrame;
    int mStoreFrameCount;
    char mDbgStoreFrameFilePath[VI_MAXPATHSIZE];
    // struct list_head mIdleOutFrameList;   //
    // struct list_head mReadyOutFrameList;  //
    // struct list_head mUsedOutFrameList;   //
    // int mFrameNodeNum;
    // BOOL mWaitOutFrameFullFlag;
    // BOOL mWaitOutFrameFlag;  //for non-tunnel mode, wait outFrame coming!
    // pthread_mutex_t mOutFrameListMutex;
    // pthread_cond_t mOutFrameFullCondition;
    // pthread_cond_t mOutFrameCondition;  //for non-tunnel mode, wait outFrame coming!
} VIDEOVIDATATYPE;

//private interface
ERRORTYPE VideoViGetPortDefinition(PARAM_IN COMP_HANDLETYPE hComponent,
                                   PARAM_INOUT COMP_PARAM_PORTDEFINITIONTYPE* pPortDef);
ERRORTYPE VideoViSetPortDefinition(PARAM_IN COMP_HANDLETYPE hComponent,
                                   PARAM_IN COMP_PARAM_PORTDEFINITIONTYPE* pPortDef);
ERRORTYPE VideoViGetCompBufferSupplier(PARAM_IN COMP_HANDLETYPE hComponent,
                                       PARAM_INOUT COMP_PARAM_BUFFERSUPPLIERTYPE* pPortBufSupplier);
ERRORTYPE VideoViSetCompBufferSupplier(PARAM_IN COMP_HANDLETYPE hComponent,
                                       PARAM_IN COMP_PARAM_BUFFERSUPPLIERTYPE* pPortBufSupplier);
ERRORTYPE VideoViGetMPPChannelInfo(PARAM_IN COMP_HANDLETYPE hComponent, PARAM_OUT MPP_CHN_S* pChn);
ERRORTYPE VideoViSetMPPChannelInfo(PARAM_IN COMP_HANDLETYPE hComponent, PARAM_IN MPP_CHN_S* pChn);
//public interface
ERRORTYPE VideoViSendCommand(PARAM_IN COMP_HANDLETYPE hComponent, PARAM_IN COMP_COMMANDTYPE Cmd,
                             PARAM_IN unsigned int nParam1, PARAM_IN void* pCmdData);
ERRORTYPE VideoViGetState(PARAM_IN COMP_HANDLETYPE hComponent, PARAM_OUT COMP_STATETYPE* pState);
ERRORTYPE VideoViSetCallbacks(PARAM_IN COMP_HANDLETYPE hComponent, PARAM_IN COMP_CALLBACKTYPE* pCallbacks,
                              PARAM_IN void* pAppData);
ERRORTYPE VideoViGetConfig(PARAM_IN COMP_HANDLETYPE hComponent, PARAM_IN COMP_INDEXTYPE nIndex,
                           PARAM_IN void* pComponentConfigStructure);
ERRORTYPE VideoViSetConfig(PARAM_IN COMP_HANDLETYPE hComponent, PARAM_IN COMP_INDEXTYPE nIndex,
                           PARAM_IN void* pComponentConfigStructure);
ERRORTYPE VideoViComponentTunnelRequest(PARAM_IN COMP_HANDLETYPE hComponent, PARAM_IN unsigned int nPort,
                                        PARAM_IN COMP_HANDLETYPE hTunneledComp, PARAM_IN unsigned int nTunneledPort,
                                        PARAM_INOUT COMP_TUNNELSETUPTYPE* pTunnelSetup);
ERRORTYPE VideoViEmptyThisBuffer(PARAM_IN COMP_HANDLETYPE hComponent, PARAM_IN COMP_BUFFERHEADERTYPE* pBuffer);
ERRORTYPE VideoViFillThisBuffer(PARAM_IN COMP_HANDLETYPE hComponent, PARAM_IN COMP_BUFFERHEADERTYPE* pBuffer);

ERRORTYPE VideoViComponentDeInit(PARAM_IN COMP_HANDLETYPE hComponent);
ERRORTYPE VideoViComponentInit(PARAM_IN COMP_HANDLETYPE hComponent);

#endif /* __IPCLINUX_VIDEOVI_COMPONENT_H__ */
