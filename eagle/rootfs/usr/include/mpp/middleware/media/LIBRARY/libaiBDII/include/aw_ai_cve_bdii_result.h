/*! \file aw_ai_cve_bdii_result.h
\brief aw_ai_cve_bdii_result.h document.
*/
#ifndef __AW_AI_CVE_BDII_RESULT_H__
#define __AW_AI_CVE_BDII_RESULT_H__

#include "aw_ai_cve_base_type.h"

#ifdef __cplusplus
extern "C"
{
#endif


//----------------------------------------------
// 双目深度信息处理结果定义
//----------------------------------------------

//! \ingroup group_bdii
//! 双目深度信息算法处理结果
typedef struct 
{
	AW_S16			*as16DeepImg;			//!< 深度信息图
	AW_S32			*as32CostImg;			//!< 代价图数据   
	AW_S32			as32Reserved[16];		//!< 预留字段
}AW_AI_CVE_BDII_RULT_S;


#ifdef __cplusplus
}
#endif


#endif
