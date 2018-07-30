/*! \file aw_ai_cve_dtca_config.h
\brief aw_ai_cve_dtca_config.h document.
*/

#ifndef __AW_AI_CVE_DTCA_CONFIG_H__
#define __AW_AI_CVE_DTCA_CONFIG_H__

#include "aw_ai_cve_base_type.h"


#ifdef __cplusplus
extern "C"{
#endif


// #define VERSION_MODH

#if defined(VERSION_MODB)
#define SUPPORT_FUNSET_B
#elif defined(VERSION_MODBE)
#define SUPPORT_FUNSET_B
#elif defined(VERSION_MODU)
#define SUPPORT_FUNSET_B
#define SUPPORT_FUNSET_U
#elif defined(VERSION_MODUE)
#define SUPPORT_FUNSET_B
#define SUPPORT_FUNSET_U
#elif defined(VERSION_MODUS)
#define SUPPORT_FUNSET_B
#define SUPPORT_FUNSET_U
#define SUPPORT_FUNSET_S
#elif defined(VERSION_MODP)
#define SUPPORT_FUNSET_B
#define SUPPORT_FUNSET_U
#define SUPPORT_FUNSET_P
#define SUPPORT_FUNSET_S
#define SUPPORT_IES
#define SUPPORT_BGMODEL
#elif defined(VERSION_MODH)
#define SUPPORT_FUNSET_B
#define SUPPORT_FUNSET_H
#define SUPPORT_HEADET
#define SUPPORT_INNCLBR
#elif defined(VERSION_SOD)
#define SUPPORT_FUNSET_S
#define SUPPORT_IES
#elif defined(VERSION_TID)
#define SUPPORT_FUNSET_T
#define SUPPORT_IES
#else
#define SUPPORT_FUNSET_B
#define SUPPORT_FUNSET_U
#define SUPPORT_FUNSET_P
#define SUPPORT_FUNSET_H
#define SUPPORT_FUNSET_S
#define SUPPORT_FUNSET_T
#define SUPPORT_IES
#define SUPPORT_BGMODEL
#define SUPPORT_HEADET
#define SUPPORT_INNCLBR
#endif

//----------------------------------------------
//  dtca param definition
//----------------------------------------------

//! DTCA功能码
typedef enum
{
// #ifdef SUPPORT_FUNSET_B
	AW_AI_CVE_DTCA_FUNC_PERIMETER             = 0x00000001,	//!< 周界入侵
	AW_AI_CVE_DTCA_FUNC_TRIPWIRE              = 0x00000010,	//!< 绊线
// #endif
// #ifdef SUPPORT_FUNSET_U
	AW_AI_CVE_DTCA_FUNC_MTRIPWIRE             = 0x00000020,	//!< 双绊线
	AW_AI_CVE_DTCA_FUNC_LOITER                = 0x00000002,	//!< 徘徊
	AW_AI_CVE_DTCA_FUNC_CONVERSE              = 0x00000008,	//!< 逆行
// #endif
// #ifdef SUPPORT_FUNSET_P
	AW_AI_CVE_DTCA_FUNC_ABNORMALVEL           = 0x00000004,	//!< 非正常速度
	AW_AI_CVE_DTCA_FUNC_MLOITER               = 0x00010000,	//!< 多人徘徊
	AW_AI_CVE_DTCA_FUNC_NOPARKING             = 0x00020000,	//!< 非法停车
// #endif
// #ifdef SUPPORT_FUNSET_H
	AW_AI_CVE_DTCA_FUNC_SLIPUP                = 0x00040000,	//!< 倒地
// #endif
// #ifdef SUPPORT_FUNSET_S
	AW_AI_CVE_DTCA_FUNC_OBJLEFT               = 0x00000040,	//!< 物品遗留
	AW_AI_CVE_DTCA_FUNC_OBJREMOVED            = 0x00000080,	//!< 物品移走
// #endif
// #ifdef SUPPORT_FUNSET_T
	AW_AI_CVE_DTCA_FUNC_VEHICLE_CONVERSE      = 0x00000100,	//!< 车辆逆行
	AW_AI_CVE_DTCA_FUNC_VEHICLE_PARK          = 0x00000200,	//!< 车辆停车
	AW_AI_CVE_DTCA_FUNC_VEHICLE_OVERSPEED     = 0x00000400,	//!< 车辆超速
	AW_AI_CVE_DTCA_FUNC_VEHICLE_UNDERSPEED    = 0x00000800,	//!< 车辆低速
	AW_AI_CVE_DTCA_FUNC_HUMAN_ACROSS          = 0x00001000,	//!< 行人穿越
	AW_AI_CVE_DTCA_FUNC_OBJECT_LEFT           = 0x00002000,	//!< 物品遗撒
	AW_AI_CVE_DTCA_FUNC_VEHICLE_OCCUPATION    = 0x00004000,	//!< 占用应急车道
// #endif
} AW_AI_CVE_DTCA_FUNCODE;

// #ifdef SUPPORT_FUNSET_B

//! 周界入侵
typedef struct
{
	AW_POLYGON_S region;           //!< 分析区域
	AW_S32 type_constrain;			//!< 是否限定目标类型(取值范围：0(否)，1(是)；缺省值：1)
	AW_S32 type_mode;				//!< 类型限定模式(取值范围：0(人或车)，1(人)，2(车)；缺省值：0)
	AW_S32 size_constrain;			//!< 是否限定目标尺寸(取值范围：0(否)，1(是)；缺省值：0)
	AW_S32 size_min;               //!< 目标最小尺寸(单位：平方厘米)(取值范围：0~1000000；缺省值：1000)
	AW_S32 size_max;               //!< 目标最大尺寸(单位：平方厘米)(取值范围：0~1000000；缺省值：100000)
} AW_AI_CVE_VANA_PARAM_PERIMETER;

//! 绊线线段参数
typedef struct
{
	AW_S32 bidir;			        //!< 表示绊线是否为双向绊线(取值范围：0(否)，1(是)；缺省值：0)
	AW_S32 angle;				    //!< 绊线禁止方向角度(单位：度)
	AW_LINE_S line;                //!< 绊线位置(单位：像素)
} AW_AI_CVE_TRIPWIRE;

//! 绊线
typedef struct
{
	AW_AI_CVE_TRIPWIRE twline;            //!< 绊线线段参数
	AW_S32 type_constrain;			//!< 是否限定目标类型(取值范围：0(否)，1(是)；缺省值：1)
	AW_S32 type_mode;				//!< 类型限定模式(取值范围：0(人或车)，1(人)，2(车)；缺省值：0)
	AW_S32 size_constrain;			//!< 是否限定目标尺寸(取值范围：0(否)，1(是)；缺省值：0)
	AW_S32 size_min;               //!< 目标最小尺寸(单位：平方厘米)(取值范围：0~1000000；缺省值：1000)
	AW_S32 size_max;               //!< 目标最大尺寸(单位：平方厘米)(取值范围：0~1000000；缺省值：100000)
} AW_AI_CVE_VANA_PARAM_TRIPWIRE;

// #endif // SUPPORT_FUNSET_B
// 
// #ifdef SUPPORT_FUNSET_U

//! 双绊线线段参数
typedef struct
{
	AW_S32 time_max;               //!<  穿越两条线的最长时间间隔(单位：秒)(取值范围：1~60；缺省值：5)
	AW_S32 angles[2];              //!<  绊线禁止方向角度(单位：度)
	AW_LINE_S lines[2];            //!<  绊线位置(单位：像素)
} AW_AI_CVE_MTRIPWIRE;

//! 双绊线
typedef struct
{
	AW_AI_CVE_MTRIPWIRE twline;           //!< 双绊线线段参数
	AW_S32 type_constrain;			//!< 是否限定目标类型(取值范围：0(否)，1(是)；缺省值：1)
	AW_S32 type_mode;				//!< 类型限定模式(取值范围：0(人或车)，1(人)，2(车)；缺省值：0)
	AW_S32 size_constrain;			//!< 是否限定目标尺寸(取值范围：0(否)，1(是)；缺省值：0)
	AW_S32 size_min;               //!< 目标最小尺寸(单位：平方厘米)(取值范围：0~1000000；缺省值：1000)
	AW_S32 size_max;               //!< 目标最大尺寸(单位：平方厘米)(取值范围：0~1000000；缺省值：100000)
} AW_AI_CVE_VANA_PARAM_MTRIPWIRE;

//! 徘徊
typedef struct
{
	AW_POLYGON_S region;           //!< 分析区域
	AW_S32 type_constrain;			//!< 是否限定目标类型(取值范围：0(否)，1(是)；缺省值：1)
	AW_S32 type_mode;				//!< 类型限定模式(取值范围：0(人或车)，1(人)，2(车)；缺省值：0)
	AW_S32 size_constrain;			//!< 是否限定目标尺寸(取值范围：0(否)，1(是)；缺省值：0)
	AW_S32 size_min;               //!< 目标最小尺寸(单位：平方厘米)(取值范围：0~1000000；缺省值：1000)
	AW_S32 size_max;               //!< 目标最大尺寸(单位：平方厘米)(取值范围：0~1000000；缺省值：100000)
	AW_S32 time_min;		        //!< 徘徊最短时间(单位: 秒)(取值范围：5~60；缺省值：10)
	AW_S32 analysis_path;			//!< 是否启用路径判断(取值范围：0(否)，1(是)；缺省值：1)
} AW_AI_CVE_VANA_PARAM_LOITER;

//! 逆行
typedef struct
{
	AW_POLYGON_S region;           //!< 分析区域
	AW_S32 type_constrain;			//!< 是否限定目标类型(取值范围：0(否)，1(是)；缺省值：1)
	AW_S32 type_mode;				//!< 类型限定模式(取值范围：0(人或车)，1(人)，2(车)；缺省值：0)
	AW_S32 size_constrain;			//!< 是否限定目标尺寸(取值范围：0(否)，1(是)；缺省值：0)
	AW_S32 size_min;               //!< 目标最小尺寸(单位：平方厘米)(取值范围：0~1000000；缺省值：1000)
	AW_S32 size_max;               //!< 目标最大尺寸(单位：平方厘米)(取值范围：0~1000000；缺省值：100000)
	AW_S32 direction;              //!< 逆行方向角度(单位：度)
} AW_AI_CVE_VANA_PARAM_CONVERSE;

// #endif // SUPPORT_FUNSET_U
// 
// #ifdef SUPPORT_FUNSET_P

//! 非正常速度
typedef struct
{
	AW_POLYGON_S region;           //!< 分析区域
	AW_S32 type_constrain;			//!< 是否限定目标类型(取值范围：0(否)，1(是)；缺省值：1)
	AW_S32 type_mode;				//!< 类型限定模式(取值范围：0(人或车)，1(人)，2(车)；缺省值：0)
	AW_S32 size_constrain;			//!< 是否限定目标尺寸(取值范围：0(否)，1(是)；缺省值：0)
	AW_S32 size_min;               //!< 目标最小尺寸(单位：平方厘米)(取值范围：0~1000000；缺省值：1000)
	AW_S32 size_max;               //!< 目标最大尺寸(单位：平方厘米)(取值范围：0~1000000；缺省值：100000)
	AW_S32	velo_flag;              //!< 限速标识（0：允许范围；1：禁止范围；缺省值：0）
    AW_S32 velo_min;               //!< 最小运动速度(单位：米/秒)(取值范围：0~1000；缺省值：0)
    AW_S32 velo_max;               //!< 最大运动速度(单位：米/秒)(取值范围：0~1000；缺省值：5)
} AW_AI_CVE_VANA_PARAM_ABNORMALVEL;

//! 多人徘徊
typedef struct
{
	AW_POLYGON_S region;           //!< 分析区域
	AW_S32 size_constrain;			//!< 是否限定目标尺寸(取值范围：0(否)，1(是)；缺省值：1)
	AW_S32 size_min;               //!< 目标最小尺寸(单位：平方厘米)(取值范围：0~1000000；缺省值：1000)
	AW_S32 size_max;               //!< 目标最大尺寸(单位：平方厘米)(取值范围：0~1000000；缺省值：1000000)
	AW_S32 time_min;               //!< 徘徊最短时间(单位：秒)(取值范围：5~60；缺省值：5)
	AW_AI_CVE_FORBIDDEN_INTERVAL_S tgtnum_interval;	// 禁止的人数范围
} AW_AI_CVE_VANA_PARAM_MLOITER;

//! 非法停车
typedef struct
{
	AW_POLYGON_S region;           //!< 分析区域
	AW_S32 size_min;               //!< 车辆最小尺寸(单位：平方厘米)(取值范围：0~1000000；缺省值：1000)
	AW_S32 size_max;               //!< 车辆最大尺寸(单位：平方厘米)(取值范围：0~1000000；缺省值：1000000)
	AW_S32 time_min;               //!< 车辆停留最短时间(单位：秒)(取值范围：5~60；缺省值：5)
} AW_AI_CVE_VANA_PARAM_NOPARKING;

// #endif // SUPPORT_FUNSET_P
// 
// #ifdef SUPPORT_FUNSET_H

//! 倒地
typedef struct
{
	AW_POLYGON_S region;           //!< 分析区域
	AW_S32 type_constrain;			//!< 是否限定目标类型（人）(取值范围：0(否)，1(是)；缺省值：1)
	AW_S32 size_constrain;			//!< 是否限定目标尺寸(取值范围：0(否)，1(是)；缺省值：0)
	AW_S32 size_min;               //!< 目标最小尺寸(单位：平方厘米)(取值范围：0~1000000；缺省值：1000)
	AW_S32 size_max;               //!< 目标最大尺寸(单位：平方厘米)(取值范围：0~1000000；缺省值：100000)
	AW_S32 time_dura;              //!< 倒地最短持续时间(单位：秒)(取值范围：5~60；缺省值：5)
	AW_S32 height_ratio;           //!< 倒地后的高度比率阈值(取值范围：20~200；缺省值：100)
} AW_AI_CVE_VANA_PARAM_SLIPUP;

// #endif // SUPPORT_FUNSET_H
// 
// #ifdef SUPPORT_FUNSET_S

//! 物品遗留
typedef struct
{
	AW_POLYGON_S region;           //!< 分析区域
	AW_S32 size_min;               //!< 物品最小尺寸(单位：平方厘米)(取值范围：10~40000；缺省值：100)
	AW_S32 size_max;               //!< 物品最大尺寸(单位：平方厘米)(取值范围：10~40000；缺省值：10000)
	AW_S32 time_min;               //!< 物品遗留最短时间(单位：秒)(取值范围：5~60；缺省值：5)
} AW_AI_CVE_VANA_PARAM_OBJLEFT;

//! 物品移走
typedef struct
{
	AW_POLYGON_S region;           //!< 分析区域
	AW_S32 size_min;               //!< 物品最小尺寸(单位：平方厘米)(取值范围：10~40000；缺省值：100)
	AW_S32 size_max;               //!< 物品最大尺寸(单位：平方厘米)(取值范围：10~40000；缺省值：100)
	AW_S32 time_min;               //!< 物品移走最短时间(单位：秒)(取值范围：5~60；缺省值：5)
} AW_AI_CVE_VANA_PARAM_OBJREMOVED;

// #endif // SUPPORT_FUNSET_S
// 
// #ifdef SUPPORT_FUNSET_T

//! 车辆逆行
typedef struct
{
	AW_POLYGON_S region;           //!< 分析区域
    AW_S32 direction;              //!< 逆行方向角度(单位：度)
} AW_AI_CVE_VANA_PARAM_VEHICLE_CONVERSE;

//! 车辆停车
typedef struct
{
	AW_POLYGON_S region;           //!< 分析区域
    AW_S32 velo_max;               //!< 最大运动速度(单位：厘米/秒)(取值范围：0~200；缺省值：10)
} AW_AI_CVE_VANA_PARAM_VEHICLE_PARK;

//! 车辆超速
typedef struct
{
	AW_POLYGON_S region;           //!< 分析区域
    AW_S32 velo_min;               //!< 最小运动速度(单位：千米/小时)(取值范围：0~200；缺省值：120)
} AW_AI_CVE_VANA_PARAM_VEHICLE_OVERSPEED;

//! 车辆低速
typedef struct
{
	AW_POLYGON_S region;           //!< 分析区域
    AW_S32 velo_max;               //!< 最大运动速度(单位：千米/小时)(取值范围：0~200；缺省值：30)
} AW_AI_CVE_VANA_PARAM_VEHICLE_UNDERSPEED;

//! 占用应急车道
typedef struct
{
	AW_POLYGON_S region;           //!< 分析区域
} AW_AI_CVE_VANA_PARAM_VEHICLE_OCCUPATION;

//! 行人穿越
typedef struct
{
	AW_POLYGON_S region;           //!< 分析区域
} AW_AI_CVE_VANA_PARAM_HUMAN_ACROSS;

//! 物品遗撒
typedef struct
{
	AW_POLYGON_S region;           //!< 分析区域
	AW_S32 size_min;               //!< 物品最小尺寸(单位：平方厘米)(取值范围：10~40000；缺省值：100)
	AW_S32 size_max;               //!< 物品最大尺寸(单位：平方厘米)(取值范围：10~40000；缺省值：10000)
	AW_S32 time_min;               //!< 物品遗留最短时间(单位：秒)(取值范围：5~60；缺省值：5)
} AW_AI_CVE_VANA_PARAM_OBJECT_LEFT;

// #endif // SUPPORT_FUNSET_T

//! 功能参数
typedef union
{
// #ifdef SUPPORT_FUNSET_B
	AW_AI_CVE_VANA_PARAM_PERIMETER             perimeter;          //!< 周界入侵
	AW_AI_CVE_VANA_PARAM_TRIPWIRE              tripwire;           //!< 绊线
// #endif
// #ifdef SUPPORT_FUNSET_U
	AW_AI_CVE_VANA_PARAM_MTRIPWIRE             mtripwire;          //!< 双绊线
	AW_AI_CVE_VANA_PARAM_LOITER                loiter;             //!< 徘徊
	AW_AI_CVE_VANA_PARAM_CONVERSE              converse;           //!< 逆行
// #endif
// #ifdef SUPPORT_FUNSET_P
	AW_AI_CVE_VANA_PARAM_ABNORMALVEL           abnormalvel;        //!< 非正常速度
	AW_AI_CVE_VANA_PARAM_MLOITER               mloiter;            //!< 多人徘徊
	AW_AI_CVE_VANA_PARAM_NOPARKING             noparking;          //!< 非法停车
// #endif
// #ifdef SUPPORT_FUNSET_H
	AW_AI_CVE_VANA_PARAM_SLIPUP                slipup;             //!< 倒地
// #endif
// #ifdef SUPPORT_FUNSET_S
	AW_AI_CVE_VANA_PARAM_OBJLEFT               objleft;            //!< 物品遗留
	AW_AI_CVE_VANA_PARAM_OBJREMOVED            objremoved;         //!< 物品移走
// #endif
// #ifdef SUPPORT_FUNSET_T
	AW_AI_CVE_VANA_PARAM_VEHICLE_CONVERSE      v_converse;         //!< 车辆逆行
	AW_AI_CVE_VANA_PARAM_VEHICLE_PARK          v_park;             //!< 车辆停车
	AW_AI_CVE_VANA_PARAM_VEHICLE_OVERSPEED     v_overspeed;        //!< 车辆超速
	AW_AI_CVE_VANA_PARAM_VEHICLE_UNDERSPEED    v_underspeed;       //!< 车辆低速
	AW_AI_CVE_VANA_PARAM_VEHICLE_OCCUPATION    v_occupation;       //!< 占用应急车道
	AW_AI_CVE_VANA_PARAM_HUMAN_ACROSS          h_across;           //!< 行人穿越
	AW_AI_CVE_VANA_PARAM_OBJECT_LEFT           o_left;             //!< 物品遗撒
// #endif
} AW_AI_CVE_VANA_PARAM;

//! 功能参数
typedef struct
{
// #ifdef SUPPORT_FUNSET_B
	AW_AI_CVE_VANA_PARAM_PERIMETER             perimeter;          //!< 周界入侵
	AW_AI_CVE_VANA_PARAM_TRIPWIRE              tripwire;           //!< 绊线
// #endif
// #ifdef SUPPORT_FUNSET_U
	AW_AI_CVE_VANA_PARAM_MTRIPWIRE             mtripwire;          //!< 双绊线
	AW_AI_CVE_VANA_PARAM_LOITER                loiter;             //!< 徘徊
	AW_AI_CVE_VANA_PARAM_CONVERSE              converse;           //!< 逆行
// #endif
// #ifdef SUPPORT_FUNSET_P
	AW_AI_CVE_VANA_PARAM_ABNORMALVEL           abnormalvel;        //!< 非正常速度
	AW_AI_CVE_VANA_PARAM_MLOITER               mloiter;            //!< 多人徘徊
	AW_AI_CVE_VANA_PARAM_NOPARKING             noparking;          //!< 非法停车
// #endif
// #ifdef SUPPORT_FUNSET_H
	AW_AI_CVE_VANA_PARAM_SLIPUP                slipup;             //!< 倒地
// #endif
// #ifdef SUPPORT_FUNSET_S
	AW_AI_CVE_VANA_PARAM_OBJLEFT               objleft;            //!< 物品遗留
	AW_AI_CVE_VANA_PARAM_OBJREMOVED            objremoved;         //!< 物品移走
// #endif
// #ifdef SUPPORT_FUNSET_T
	AW_AI_CVE_VANA_PARAM_VEHICLE_CONVERSE      v_converse;         //!< 车辆逆行
	AW_AI_CVE_VANA_PARAM_VEHICLE_PARK          v_park;             //!< 车辆停车
	AW_AI_CVE_VANA_PARAM_VEHICLE_OVERSPEED     v_overspeed;        //!< 车辆超速
	AW_AI_CVE_VANA_PARAM_VEHICLE_UNDERSPEED    v_underspeed;       //!< 车辆低速
	AW_AI_CVE_VANA_PARAM_VEHICLE_OCCUPATION    v_occupation;       //!< 占用应急车道
	AW_AI_CVE_VANA_PARAM_HUMAN_ACROSS          h_across;           //!< 行人穿越
	AW_AI_CVE_VANA_PARAM_OBJECT_LEFT           o_left;             //!< 物品遗撒
// #endif
} AW_AI_CVE_VANA_PARAM_S;

//! 分析功能
typedef struct
{
	AW_S8 name[32];                    //!< 功能名称
	AW_U32 enable;                     //!< 是否使能
	AW_U32 level;                      //!< 警报级别，参考\ref AW_AI_CVE_ALARM_LEVEL_E
	AW_U32 mode;                       //!< 分析模式，参考\ref DTCA_FUNCODE
	AW_AI_CVE_VANA_PARAM param;               //!< 分析参数
} AW_AI_CVE_VANA_FUNC;

#define AW_AI_CVE_VANA_FUNC_MAXNUM 32
//! 分析功能集合
typedef struct
{
	AW_AI_CVE_VANA_PARAM_S defparam;          //!< 缺省功能参数
    AW_S32 num_used;                   //!< 有效功能数目
	AW_AI_CVE_VANA_FUNC funcs[AW_AI_CVE_VANA_FUNC_MAXNUM];//!< 分析功能数组
} AW_AI_CVE_VANA_FUNCTION;

//! 性能参数
typedef struct
{
	AW_S32 do_istab;                       //!< 是否做电子稳像处理(取值范围：0(否)，1(是)；缺省值：0)
	AW_S32 scene_mode;						//!< 场景模式(取值范围：0(室外)，1(室内)；缺省值：0)
	AW_S32 sensitivity;					//!< 灵敏度(0：高，1：中，2：低；缺省值：1)
} AW_AI_CVE_PARA_PERFORMANCE;

//! \ingroup group_dtca
//! 目标识别算法应用参数
typedef struct
{
    AW_S32 dim_w;                          //!< 配置图像的宽度
    AW_S32 dim_h;                          //!< 配置图像的高度
	AW_AI_CVE_VANA_FUNCTION functions;            //!< 分析功能
    AW_AI_CVE_PARA_PERFORMANCE performance;       //!< 视频异常检测参数
} AW_AI_CVE_DTCA_PARAM_APP;

//! \ingroup group_dtca
//! 目标识别算法高级参数
typedef struct
{
// #ifdef SUPPORT_BGMODEL
	// 背景建模
	AW_S32 bgm_period;						//!< 是否启用周期运动背景建模(取值范围：0(否)，1(是)；缺省值：0)
	AW_S32 bgm_period_time;				//!< 周期运动时间(取值范围：1～60秒；缺省值：15)
	AW_S32 bgm_period_noise;				//!< 周期运动噪声(取值范围：0(低)，1(高)；缺省值：0)
	AW_S32 sensi_high_noise;				//!< 是否高噪声(取值范围：0(否)，1(是)；缺省值：0)
	AW_S32 sensi_low_contrast;				//!< 是否低对比度(取值范围：0(否)，1(是)；缺省值：0)
	AW_S32 bgm_debug;				        //!< 调试参数
	AW_S32 bgm_reserved[2];				//!< 保留字段
// #endif

// #ifdef SUPPORT_HEADET
	// 头部检测
	AW_S32 detect_head;                    //!< 是否检测头部(取值范围：0(否)，1(是)；缺省值：0)
	AW_S32 vote_mode;                      //!< 投票模式(取值范围：bit0(对黑区域投票) ，bit1(对白区域投票)；缺省值：1)
	AW_S32 vote_ratio;                     //!< 投票计数比率阈值(取值范围：0～500；缺省值：80)
	AW_S32 circonf_rat;                    //!< 圆置信度比率(取值范围：0～100；缺省值：20)
	AW_S32 head_reserved[4];				//!< 保留字段
// #endif

// #ifdef SUPPORT_INNCLBR
	// 相机信息
	AW_S32 use_caminfo;					//!< 是否使用相机信息(取值范围：0(否)，1(是)；缺省值：1)
	AW_S32 use_posinfo;					//!< 是否使用位置信息(取值范围：0(否)，1(是)；缺省值：1)
	AW_S32 cam_fov_vert;					//!< 相机垂直视场角(取值范围：0～180度；缺省值：50)
	AW_S32 cam_height;						//!< 相机安装高度(取值范围：0～300厘米；缺省值：160)
	AW_S32 tolerance_rat;					//!< 参数容差比率(取值范围：0～50；缺省值：20)
	AW_S32 tgt_height_min;					//!< 目标最小高度(取值范围：0～400厘米；缺省值：150)
	AW_S32 view_dis_max;					//!< 视场最远距离(取值范围：0～2000厘米；缺省值：1000)
	AW_S32 reftgt_height;					//!< 参考目标高度(取值范围：0～400厘米；缺省值：0)
	AW_S32 reftgt_pos_hy;					//!< 参考目标头顶位置(取值范围：0～1000像素；缺省值：0)
	AW_S32 reftgt_pos_fy;					//!< 参考目标脚底位置(取值范围：0～1000像素；缺省值：0)
	AW_S32 cam_reserved[6];				//!< 保留字段
// #endif

} AW_AI_CVE_DTCA_PARAM_ADV;

//! \ingroup group_dtca
//! 目标识别算法处理参数
typedef struct
{
	AW_AI_CVE_DTCA_PARAM_APP cParamApp;           //!< 应用参数
    AW_S32 s32UseAdvParam;                 //!< 是否使用高级参数
	AW_AI_CVE_DTCA_PARAM_ADV cParamAdv;           //!< 高级参数
} AW_AI_CVE_DTCA_PARAM_ALGO;

//! \ingroup group_dtca
//! 目标识别算法IO参数
typedef struct
{
    AW_S32 s32Width;                       //!< 图像宽度
    AW_S32 s32Height;                      //!< 图像高度
    AW_U32 u32FrameTime;                   //!< 图像帧的时间长度（单位：毫秒）
} AW_AI_CVE_DTCA_PARAM_INOUT;

//! \ingroup group_dtca
//! 目标识别算法参数
typedef struct
{
    AW_AI_CVE_DTCA_PARAM_INOUT cParamInout;       //!< 算法IO参数
    AW_AI_CVE_DTCA_PARAM_ALGO cParamAlgo;         //!< 算法处理参数
} AW_AI_CVE_DTCA_PARAM;


//! \ingroup group_dtca
//! \{

//! \brief 查询参数配置版本
//! \param pVersion     [out] 版本字符串，字符串缓冲区长度至少是32
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_DTCA_GetSceneVersion( AW_CHAR *pVersion );

//! \brief 将目标识别算法处理参数打包为XML文件
//! \param pParams      [in] 参数数据，参考\ref AW_AI_CVE_DTCA_PARAM_ALGO
//! \param pFilNam      [in] XML文件名
//! \param pMemMgr      [in] 内存管理器，当前置为NULL
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_DTCA_PacketParamFile( AW_AI_CVE_DTCA_PARAM_ALGO *pParams, AW_CHAR *pFilNam, AW_PVOID pMemMgr );

//! \brief 将目标识别算法处理参数打包为XML字符串
//! \param pParams      [in] 参数数据，参考\ref AW_AI_CVE_DTCA_PARAM_ALGO
//! \param pBuffer      [out] XML字符串缓冲区
//! \param nBufLen      [in] 缓冲区长度
//! \param pMemMgr      [in] 内存管理器，当前置为NULL
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_DTCA_PacketParamString( AW_AI_CVE_DTCA_PARAM_ALGO *pParams, AW_CHAR *pBuffer, AW_S32 nBufLen, AW_PVOID pMemMgr );

//! \brief 从XML文件解析目标识别算法处理参数
//! \param pFilNam      [in] XML文件名
//! \param pParams      [out] 参数数据，参考\ref AW_AI_CVE_DTCA_PARAM_ALGO
//! \param pMemMgr      [in] 内存管理器，当前置为NULL
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_DTCA_ParseParamFile( AW_CHAR *pFilNam, AW_AI_CVE_DTCA_PARAM_ALGO *pParams, AW_PVOID pMemMgr );

//! \brief 从XML字符串解析目标识别算法处理参数
//! \param pXmlString   [in] XML字符串
//! \param pParams      [out] 参数数据，参考\ref AW_AI_CVE_DTCA_PARAM_ALGO
//! \param pMemMgr      [in] 内存管理器，当前置为NULL
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_DTCA_ParseParamString( AW_CHAR *pXmlString, AW_AI_CVE_DTCA_PARAM_ALGO *pParams, AW_PVOID pMemMgr );

//! \brief 获取缺省参数字符串
//! \return             字符串指针
AW_CVE_EXPORTS AW_CHAR* AW_AI_CVE_DTCA_GetParamString();

//! \}


#ifdef __cplusplus
}
#endif


#endif  // __AW_AI_CVE_DTCA_CONFIG_H__
