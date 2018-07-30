#ifndef _AW_AI_EVE_KERNEL_INTERFACE_H
#define _AW_AI_EVE_KERNEL_INTERFACE_H

/*
	EVE api functions.
	Do not modify!

	Writen by limianhe<limianhe@allwinnertech.com>
*/

#include "aw_ai_eve_type.h"

//----------------------------------------------
// EXPORTS and IMPORTS definition
#ifdef WIN32 
#define AW_EXPORTS __declspec(dllexport)
#else
#define AW_EXPORTS 
#include <pthread.h>
#endif


//! \brief 配置EVE模块的数据源物地址
//! \pParam pEVECtrl [in] 数据源地址
//! \return             操作状态，参考\ref AW_STATUS_E
AW_EXPORTS  AW_STATUS_E  AW_AI_EVE_Kernel_SetSrcAddr(AW_U32 addrPtr);

//! \brief 配置EVE模块的DMA搬运与主程序的执行模式，0-异步，1-同步
//! \dmaMode pEVECtrl [in] DMA与主程序执行模式
//! \return             操作状态，参考\ref AW_STATUS_E
AW_EXPORTS  AW_STATUS_E  AW_AI_EVE_Kernel_SetDMAMode(AW_S32 dmaMode);

//! \brief 创建EVE模块并初始化、配置DMA参数
//! \pParam pEVECtrl [in] EVE配置参数
//! \return             操作状态，参考\ref AW_STATUS_E
AW_EXPORTS  AW_STATUS_E  AW_AI_EVE_Kernel_Init(AW_AI_EVE_CTRL_S* pEVECtrl);

//! \brief 终止EVE模块并释放内存
//! \return             操作状态，参考\ref AW_STATUS_E
AW_EXPORTS AW_STATUS_E  AW_AI_EVE_Kernel_UnInit();

//! \brief 启动任务检测
//! \param userFunc     [in] 回调函数，用于获取检测结果
//! \return             操作状态，参考\ref AW_STATUS_E
AW_EXPORTS AW_STATUS_E  AW_AI_EVE_Kernel_Detect(void(*userFunc)(AW_AI_EVE_RESULTS* r, AW_AI_EVE_MIDRESULTS* m, void* p ), void* pUsr);

AW_EXPORTS  AW_STATUS_E  AW_AI_EVE_Kernel_SetDMAParam(AW_AI_EVE_DMA_CTRL_S* pDmaCtrl);

#endif