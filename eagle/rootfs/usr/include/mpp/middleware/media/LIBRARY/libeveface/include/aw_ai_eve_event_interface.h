#ifndef _AW_AI_EVE_EVENT_INTERFACE_H
#define _AW_AI_EVE_EVNET_INTERFACE_H

#include "aw_ai_eve_type.h"

//----------------------------------------------
// EXPORTS and IMPORTS definition
//----------------------------------------------
#if (defined WIN32 || defined _WIN32 || defined WINCE) && defined CVE_API_EXPORTS
    #define AW_EXPORTS __declspec(dllexport)
#else
    #define AW_EXPORTS
#endif

//event type
typedef enum
{
	AW_AI_EVE_EVENT_FACEDETECT = 3001,  //face detect
	AW_AI_EVE_EVENT_HEADDETECT = 3002,  //reserved
}AW_AI_EVE_EVENT_TYPE_E;

//face detect parameter
typedef struct _AW_AI_EVE_EVENT_FACEDET_PARAM_S
{
	AW_ROI_SET_S sRoiSet;          //facedetect roi, support maximize 8 rois
	AW_S32     s32OverLapCoeff;    //overlap coeff, [1, 100]%, default: [20]%
	AW_S32     s32MinFaceSize;     //minimize face  size,[20]pixel
	AW_S32     s32MergeThreshold;  //merger threshold, [2, 5], default: 3  
	AW_S32     s32MaxFaceNum;      //maximize face num, [1, 128], default: 128
	AW_S32     s32ClassifyFlag;    //the second Classify flag, 0-off, 1-on, reseverd, default: 0
	//AW_S32     s32MinSnapFaceSize; //the minimize snap face size, default: 20
	//AW_S32     s32MaxSnapFaceSize; //the maximum  snap face size, default: 120
	AW_S8     *s8Cfgfile;          //face classifier cfg file, reserved, default[NULL]
	AW_S8     *s8Weightfile;       //face classifier weight file，reserved, default[NULL]
}AW_AI_EVE_EVENT_FACEDET_PARAM_S, *lpAW_AI_EVE_EVENT_FACEDET_PARAM_S;

//eve result
typedef struct _AW_AI_EVE_EVENT_RESULT_S
{
	AW_EVETARGET_SET_S  sTarget; 
	AW_EVENT_SET_S      sEvent;
}AW_AI_EVE_EVENT_RESULT_S, *lpAW_AI_EVE_EVENT_RESULT_S;

//interface
#ifdef __cplusplus
extern "C"{
#endif

//! \ingroup group_eve_application
//! \{
//! \brief 查询EVE算法版本
//! \param pVersion     [out] 版本字符串，字符串缓冲区长度至少是32
//! \return             操作状态，参考\ref AW_STATUS_E
AW_EXPORTS  AW_STATUS_E AW_AI_EVE_Event_GetAlgoVersion( AW_S8 *pVersion );

//! \brief 创建算法模块并初始化。
//! \pParam pEVECtrl [in] EVE配置参数，参考\ref AW_AI_EVE_CTRL_S
//! \return             模块句柄
AW_EXPORTS  AW_HANDLE   AW_AI_EVE_Event_Init(AW_AI_EVE_CTRL_S *pEVECtrl);

//! \brief 终止算法模块并释放内存
//! \param hHandle      [in] 模块句柄
//! \return             操作状态，参考\ref AW_STATUS_E
AW_EXPORTS AW_STATUS_E  AW_AI_EVE_Event_UnInit( AW_HANDLE hHandle);

//! \brief 处理一帧图像，并获取处理结果，适合视频处理
//! \param hHandle      [in] 模块句柄
//! \param pstImage     [in] 待处理的输入图像，参考\ref AW_IMAGE_S
//! \param u32TimeStamp [in] 输入图像的时间戳，以图像帧为单位
//! \param pstResult    [out] 处理结果，参考\ref AW_AI_EVE_EVENT_RESULT_S
//! \return             操作状态，参考\ref AW_STATUS_E
AW_EXPORTS AW_STATUS_E  AW_AI_EVE_Event_Process( AW_HANDLE hHandle, AW_IMAGE_S *pstImage, AW_S64 u32TimeStamp, AW_AI_EVE_EVENT_RESULT_S *pstResult );

//! \brief 处理一幅图像，并获取处理结果，适合单张图片处理
//! \param hHandle      [in] 模块句柄
//! \param pstImage     [in] 待处理的输入图像，参考\ref AW_IMAGE_S
//! \param pstResult    [out] 处理结果，参考\ref AW_AI_EVE_EVENT_RESULT_S
//! \return             操作状态，参考\ref AW_STATUS_E
AW_EXPORTS AW_STATUS_E  AW_AI_EVE_Event_ProcessImage( AW_HANDLE hHandle, AW_IMAGE_S *pstImage, AW_AI_EVE_EVENT_RESULT_S *pstResult );


//! \brief 设置事件参数结构体
//! \param hHandle      [in] 模块句柄
//! \param eventType    [in] 事件类型，参考\ref AW_AI_EVE_EVENT_TYPE_E
//! \param pEventParam  [in] 事件结构体配置，参考\ref 不同的事件结构体参数
//! \return             操作状态，参考\ref AW_STATUS_E
AW_EXPORTS AW_STATUS_E  AW_AI_EVE_Event_SetEventParam( AW_HANDLE hHandle, AW_AI_EVE_EVENT_TYPE_E eventType, AW_PVOID pEventParam);

//! \brief 设置EVE参数
//! \param hHandle      [in] 模块句柄
//! \param pEveParam    [in] 设置EVE参数，参考\ref AW_AI_EVE_PARAMETER_S
//! \return             操作状态，参考\ref AW_STATUS_E
//AW_EXPORTS AW_STATUS_E  AW_AI_EVE_Event_SetEveParam( AW_HANDLE hHandle, AW_AI_EVE_KERNEL_CTRL_S *pEveParam);

//! \brief 设置EVE数据源地址
//! \param hHandle      [in] 模块句柄
//! \param pSourceAddr  [in] pSourceAddr,数据源地址
//! \return             操作状态，参考\ref AW_STATUS_E
AW_EXPORTS AW_STATUS_E  AW_AI_EVE_Event_SetEveSourceAddress( AW_HANDLE hHandle, void *pSourceAddr);

//! \brief 设置EVE内核DMA搬运与EVE算子的执行顺序
//! \param hHandle      [in] 模块句柄
//! \param dmaMode      [in] DMA与EVE算子执行顺序，0-异步，1-同步
//! \return             操作状态，参考\ref AW_STATUS_E
AW_EXPORTS AW_STATUS_E  AW_AI_EVE_Event_SetEveDMAExecuteMode( AW_HANDLE hHandle, AW_S32 dmaMode);

AW_EXPORTS  AW_STATUS_E  AW_AI_EVE_Event_SetDMAParam(AW_HANDLE hHandle, AW_AI_EVE_DMA_CTRL_S* pDmaCtrl);


//! \brief 获取最后的错误码结果
//! \param hHandle      [in] 模块句柄
//! \return             算法错误码，参考\ref AW_S32
AW_EXPORTS AW_S32  AW_AI_EVE_Event_GetLastError( AW_HANDLE hHandle );

#ifdef __cplusplus
}
#endif


#endif // _AW_AI_EVE_INTERFACE_H
