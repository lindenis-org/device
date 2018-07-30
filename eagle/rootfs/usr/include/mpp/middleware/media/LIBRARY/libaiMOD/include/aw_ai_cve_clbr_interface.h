/*! \file aw_ai_cve_clbr_interface.h
\brief aw_ai_cve_clbr_interface.h document.
*/

#ifndef _AW_AI_CVE_CLBR_INTERFACE_H_
#define _AW_AI_CVE_CLBR_INTERFACE_H_

#include "aw_ai_cve_base_type.h"
#include "aw_ai_cve_clbr_config.h"


#ifdef __cplusplus
extern "C"{
#endif


//! \ingroup group_clbr
//! \{

//! \brief 查询算法版本
//! \param pVersion     [out] 版本字符串，字符串缓冲区长度至少是32
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_CLBR_GetAlgoVersion( AW_CHAR *pVersion );

//! \brief 从标定数据计算景深系数
//! \param pParams      [in,out] 景深标定参数，参考\ref AW_AI_CVE_CLBR_PARAM
//! \param flag         [in] 计算模式，当前置为0
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_FDEPTH_Calculate( AW_AI_CVE_CLBR_PARAM *pParams, AW_U32 flag );

//! \brief 计算像素点分辨率
//! \param pParams      [in] 景深标定参数，参考\ref AW_AI_CVE_CLBR_PARAM
//! \param x            [in] 像素点X坐标
//! \param y            [in] 像素点Y坐标
//! \param res_x        [out] X方向分辨率，分辨率单位为cm/pixel，如果计算结果为0，表示此像素位置无效
//! \param res_y        [out] Y方向分辨率，分辨率单位为cm/pixel，如果计算结果为0，表示此像素位置无效
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_FDEPTH_GetPointResolution( AW_AI_CVE_CLBR_PARAM *pParams, AW_S32 x, AW_S32 y,
                                                         AW_DOUBLE *res_x, AW_DOUBLE *res_y );

//! \brief 计算线段长度
//! \param pParams      [in] 景深标定参数，参考\ref AW_AI_CVE_CLBR_PARAM
//! \param line         [in] 待计算线段，参考\ref AW_LINE_S
//! \param type         [in] 线段类型，参考\ref AW_AI_CVE_FLINE_TYPE
//! \param length       [out] 线段长度，单位为厘米，如果计算结果为0，表示此线段位置无效
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_FDEPTH_GetLineLength( AW_AI_CVE_CLBR_PARAM *pParams, AW_LINE_S *line,
                                                  AW_S32 type, AW_S32 *length );

//! \brief 从矩形面积和宽高比率计算矩形的宽度和高度
//! \param pParams      [in] 景深标定参数，参考\ref AW_AI_CVE_CLBR_PARAM
//! \param type         [in] 线段类型，参考\ref AW_AI_CVE_FLINE_TYPE
//! \param bpos			[out] 矩形位置
//! \param pwidth		[out] 矩形宽度
//! \param pheight		[out] 矩形高度
//! \return             操作状态，参考\ref AW_STATUS_E
AW_CVE_EXPORTS AW_STATUS_E AW_AI_CVE_FDEPTH_GetRectDimension( AW_AI_CVE_CLBR_PARAM *pParams, AW_S32 type, AW_POINT_S *bpos,
                                                     AW_DOUBLE area, AW_DOUBLE ratio, AW_S32 *pwidth, AW_S32 *pheight );

//! \}


#ifdef __cplusplus
}
#endif


#endif // _AW_AI_CVE_CLBR_INTERFACE_H_



