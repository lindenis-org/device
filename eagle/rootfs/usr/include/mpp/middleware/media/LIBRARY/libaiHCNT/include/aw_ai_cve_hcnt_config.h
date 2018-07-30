/*! \file aw_ai_cve_hcnt_config.h
\brief aw_ai_cve_hcnt_config.h document.
*/

#ifndef __AW_AI_CVE_HCNT_CONFIG_H__
#define __AW_AI_CVE_HCNT_CONFIG_H__

#include "aw_ai_cve_base_type.h"


#ifdef __cplusplus
extern "C"{
#endif


//----------------------------------------------
//  hcnt param definition
//----------------------------------------------

//! HCNT功能码
typedef enum
{
	AW_AI_CVE_HCNT_FUNC_PERIMETER     = 0x00000001,  //!< 周界入侵
	AW_AI_CVE_HCNT_FUNC_HUMANCOUNT    = 0x00000002,  //!< 人员计数
} AW_AI_CVE_HCNT_FUNCODE;

//! 周界入侵
typedef struct
{
	AW_POLYGON_S region;           //!< 分析区域
} AW_AI_CVE_HCNT_VANA_PARAM_PERIMETER;

//! 人员计数
typedef struct
{
	AW_AI_CVE_CUT_LINE_S cutline;           //!< 切面线段
} AW_AI_CVE_HCNT_VANA_PARAM_HUMANCOUNT;

//! 功能参数
typedef union
{
	AW_AI_CVE_HCNT_VANA_PARAM_PERIMETER   perimeter;  //!< 周界入侵
	AW_AI_CVE_HCNT_VANA_PARAM_HUMANCOUNT  humancount; //!< 人员计数
} AW_AI_CVE_HCNT_VANA_PARAM;

//! 功能参数
typedef struct
{
	AW_AI_CVE_HCNT_VANA_PARAM_PERIMETER   perimeter;  //!< 周界入侵
	AW_AI_CVE_HCNT_VANA_PARAM_HUMANCOUNT  humancount; //!< 人员计数
} AW_AI_CVE_HCNT_VANA_PARAM_S;

//! 分析功能
typedef struct
{
	AW_S8 name[32];                    //!< 功能名称
	AW_U32 enable;                     //!< 是否使能
	AW_U32 level;                      //!< 警报级别，参考\ref AW_ALARM_LEVEL
	AW_U32 mode;                       //!< 分析模式，参考\ref HCNT_FUNCODE
	AW_AI_CVE_HCNT_VANA_PARAM param;          //!< 分析参数
} AW_AI_CVE_HCNT_VANA_FUNC;

#define AW_AI_CVE_HCNT_VANA_FUNC_MAXNUM 32
//! 分析功能集合
typedef struct
{
	AW_AI_CVE_HCNT_VANA_PARAM_S defparam;     //!< 缺省功能参数
    AW_S32 num_used;                   //!< 有效功能数目
	AW_AI_CVE_HCNT_VANA_FUNC funcs[AW_AI_CVE_HCNT_VANA_FUNC_MAXNUM];//!< 分析功能数组
} AW_AI_CVE_HCNT_VANA_FUNCTION;

//! \ingroup group_hcnt
//! 目标识别算法应用参数
typedef struct
{
    AW_S32 dim_w;									//!< 配置图像的宽度
    AW_S32 dim_h;									//!< 配置图像的高度
	AW_AI_CVE_HCNT_VANA_FUNCTION functions;			//!< 分析功能
} AW_AI_CVE_HCNT_PARAM_APP;


//! \ingroup group_hcnt
//! 目标识别算法IO参数
typedef struct
{
    AW_S32 s32Width;                       //!< 图像宽度
    AW_S32 s32Height;                      //!< 图像高度
    AW_U32 u32FrameTime;                   //!< 图像帧的时间长度（单位：毫秒）
} AW_AI_CVE_HCNT_PARAM_INOUT;


//! \ingroup group_hcnt
//! 目标识别算法性能参数
typedef struct
{
    // 系统参数
    AW_S32 proc_interval;                  //!< 图像处理时间间隔(取值范围：0～200毫秒；缺省值：100)
    AW_FLOAT head_radevi;                  //!< 头部半径容差比率(取值范围：0.1～1.0；缺省值：0.3)
    AW_S32 ciruniq_rad;                    //!< 圆单一性半径比率(取值范围：-100～100；缺省值：50)
    AW_S32 sensitivity;                    //!< 检测灵敏度(0：高，1：中，2：低；缺省值：0)
} AW_AI_CVE_HCNT_PARAM_PERF;

//! \ingroup group_hcnt
//! 目标识别算法处理参数
typedef struct
{
    AW_AI_CVE_HCNT_PARAM_APP cParamApp;           //!< 应用参数
    AW_AI_CVE_HCNT_PARAM_PERF cParamPerf;          //!< 性能参数
} AW_AI_CVE_HCNT_PARAM_ALGO;

//! \ingroup group_hcnt
//! 目标识别算法参数
typedef struct
{
    AW_AI_CVE_HCNT_PARAM_INOUT cParamInout;       //!< 算法IO参数
    AW_AI_CVE_HCNT_PARAM_ALGO cParamAlgo;       //!< 算法处理参数
} AW_AI_CVE_HCNT_PARAM;


//! \ingroup group_hcnt
//! \{

//! \brief 查询参数配置版本
//! \param pVersion     [out] 版本字符串，字符串缓冲区长度至少是32
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_HCNT_GetSceneVersion( AW_CHAR *pVersion );

//! \brief 将目标识别算法处理参数打包为XML文件
//! \param pParams      [in] 参数数据，参考\ref AW_AI_CVE_HCNT_PARAM_ALGO
//! \param pFilNam      [in] XML文件名
//! \param pMemMgr      [in] 内存管理器，当前置为NULL
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_HCNT_PacketParamFile( AW_AI_CVE_HCNT_PARAM_ALGO *pParams, AW_CHAR *pFilNam, AW_PVOID pMemMgr );

//! \brief 将目标识别算法处理参数打包为XML字符串
//! \param pParams      [in] 参数数据，参考\ref AW_AI_CVE_HCNT_PARAM_ALGO
//! \param pBuffer      [out] XML字符串缓冲区
//! \param nBufLen      [in] 缓冲区长度
//! \param pMemMgr      [in] 内存管理器，当前置为NULL
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_HCNT_PacketParamString( AW_AI_CVE_HCNT_PARAM_ALGO *pParams, AW_CHAR *pBuffer, AW_S32 nBufLen, AW_PVOID pMemMgr );

//! \brief 从XML文件解析目标识别算法处理参数
//! \param pFilNam      [in] XML文件名
//! \param pParams      [out] 参数数据，参考\ref AW_AI_CVE_HCNT_PARAM_ALGO
//! \param pMemMgr      [in] 内存管理器，当前置为NULL
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_HCNT_ParseParamFile( AW_CHAR *pFilNam, AW_AI_CVE_HCNT_PARAM_ALGO *pParams, AW_PVOID pMemMgr );

//! \brief 从XML字符串解析目标识别算法处理参数
//! \param pXmlString   [in] XML字符串
//! \param pParams      [out] 参数数据，参考\ref AW_AI_CVE_HCNT_PARAM_ALGO
//! \param pMemMgr      [in] 内存管理器，当前置为NULL
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_HCNT_ParseParamString( AW_CHAR *pXmlString, AW_AI_CVE_HCNT_PARAM_ALGO *pParams, AW_PVOID pMemMgr );

//! \brief 获取缺省参数字符串
//! \return             字符串指针
AW_CVE_EXPORTS AW_CHAR* AW_HCNT_GetParamString();

//! \}


#ifdef __cplusplus
}
#endif


#endif  // __AW_AI_CVE_HCNT_CONFIG_H__
