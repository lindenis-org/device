
/*
 ******************************************************************************
 *
 * bsp_isp.h
 *
 * Hawkview ISP - bsp_isp.h module
 *
 * Copyright (c) 2016 by Allwinnertech Co., Ltd.  http://www.allwinnertech.com
 *
 * Version		  Author         Date		    Description
 *
 *   3.0		  Yang Feng   	2016/03/31	VIDEO INPUT
 *
 *****************************************************************************
 */

#ifndef __BSP__ISP__H
#define __BSP__ISP__H

#include "isp_comm.h"

#define MAX_ISP_SRC_CH_NUM 3

struct isp_table_addr {
	void            *isp_def_lut_tbl_vaddr;
	void            *isp_def_lut_tbl_paddr;
	void            *isp_def_lut_tbl_dma_addr;
	void            *isp_lsc_tbl_vaddr;
	void            *isp_lsc_tbl_paddr;
	void            *isp_lsc_tbl_dma_addr;
	void            *isp_gamma_tbl_vaddr;
	void            *isp_gamma_tbl_paddr;
	void            *isp_gamma_tbl_dma_addr;
	void            *isp_linear_tbl_vaddr;
	void            *isp_linear_tbl_paddr;
	void            *isp_linear_tbl_dma_addr;

	void            *isp_drc_tbl_vaddr;
	void            *isp_drc_tbl_paddr;
	void            *isp_drc_tbl_dma_addr;
	void            *isp_disc_tbl_vaddr;
	void            *isp_disc_tbl_paddr;
	void            *isp_disc_tbl_dma_addr;
};

void bsp_isp_init_platform(unsigned int platform_id);


#endif //__BSP__ISP__H
