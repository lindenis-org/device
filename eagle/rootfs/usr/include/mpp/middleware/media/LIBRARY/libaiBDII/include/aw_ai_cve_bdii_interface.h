
/*! \file aw_ai_cve_bdii_interface.h
\brief aw_ai_cve_bdii_interface.h document.
*/

#ifndef _AW_AI_CVE_BDII_INTERFACE_H_
#define _AW_AI_CVE_BDII_INTERFACE_H_

#include "aw_ai_cve_base_type.h"
#include "aw_ai_cve_bdii_config.h"

//! \defgroup group_bdii 双目深度信息
//!  车牌识别数据类型与函数
//! \{
//! \}


#ifdef __cplusplus
extern "C"
{
#endif

//! \ingroup group_bdii
//! \{

//! \brief 创建算法引擎
//! \return			模块句柄
AW_CVE_EXPORTS AW_HANDLE   AW_AI_CVE_BDII_Create();


//! \brief 删除算法引擎
//! \param Object	要删除的算法引擎
//! \return			操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E   AW_AI_CVE_BDII_Release( AW_PVOID Object );


//! \brief 创建各个模块并初始化
//! \param hModule	模块句柄
//! \param Para		初始化参数指针，参考\ref AW_AI_CVE_BDII_INIT_PARA_S
//! \return			操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E    AW_AI_CVE_BDII_Init(AW_HANDLE hModule,  AW_AI_CVE_BDII_INIT_PARA_S  *pstInitPara );


//! \brief 处理一幅YUV图像
//! \param Object		算法引擎
//! \param pstImageLft	左图图像指针，参考\ref AW_IMAGE_S 
//! \param pstImageRgt	右图图像指针，参考\ref AW_IMAGE_S 
//! \param Output		输出结果指针，参考\ref AW_AI_CVE_BDII_RULT_S 
//! \return				操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E    AW_AI_CVE_BDII_Process( AW_PVOID Object, AW_IMAGE_S *pstImageLft, AW_IMAGE_S *pstImageRgt, AW_AI_CVE_BDII_RULT_S *pstOutput );



//! \}
#ifdef __cplusplus
}
#endif

#endif // _AW_AI_CVE_BDII_INTERFACE_H_


