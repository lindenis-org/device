/*! \file aw_ai_cve_hcnt_result.h
\brief aw_ai_cve_hcnt_result.h document.
*/

#ifndef __AW_AI_CVE_HCNT_RESULT_H__
#define __AW_AI_CVE_HCNT_RESULT_H__

#include "aw_ai_cve_base_type.h"


#ifdef __cplusplus
extern "C"
{
#endif


//----------------------------------------------
// 处理结果定义
//----------------------------------------------

//! \ingroup group_hcnt
//! 算法处理结果
typedef AW_AI_CVE_ALGO_RESULT_S AW_AI_CVE_HCNT_RESULT_S;

//! \ingroup group_hcnt
//! 人员计数事件数据（存储区为AW_AI_CVE_EVENT的u8Data变量）
typedef struct
{
	AW_LINE_S line;                //!< 线段位置
	AW_S16 angle;					//!< 方向角度
	AW_S16	tgtnum;					//!< 目标数目
} AW_AI_CVE_HCNTEVT_DATA_HUMANCOUNT;


#ifdef __cplusplus
}
#endif


#endif  // __AW_AI_CVE_HCNT_RESULT_H__
