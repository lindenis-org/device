/*! \file aw_ai_cve_dtca_result.h
\brief aw_ai_cve_dtca_result.h document.
*/

#ifndef __AW_AI_CVE_DTCA_RESULT_H__
#define __AW_AI_CVE_DTCA_RESULT_H__

#include "aw_ai_cve_base_type.h"


#ifdef __cplusplus
extern "C"
{
#endif


//----------------------------------------------
// 处理结果定义
//----------------------------------------------

//! \ingroup group_dtca
//! 算法处理结果
typedef AW_AI_CVE_ALGO_RESULT_S AW_AI_CVE_DTCA_RESULT_S;

//! \ingroup group_dtca
//! 视频异常事件私有数据
typedef struct
{
	AW_S32 type;                           //!< 异常类型
	AW_S32 conf;                           //!< 可信度量
} AW_AI_CVE_DTCA_EVTDAT_VEXCEPT_S;

//! \ingroup group_dtca
//! 事件私有数据
typedef union
{
	AW_AI_CVE_DTCA_EVTDAT_VEXCEPT_S vexcept;        //!< 视频异常
} AW_AI_CVE_DTCA_EVTDAT_S;


#ifdef __cplusplus
}
#endif


#endif  // __AW_AI_CVE_DTCA_RESULT_H__
