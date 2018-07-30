/*! \file aw_ai_cve_base_type.h
\brief cve_base_type.h document.
*/

#ifndef __AW_AI_CVE_BASE_TYPE_H__
#define __AW_AI_CVE_BASE_TYPE_H__

#if !defined _CRT_SECURE_NO_DEPRECATE && _MSC_VER > 1300
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "aw_ai_common_type.h"

//! \defgroup group_core 基础设施
//!  基础设施数据类型与函数
//! \{
//! \}


#ifdef __cplusplus
extern "C"{
#endif


//----------------------------------------------
// EXPORTS and IMPORTS definition
//----------------------------------------------
#if (defined WIN32 || defined _WIN32 || defined WINCE) && defined AW_AI_CVE_API_EXPORTS
    #define AW_CVE_EXPORTS __declspec(dllexport)
#else
    #define AW_CVE_EXPORTS
#endif

//----------------------------------------------
// constant definition
//----------------------------------------------
#define AW_AI_CVE_MODULE_DATLEN	1024
//! \ingroup group_core
//! object definition
typedef struct
{
	AW_U8 auBuffer[AW_AI_CVE_MODULE_DATLEN];				//!< Buffer
} AW_AI_CVE_OBJ_S;

//! \ingroup group_core
//! error code definition
typedef enum
{
	AW_AI_CVE_ERR_NULL_PTR       = 0xA00A0001,            //!< null pointer
	AW_AI_CVE_ERR_ILLEGAL_PARAM  = 0xA00A0002,            //!< illegal param
	AW_AI_CVE_ERR_INVALID_ADDR   = 0xA00A0003,            //!< invalid address
	AW_AI_CVE_ERR_NOT_CONFIG     = 0xA00A0004,            //!< not config
	AW_AI_CVE_ERR_NO_LISENCE     = 0xA00A0005,            //!< no valid liceence
	AW_AI_CVE_ERR_INVALID_IMAGE  = 0xA00A0006,            //!< invalid image
} AW_AI_CVE_ERROR_CODE_E;

//! \ingroup group_core
//! pixel format of the Yuv image 
typedef enum
{
	AW_AI_CVE_YUV_PLANAR_422 = 0x01,                    //!<  YYY UUU VVV	
	AW_AI_CVE_YUV_SEMIPLANAR_422 = 0x02,                 //!<  [Y0 Y1 Y2] [U0V0 U1V1 V2V2] 
	AW_AI_CVE_YUV_SEMIPLANAR_420 = 0x03,				//!<  [Y0 Y1 /Y2 Y3] [U0V0 U1V1] 
	AW_AI_CVE_YUV_PLANAR_420 = 0x04					    //!<  [Y0 Y1 /Y2 Y3] [U0V0 U1V1] 
} AW_AI_CVE_YUV_FORMAT_E;

//! \ingroup group_core
//! quadrangle definition
typedef struct
{
	AW_POINT_S astPoints[4];   //!< quadrangle point array
} AW_AI_CVE_QUADRANGLE_S;

//! \ingroup group_core
//! BRG pixel definition
typedef struct
{
	AW_U8 u8B;                 //!< blue
	AW_U8 u8G;                 //!< green
	AW_U8 u8R;                 //!< red
} AW_AI_CVE_PIXEL_S;

//! \ingroup group_core
//! gray image definition
typedef struct
{
	AW_S32 s32Width;           //!< width of the image
	AW_S32 s32Height;          //!< height of the image
	AW_S32 s32Stride;		   //!< stride of the image
	AW_U8 *pu8Data;            //!< data buffer of the image
    AW_U32 u32PhyAddr;		   //!< data physical address of the image
} AW_AI_CVE_GRAY_IMAGE_S;

//! \ingroup group_core
//! yuv422p image definition
typedef struct
{
	AW_AI_CVE_YUV_FORMAT_E  enPixelFormat;     //!< pixel format of the image()
	AW_S32 s32Width;					 //!< width of the image
	AW_S32 s32Height;					 //!< height of the image
	AW_S32 s32Stride;					 //!< stride of the image
	AW_U8 *pu8YData;					 //!< Y data buffer of the image
	AW_U8 *pu8UData;					 //!< U data buffer of the image
	AW_U8 *pu8VData;				     //!< V data buffer of the image
	AW_U8 *pu8UVData;					 //!< UV data buffer of the image
	AW_U32 u32YDataPhyAddr;			 	 //!< Y data physical address of the image
} AW_AI_CVE_YUV422P_IMAGE_S;

//! \ingroup group_core
//! RBG image definition
typedef struct
{
	AW_S32 s32Width;           //!< width of the image
	AW_S32 s32Height;          //!< height of the image
	AW_U8 *pu8RData;           //!< red data buffer of the image
	AW_U8 *pu8GData;           //!< green data buffer of the image
	AW_U8 *pu8BData;           //!< blue data buffer of the image
} AW_AI_CVE_RBG_IMAGE_S;

//! 切面线段
typedef struct
{
	AW_LINE_S line;            //!< 线段位置(单位：像素)
} AW_AI_CVE_CUT_LINE_S;

//! 禁止范围
typedef struct
{
	AW_S32 forbidden;              //!< 禁止标志（0：允许；1：禁止）
	AW_S32 minimum;                //!< 最小值，取值-1表示不作约束
	AW_S32 maximum;                //!< 最大值，取值-1表示不作约束
} AW_AI_CVE_FORBIDDEN_INTERVAL_S;

//----------------------------------------------
// 事件定义
//----------------------------------------------

//! \ingroup group_core
//! 事件类型
typedef enum
{
	AW_AI_CVEEVT_TYPE_UNKNOWN             = 0000, //!< 未知类型

	AW_AI_CVEEVT_TYPE_PERIMETER           = 1000, //!< 周界入侵
	AW_AI_CVEEVT_TYPE_LOITER              = 1001,	//!< 徘徊
	AW_AI_CVEEVT_TYPE_ABNORMALVEL         = 1002,	//!< 非正常速度
	AW_AI_CVEEVT_TYPE_CONVERSE            = 1003,	//!< 逆行
	AW_AI_CVEEVT_TYPE_TRIPWIRE            = 1004,	//!< 绊线
	AW_AI_CVEEVT_TYPE_MTRIPWIRE           = 1005,	//!< 双绊线
	AW_AI_CVEEVT_TYPE_OBJLEFT             = 1006,	//!< 物品遗留
	AW_AI_CVEEVT_TYPE_OBJREMOVED          = 1007,	//!< 物品移走
	AW_AI_CVEEVT_TYPE_MLOITER             = 1008, //!< 多人徘徊
	AW_AI_CVEEVT_TYPE_NOPARKING           = 1009, //!< 非法停车
	AW_AI_CVEEVT_TYPE_SLIPUP              = 1010, //!< 倒地
	AW_AI_CVEEVT_TYPE_VEHICLE_CONVERSE    = 1101, //!< 车辆逆行
	AW_AI_CVEEVT_TYPE_VEHICLE_PARK        = 1102, //!< 车辆停车
	AW_AI_CVEEVT_TYPE_VEHICLE_OVERSPEED   = 1103, //!< 车辆超速
	AW_AI_CVEEVT_TYPE_VEHICLE_UNDERSPEED  = 1104, //!< 车辆低速
	AW_AI_CVEEVT_TYPE_HUMAN_ACROSS        = 1105, //!< 行人穿越
	AW_AI_CVEEVT_TYPE_OBJECT_LEFT         = 1106, //!< 物品遗撒
	AW_AI_CVEEVT_TYPE_VEHICLE_OCCUPATION  = 1107, //!< 占用应急车道

	AW_AI_CVEEVT_TYPE_TGTCOUNT            = 1201,	//!< 目标计数
	AW_AI_CVEEVT_TYPE_HUMANCOUNT          = 1202,	//!< 人员计数

	AW_AI_CVEEVT_TYPE_SIGNAL_BAD  		= 2001  //!< 视频信号异常

} AW_AI_CVE_EVT_TYPE_E;

//! \ingroup group_core
//! 视频信号异常类型
typedef enum
{
	AW_AI_CVEVE_TYPE_Unknown = 0,                 //!< 未知类型
	AW_AI_CVEVE_TYPE_CameraMoved = 1,             //!< 相机移动
	AW_AI_CVEVE_TYPE_CameraOccluded,              //!< 相机遮挡
	AW_AI_CVEVE_TYPE_TooDark,                     //!< 图像太暗
	AW_AI_CVEVE_TYPE_HighLight,                   //!< 图像太亮
	AW_AI_CVEVE_TYPE_ImageFuzzy,                  //!< 图像模糊/相机失焦
	AW_AI_CVEVE_TYPE_NUM
} AW_AI_AW_AI_CVEVE_TYPE_E;

//! \ingroup group_core
//! 算法处理结果
typedef struct
{
	AW_TARGET_SET_S stTargetSet;             //!< 目标结果数据
	AW_EVENT_SET_S  stEventSet;               //!< 事件结果数据
} AW_AI_CVE_ALGO_RESULT_S;

//! \ingroup group_core
//! 警报级别
typedef enum
{
	AW_AI_CVEALARM_LEVEL_ALARM      = 0,      //!< 报警
	AW_AI_CVEALARM_LEVEL_PREALARM   = 1       //!< 预警
} AW_AI_CVE_ALARM_LEVEL_E;

//! \brief 格式化版本字符串
//! \param nSeriNum     [in] 版本序列号
//! \param pVersion     [out] 版本字符串，字符串缓冲区长度至少是32
AW_CVE_EXPORTS void AW_AI_CVECORE_FormatVersion( AW_U32 nSeriNum, AW_CHAR *pVerion );


#ifdef __cplusplus
}
#endif


#endif // __AW_AI_CVE_TYPE_H__

