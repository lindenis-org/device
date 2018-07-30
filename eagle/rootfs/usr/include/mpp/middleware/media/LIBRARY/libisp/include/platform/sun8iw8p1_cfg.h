
/*
 ******************************************************************************
 *
 * sun8iw8p1_cfg.h
 *
 * Hawkview ISP - sun8iw8p1_cfg.h module
 *
 * Copyright (c) 2016 by Allwinnertech Co., Ltd.  http://www.allwinnertech.com
 *
 * Version		  Author         Date		    Description
 *
 *   3.0		  Yang Feng   	2016/04/20	VIDEO INPUT
 *
 *****************************************************************************
 */
#ifndef _SUN8IW8P1_CFG_H_
#define _SUN8IW8P1_CFG_H_

//stat size configs

#define ISP_STAT_TOTAL_SIZE         0x2100

#define ISP_STAT_HIST_MEM_SIZE      0x0200
#define ISP_STAT_AE_MEM_SIZE        0x0600
#define ISP_STAT_AWB_MEM_SIZE       0x0200
#define ISP_STAT_AF_MEM_SIZE        0x0500
#define ISP_STAT_AFS_MEM_SIZE       0x0200
#define ISP_STAT_AWB_WIN_MEM_SIZE   0x1000

#define ISP_STAT_HIST_MEM_OFS       0x0
#define ISP_STAT_AE_MEM_OFS         (ISP_STAT_HIST_MEM_OFS + ISP_STAT_HIST_MEM_SIZE)
#define ISP_STAT_AWB_MEM_OFS        (ISP_STAT_AE_MEM_OFS   + ISP_STAT_AE_MEM_SIZE)
#define ISP_STAT_AF_MEM_OFS         (ISP_STAT_AWB_MEM_OFS  + ISP_STAT_AWB_MEM_SIZE)
#define ISP_STAT_AFS_MEM_OFS        (ISP_STAT_AF_MEM_OFS   + ISP_STAT_AF_MEM_SIZE)
#define ISP_STAT_AWB_WIN_MEM_OFS    (ISP_STAT_AFS_MEM_OFS   + ISP_STAT_AFS_MEM_SIZE)

//table size configs

#define ISP_LINEAR_LUT_LENS_GAMMA_MEM_SIZE 0xE00
#define ISP_LUT_MEM_SIZE            0x0
#define ISP_LENS_MEM_SIZE           0x0600
#define ISP_GAMMA_MEM_SIZE          0x0200
#define ISP_LINEAR_MEM_SIZE          0x0600

#define ISP_DRC_DISC_MEM_SIZE            0x0600
#define ISP_DRC_MEM_SIZE            0x0200
#define ISP_DISC_MEM_SIZE          0x0400

#define ISP_REG_SIZE                0x1000
#define ISP_LOAD_REG_SIZE           0x1000
#define ISP_SAVED_REG_SIZE          0x1000

#define MAX_CH_NUM      4
#define MAX_INPUT_NUM   2     //the maximum number of device connected to the same bus
#define MAX_ISP_STAT_BUF  5   //the maximum number of isp statistic buffer
#define MAX_SENSOR_DETECT_NUM  3   //the maximum number of detect sensor on the same bus.

#define MAX_AF_WIN_NUM 1
#define MAX_AE_WIN_NUM 1

#endif /*_SUN8IW8P1_CFG_H_*/

