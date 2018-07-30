/******************************************************************************
  Copyright (C), 2001-2016, Allwinner Tech. Co., Ltd.
 ******************************************************************************
  File Name     : videoInputBufferManager.h
  Version       : Initial Draft
  Author        : Allwinner BU3-PD2 Team
  Created       : 2016/06/28
  Last Modified :
  Description   : mpi functions implement
  Function List :
  History       :
******************************************************************************/
#ifndef __VIDEOINPUT_BUFFER_MANAGER_H__
#define __VIDEOINPUT_BUFFER_MANAGER_H__

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// #include <mm_comm_aio.h>

typedef struct VideoInputBufferManager {
    struct list_head mFreeFrmList;
    struct list_head mValidFrmList;
    struct list_head mUsingFrmList;
    pthread_mutex_t mFrmListLock;
    pthread_cond_t mCondUsingFrmEmpty;
    int mFrameNodeNum;
    int mbWaitUsingFrmEmptyFlag;

    VIDEO_FRAME_INFO_S *(*getValidFrame)(struct VideoInputBufferManager *pMgr);
    int (*releaseFrame)(struct VideoInputBufferManager *pMgr, VIDEO_FRAME_INFO_S *pFrame);
    int (*pushFrame)(struct VideoInputBufferManager *pMgr, VIDEO_FRAME_INFO_S *pFrame);
    int (*usingFrmEmpty)(struct VideoInputBufferManager *pMgr);
    int (*waitUsingFrmEmpty)(struct VideoInputBufferManager *pMgr);
} VideoInputBufferManager;

VideoInputBufferManager *videoInputBufMgrCreate(int frmNum, int frmSize);
void videoInputBufMgrDestroy(VideoInputBufferManager *pMgr);

#endif /* __PCM_BUFFER_MANAGER_H__ */
