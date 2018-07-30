/*! \file aw_ai_cve_bdii_config.h
\brief aw_ai_cve_bdii_config.h document.
*/
#ifndef __AW_AI_CVE_BDII_CONFIG_H__
#define __AW_AI_CVE_BDII_CONFIG_H__

#include "aw_ai_cve_base_type.h"
#include "aw_ai_cve_bdii_result.h"

#ifdef __cplusplus
extern "C"
{
#endif


//----------------------------------------------
//  双目深度信息图参数定义             	
//----------------------------------------------

//! \ingroup group_bdii
//! 双目深度信息算法初始参数
typedef struct 
{
	AW_U8 u8ftzero;							//!< 映射范围[16-128，默认31] 
	AW_U8 u8maxDisparity;					//!< 视差最大值[16~128，默认64]	
	AW_U8 u8SADWindowSize;					//!< 统计窗口尺寸[5~21，默认7]，要求奇数值	
	AW_U8 u8textureThreshold;				//!< 纹理阈值参数[1~128，默认10]
	AW_U8 u8uniquenessRatio;				//!< 视差唯一性比例[1~50，默认15]
	AW_U8 u8disp12MaxDiff;					//!< 验证可容许最大偏移[1~10，默认1]
	AW_U8 u8Reserved[64];					//!< 保留字段
}AW_AI_CVE_BDII_INIT_PARA_S;

#ifdef __cplusplus
}
#endif


#endif // __AW_AI_CVE_BDII_CONFIG_H__

