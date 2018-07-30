/*! \file aw_ai_cve_clbr_config.h
\brief aw_ai_cve_clbr_config.h document.
*/

#ifndef __AW_AI_CVE_CLBR_CONFIG_H__
#define __AW_AI_CVE_CLBR_CONFIG_H__

#include "aw_ai_cve_base_type.h"


//! \defgroup group_clbr 景深标定
//!  景深标定数据类型与函数
//! \{
//! \}


#ifdef __cplusplus
extern "C"{
#endif


//----------------------------------------------
//  clbr param definition
//----------------------------------------------

#define AW_AI_CVE_FDEPTH_MINRES	1	//!< 景深分辨率最小值(unit: mm/pixel)
#define AW_AI_CVE_FDEPTH_MAXRES	254	//!< 景深分辨率最大值(unit: mm/pixel)

//! 标定线段类型
typedef enum
{
	AW_AI_CVE_FLINE_HORI = 0,
	AW_AI_CVE_FLINE_VERT
} AW_AI_CVE_FLINE_TYPE;

//! 标定线段
typedef struct
{
	AW_S32 type;               //!< 线段类型，参考\ref AW_AI_CVE_FLINE_TYPE
	AW_LINE_S ref_line;        //!< 线段坐标(unit: pixel)
	AW_S32 ref_length;			//!< 线段长度(unit: cm)
} AW_AI_CVE_FDZ_LINE;

#define AW_AI_CVE_MAXNUM_FDEPTH_LINE		8
//! 标定线段集合
typedef struct
{
	AW_S32 num_used;			//!< 有效线段数目
	AW_AI_CVE_FDZ_LINE lines[AW_AI_CVE_MAXNUM_FDEPTH_LINE]; //!< 线段数组
} AW_AI_CVE_FDZ_LINES;

//! 景深系数
//! resolv = cx * x + cy * y + cf, (unit: pixel/cm)
typedef struct
{
	AW_FLOAT cx;                   //!< 水平方向系数
	AW_FLOAT cy;                   //!< 竖直方向系数
	AW_FLOAT cf;                   //!< 偏置系数
} AW_AI_CVE_FDEPTH_COEF;

//! \ingroup group_clbr
//! 景深标定参数
typedef struct
{
    AW_S32 dim_w;              //!< 标定图像宽度
    AW_S32 dim_h;              //!< 标定图像高度
	AW_AI_CVE_FDZ_LINES fdlines;      //!< 标定数据
	AW_AI_CVE_FDEPTH_COEF coef;       //!< 景深系数
} AW_AI_CVE_CLBR_PARAM;

//! \ingroup group_clbr
//! \{

//! \brief 查询参数配置版本
//! \param pVersion     [out] 版本字符串，字符串缓冲区长度至少是32
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_CLBR_GetSceneVersion( AW_CHAR *pVersion );

//! \brief 将景深标定算法处理参数打包为XML文件
//! \param pParams      [in] 参数数据，参考\ref AW_AI_CVE_CLBR_PARAM
//! \param pFilNam      [in] XML文件名
//! \param pMemMgr      [in] 内存管理器，当前置为NULL
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_CLBR_PacketParamFile( AW_AI_CVE_CLBR_PARAM *pParams, AW_CHAR *pFilNam, AW_PVOID pMemMgr );
//! \brief 将景深标定算法处理参数打包为XML字符串
//! \param pParams      [in] 参数数据，参考\ref AW_AI_CVE_CLBR_PARAM
//! \param pBuffer      [out] XML字符串缓冲区
//! \param nBufLen      [in] 缓冲区长度
//! \param pMemMgr      [in] 内存管理器，当前置为NULL
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_CLBR_PacketParamString( AW_AI_CVE_CLBR_PARAM *pParams, AW_CHAR *pBuffer, AW_S32 nBufLen, AW_PVOID pMemMgr );

//! \brief 从XML文件解析景深标定算法处理参数
//! \param pFilNam      [in] XML文件名
//! \param pParams      [out] 参数数据，参考\ref AW_AI_CVE_CLBR_PARAM
//! \param pMemMgr      [in] 内存管理器，当前置为NULL
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_CLBR_ParseParamFile( AW_CHAR *pFilNam, AW_AI_CVE_CLBR_PARAM *pParams, AW_PVOID pMemMgr );

//! \brief 从XML字符串解析景深标定算法处理参数
//! \param pXmlString   [in] XML字符串
//! \param pParams      [out] 参数数据，参考\ref AW_AI_CVE_CLBR_PARAM
//! \param pMemMgr      [in] 内存管理器，当前置为NULL
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_CLBR_ParseParamString( AW_CHAR *pXmlString, AW_AI_CVE_CLBR_PARAM *pParams, AW_PVOID pMemMgr );

//! \brief 获取缺省参数字符串
//! \return             字符串指针
AW_CVE_EXPORTS AW_CHAR* AW_AI_CVE_CLBR_GetParamString();


//! \}


#ifdef __cplusplus
}
#endif


#endif  // __AW_AI_CVE_CLBR_CONFIG_H__
