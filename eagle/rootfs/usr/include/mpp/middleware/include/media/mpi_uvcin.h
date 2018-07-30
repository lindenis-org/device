/******************************************************************************
  Copyright (C), 2001-2016, Allwinner Tech. Co., Ltd.
 ******************************************************************************
  File Name     : mpi_uvcin.h
  Version       : Initial Draft
  Author        : Allwinner BU3-PD2 Team
  Created       : 2016/10/15
  Last Modified :
  Description   : mpi functions declaration for uvc input component
  Function List :
  History       :
******************************************************************************/

#ifndef __UVC_COMPONENT_MPI_UVCIN_H__
#define __UVC_COMPONENT_MPI_UVCIN_H__

//ref platform headers
#include "plat_type.h"
#include "plat_errno.h"
#include "plat_defines.h"
#include "plat_math.h"

//media api headers to app
#include "mm_common.h"
#include "mm_comm_uvc.h"
#include "mm_comm_video.h"
//media internal common headers.
#include "vdecoder.h"

#ifdef __cplusplus
extern "C" {
#endif
ERRORTYPE AW_MPI_UVC_CreateChn(UVC_CHN UvcChn, const UVC_CHN_ATTR_S *pAttr);
ERRORTYPE AW_MPI_UVC_StartRecvPic(UVC_CHN UvcChn);
ERRORTYPE AW_MPI_UVC_StopRecvPic(UVC_CHN UvcChn);
ERRORTYPE AW_MPI_UVC_RegisterCallback(UVC_CHN UvcChn, MPPCallbackInfo *pCallback);
/*-1:bolck  0:nonblock   >0:overtime*/
ERRORTYPE AW_MPI_UVC_GetFrame(UVC_CHN UvcChn,int streamIdx,VIDEO_FRAME_INFO_S *pstFrameInfo,int nMilliSec);
ERRORTYPE AW_MPI_UVC_ReleaseFrame(UVC_CHN UvcChn,int streamIdx,VIDEO_FRAME_INFO_S *pstFrameInfo);
ERRORTYPE AW_MPI_UVC_DestroyChn(UVC_CHN UvcChn);
#ifdef __cplusplus
}
#endif
#endif /* __UVC_COMPONENT_MPI_UVCIN_H__ */
