/*! \file aw_ai_cve_vlpr_result.h
\brief aw_ai_cve_vlpr_result.h document.
*/
#ifndef __AW_AI_CVE_VLPR_RESULT_H__
#define __AW_AI_CVE_VLPR_RESULT_H__

#include "aw_ai_cve_base_type.h"

#ifdef __cplusplus
extern "C"
{
#endif



//-------------------------------------------
// 字符类型定义              		 
//-------------------------------------------

//! 字符类型定义
typedef enum 
{
	AW_AI_CVE_CHARTYPE_CHARACTER		= 0,	//!< 数字及字母
	AW_AI_CVE_CHARTYPE_ONLYDIGITAL		= 1,	//!< 数字
	AW_AI_CVE_CHARTYPE_ONLYALPHABET		= 2,	//!< 字母 

	AW_AI_CVE_HANZI_CHINA				= 3,	//!< 全国
	AW_AI_CVE_HANZI_BEIJING				= 4,	//!< 北京
	AW_AI_CVE_HANZI_SHANGHAI			= 5,	//!< 上海
	AW_AI_CVE_HANZI_TIANJIN				= 6,	//!< 天津
	AW_AI_CVE_HANZI_CHONGQING			= 7,	//!< 重庆
	AW_AI_CVE_HANZI_HEILONGJIANG		= 8,	//!< 黑龙江
	AW_AI_CVE_HANZI_JILIN				= 9,	//!< 吉林
	AW_AI_CVE_HANZI_LIAONING			= 10,	//!< 辽宁
	AW_AI_CVE_HANZI_NEIMENG				= 11,	//!< 内蒙古
	AW_AI_CVE_HANZI_HEBEI				= 12,	//!< 河北
	AW_AI_CVE_HANZI_SHANDONG			= 13,	//!< 山东
	AW_AI_CVE_HANZI_SHANXI				= 14,	//!< 山西
	AW_AI_CVE_HANZI_ANHUI				= 15,	//!< 安徽
	AW_AI_CVE_HANZI_JIANGSU				= 16,	//!< 江苏
	AW_AI_CVE_HANZI_ZHEJIANG			= 17,	//!< 浙江
	AW_AI_CVE_HANZI_FUJIAN				= 18,	//!< 福建
	AW_AI_CVE_HANZI_GUANGDONG			= 19,	//!< 广东
	AW_AI_CVE_HANZI_HENAN				= 20,	//!< 河南
	AW_AI_CVE_HANZI_JIANGXI				= 21,	//!< 江西
	AW_AI_CVE_HANZI_HUNAN				= 22,	//!< 湖南
	AW_AI_CVE_HANZI_HUBEI				= 23,	//!< 湖北
	AW_AI_CVE_HANZI_GUANGXI				= 24,	//!< 广西
	AW_AI_CVE_HANZI_HAINAN				= 25,	//!< 海南
	AW_AI_CVE_HANZI_YUNNAN				= 26,	//!< 云南
	AW_AI_CVE_HANZI_GUIZHOU				= 27,	//!< 贵州
	AW_AI_CVE_HANZI_SICHUAN				= 28,	//!< 四川
	AW_AI_CVE_HANZI_XIAN				= 29,	//!< 陕西
	AW_AI_CVE_HANZI_GANSU				= 30,	//!< 甘肃
	AW_AI_CVE_HANZI_NINGXIA				= 31,	//!< 宁夏
	AW_AI_CVE_HANZI_QINGHAI				= 32,	//!< 青海
	AW_AI_CVE_HANZI_XIZANG				= 33,	//!< 西藏
	AW_AI_CVE_HANZI_XINJIANG			= 34	//!< 新疆
}AW_AI_CVE_VLPR_CHARTYPE_E;	

//-------------------------------------------------------
// 车牌类型定义      									 
//-------------------------------------------------------

//! 车牌类型定义
typedef enum 
{
	AW_AI_CVE_PLATE_UNCERTAIN			= 0,			//!< 不确定的
	AW_AI_CVE_PLATE_BLUE				= 1,			//!< 蓝牌车
	AW_AI_CVE_PLATE_YELLOW				= 2,			//!< 单层黄牌车
	AW_AI_CVE_PLATE_POLICE				= 4,			//!< 警车
	AW_AI_CVE_PLATE_WUJING				= 8,			//!< 武警车辆
	AW_AI_CVE_PLATE_DBYELLOW			= 16,			//!< 双层黄牌
	AW_AI_CVE_PLATE_MOTOR				= 32,			//!< 摩托车
	AW_AI_CVE_PLATE_INSTRUCTIONCAR		= 64,			//!< 教练车
	AW_AI_CVE_PLATE_MILITARY			= 128,			//!< 军车
	AW_AI_CVE_PLATE_PERSONAL			= 256,			//!< 个性化车
	AW_AI_CVE_PLATE_GANGAO				= 512,			//!< 港澳车
	AW_AI_CVE_PLATE_EMBASSY				= 1024,			//!< 使馆车
	AW_AI_CVE_PLATE_NONGLARE			= 2048,			//!< 老式车牌(不反光)
	AW_AI_CVE_PLATE_AVIATION			= 4096,			//!< 民航车牌
	AW_AI_CVE_PLATE_NEWENERGY			= 8192,			//!< 新能源车牌

	AW_AI_CVE_PLATE_WHITE_TWOTWO		= 0x10000001,	//!< 2+2模型；
	AW_AI_CVE_PLATE_WHITE_TWOTHR		= 0x10000002,	//!< 2+3模型；
	AW_AI_CVE_PLATE_WHITE_THRTWO		= 0x10000004,	//!< 3+2模型；
	AW_AI_CVE_PLATE_WHITE_THRTHR		= 0x10000008,	//!< 3+3模型；
	AW_AI_CVE_PLATE_WHITE_THRFOR		= 0x10000010,	//!< 3+4模型；

	AW_AI_CVE_PLATE_BLACK_THRTWO		= 0x10000020,	//!< 3+2模型；
	AW_AI_CVE_PLATE_BLACK_TWOTHR		= 0x10000040,	//!< 2+3模型；
	AW_AI_CVE_PLATE_BLACK_THRTHR		= 0x10000080,	//!< 3+3模型；
	AW_AI_CVE_PLATE_BLACK_TWOFOR		= 0x10000100,	//!< 2+4模型；
	AW_AI_CVE_PLATE_BLACK_FORTWO		= 0x10000200,	//!< 4+2模型；
	AW_AI_CVE_PLATE_BLACK_THRFOR		= 0x10000400,	//!< 3+4模型；
}AW_AI_CVE_PLATETYPE_E;

//-------------------------------------------------------
// 车牌颜色定义
//-------------------------------------------------------

// 车牌颜色
typedef enum
{
	AW_AI_CVE_PLATE_COLOR_UNKNOWN		= 0,	//!<  未知
	AW_AI_CVE_PLATE_COLOR_BLUE			= 1,	//!<  蓝底白字
	AW_AI_CVE_PLATE_COLOR_YELLOW		= 2,	//!<  黄底黑字
	AW_AI_CVE_PLATE_COLOR_WHITE			= 3,	//!<  白底黑字
	AW_AI_CVE_PLATE_COLOR_BLACK			= 4,	//!<  黑底白字
	AW_AI_CVE_PLATE_COLOR_GREEN			= 5,	//!<  绿底白字
	AW_AI_CVE_PLATE_COLOR_GREENBLACK	= 6		//!<  绿底黑字
}AW_AI_CVE_PLATECOLOR_E;

typedef enum
{
	AW_AI_CVE_VEHICLE_COLOR_UNKOWN= 0,			//!<  未知
	AW_AI_CVE_VEHICLE_COLOR_RED = 1,			//!<  红色
	AW_AI_CVE_VEHICLE_COLOR_GREEN = 2,			//!<  绿色
	AW_AI_CVE_VEHICLE_COLOR_BLUE = 3,			//!<  蓝色
	AW_AI_CVE_VEHICLE_COLOR_YELLOW = 4,			//!<  黄色
	AW_AI_CVE_VEHICLE_COLOR_WHITE = 5,			//!<  白色
	AW_AI_CVE_VEHICLE_COLOR_GRAY = 6,			//!<  灰色
	AW_AI_CVE_VEHICLE_COLOR_BLACK = 7,			//!<  黑色
	AW_AI_CVE_VEHICLE_COLOR_PURPLE=8,			//!<  紫色
	AW_AI_CVE_VEHICLE_COLOR_BROWN=9,			//!<  棕色
	AW_AI_CVE_VEHICLE_COLOR_PINK=10				//!<  粉色
}AW_AI_CVE_VEHICLECOLOR_E;

//----------------------------------------------
// 车牌识别输出结构定义
//----------------------------------------------

#define AW_AI_CVE_VLPR_PLATE_CHAR_NUM		7								//!<  车牌字符数    
#define AW_AI_CVE_VLPR_PLATE_BUFLEN		16									//!<  车牌号最大值  

//! \ingroup group_vlpr
//! 车牌识别输出结构
typedef struct 
{
	AW_S8				as8PlateNum[AW_AI_CVE_VLPR_PLATE_BUFLEN];			//!<  车牌号
	AW_RECT_S			stPlateRect;										//!<  车牌矩形框；
	AW_RECT_S			astPlateCharRect[AW_AI_CVE_VLPR_PLATE_CHAR_NUM];	//!<  车牌字符矩形框
	AW_FLOAT			aflPlateCharConfid[AW_AI_CVE_VLPR_PLATE_CHAR_NUM];	//!<  车牌字符置信度
	AW_FLOAT			flConfidence;										//!<  车牌置信度
	AW_S32				s32PlateIntensity;									//!<  车牌亮度
	AW_AI_CVE_PLATECOLOR_E	ePlateColor;									//!<  车牌颜色
	AW_AI_CVE_PLATETYPE_E		ePlateType;									//!<  车牌类型
	AW_AI_CVE_VEHICLECOLOR_E	eVehicleColor;								//!<  车身颜色

	AW_FLOAT			flPlateAngleH;										//!<  车牌水平倾斜角度
	AW_FLOAT			flPlateAngleV;										//!<  车牌竖直倾斜角度
	AW_U8				u8PlateColorRate;									//!<  颜色匹配程度；
	AW_S8				astReserve[23];										//!<  预留参数
}AW_AI_CVE_VLPR_OUTPUT_S;


//----------------------------------------------
// 车牌识别处理结果定义
//----------------------------------------------

#define AW_AI_CVE_VLPR_MAX_OUTPUT_NUM		16								//!< 最大车牌数  

//! \ingroup group_vlpr
//! 车牌识别算法处理结果
typedef struct 
{
	AW_S32				s32NumOutput;										//!< 输出结果个数   
	AW_AI_CVE_VLPR_OUTPUT_S	astOutput[AW_AI_CVE_VLPR_MAX_OUTPUT_NUM];		//!< 多个输出结果
}AW_AI_CVE_VLPR_RULT_S;


#ifdef __cplusplus
}
#endif


#endif
