/*! \file aw_ai_cve_vlpr_config.h
\brief aw_ai_cve_vlpr_config.h document.
*/
#ifndef __AW_AI_CVE_VLPR_CONFIG_H__
#define __AW_AI_CVE_VLPR_CONFIG_H__

#include "aw_ai_cve_base_type.h"
#include "aw_ai_cve_vlpr_result.h"

#ifdef __cplusplus
extern "C"
{
#endif


//----------------------------------------------
//  车牌识别参数定义             	
//----------------------------------------------
//! \ingroup group_vlpr
//! 模式1采用多边形画车牌方式标定； 模式2采用设置俯仰角和水平角度方式标定；
typedef struct
{
	AW_S32				s32CalibMode;							//!< 0不启用，1第一种，2第二种。
	AW_POLYGON_S		stPlateCalibPolygon;					//!< 位置标定；
	AW_S32				s32AlgleVer;							//!< 相机竖直角度-俯仰角，单位：度；
	AW_S32				s32AlgleLvl;							//!< 水平旋转角度-水平角，单位：度；
}AW_AI_CVE_VLPR_CALIB_S;

//! \ingroup group_vlpr
//! 车牌识别算法初始参数
typedef struct 
{
	AW_AI_CVE_VLPR_CHARTYPE_E	astCharType[AW_AI_CVE_VLPR_PLATE_CHAR_NUM];	//!< 车牌字符类型
	AW_S32				s32MaxPlateNum;							//!< 最大车牌数
	AW_S32				s32PlateTypeSp;							//!< 支持车牌类型     0默认全部开启；
	AW_S32				s32CarColorOn;							//!< 车身颜色额启用； 0不启用
	AW_S32				s32PlateConfidThrld;					//!< 车牌置信度阈值
	AW_AI_CVE_VLPR_CALIB_S	stCamCalibPara;						//!< 相机标定参数；
	AW_S8				*ps8ModelPath;							//!< 模型文件路径
	AW_S8				astReserve[28];							//!< 预留参数
}AW_AI_CVE_VLPR_INIT_PARA_S;


//! \ingroup group_vlpr
//! 车牌识别算法处理参数
typedef struct 
{
	AW_S32				s32MinPlateWidth;			//!< 最小车牌宽度    
	AW_S32				s32MaxPlateWidth;			//!< 最大车牌宽度  	
	AW_RECT_S			stRecRect;					//!< 识别区域  
	AW_AI_CVE_VLPR_CALIB_S	stPlateCalibPara;		//!< 相机(车牌)参数标定，0表示不启用。
	AW_S8				astReserve[32];				//!< 预留参数
}AW_AI_CVE_VLPR_PROC_PARA_S;								

//! \ingroup group_vlpr
//! 车牌识别算法汉字识别配置参数
#define AW_AI_CVE_VLPR_HANZICONFIG_NUM		6							//!< 单次配置汉字类型的最大数目

typedef struct 
{
	AW_AI_CVE_VLPR_CHARTYPE_E	astHANZIType[AW_AI_CVE_VLPR_HANZICONFIG_NUM];		//!< 配置的汉字类型
	AW_S16				as16HANZIWeight[AW_AI_CVE_VLPR_HANZICONFIG_NUM];	//!< 配置的汉字权重，范围-10~20.负数表示权重降低；默认5
	AW_S16				s16HANZIConfigNum;							//!< 本次配置的数目；
	AW_S8				astReserve[32];								//!< 预留参数
}AW_AI_CVE_VLPR_HANZICONFIG_S;	

#ifdef __cplusplus
}
#endif


#endif // __AW_AI_CVE_VLPR_CONFIG_H__

