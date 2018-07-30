
/*! \file aw_ai_cve_vlpr_interface.h
\brief aw_ai_cve_vlpr_interface.h document.
*/

#ifndef _AW_AI_CVE_VLPR_INTERFACE_H_
#define _AW_AI_CVE_VLPR_INTERFACE_H_

#include "aw_ai_cve_base_type.h"
#include "aw_ai_cve_vlpr_config.h"

//! \defgroup group_vlpr 车牌识别
//!  车牌识别数据类型与函数
//! \{
//! \}


#ifdef __cplusplus
extern "C"
{
#endif

//! \ingroup group_vlpr
//! \{

//! \brief 创建算法引擎
//! \return			模块句柄
AW_CVE_EXPORTS AW_HANDLE   AW_AI_CVE_VLPR_Create();


//! \brief 删除算法引擎
//! \param Object	要删除的算法引擎
//! \return			操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E   AW_AI_CVE_VLPR_Release( AW_PVOID Object );


//! \brief 创建各个模块并初始化
//! \param hModule	模块句柄
//! \param Para		初始化参数指针，参考\ref AW_AI_CVE_VLPR_INIT_PARA_S
//! \return			操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E    AW_AI_CVE_VLPR_Init(AW_HANDLE hModule,  AW_AI_CVE_VLPR_INIT_PARA_S  *pstInitPara );


//! \brief 处理一幅YUV图像
//! \param Object	算法引擎
//! \param Input	彩色图像指针，参考\ref AW_IMAGE_S 
//! \param Para		识别参数指针，参考\ref AW_AI_CVE_VLPR_PROC_PARA_S 
//! \param Output	输出结果指针，参考\ref AW_AI_CVE_VLPR_RULT_S 
//! \return			操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E    AW_AI_CVE_VLPR_Process( AW_PVOID Object, AW_IMAGE_S *pstImage, AW_AI_CVE_VLPR_PROC_PARA_S *pstProcPara, AW_AI_CVE_VLPR_RULT_S *pstOutput );


//! \brief 获取识别算法MODEL版本号
//! \param Object	算法引擎
//! \param Version  输出版本号地址指针。要求指针所指数组长度大于50 BYTE
//! \return			操作状态，参考\ref ICE_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E  AW_AI_CVE_VLPR_GetVersion( AW_PVOID Object, AW_U8 *pu8Version );


//! \}
#ifdef __cplusplus
}
#endif

#endif // _AW_AI_CVE_VLPR_INTERFACE_H_


