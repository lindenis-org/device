#ifndef CVE_TYPE
#define CVE_TYPE
typedef int CveTaskHandle;
typedef void					CVE_VOID;
typedef unsigned char			CVE_U8;
typedef unsigned short			CVE_U16;
typedef unsigned int			CVE_U32;
typedef signed char				CVE_S8;
typedef short					CVE_S16;
typedef int						CVE_S32;
typedef unsigned int			CVE_MEM_ADDR;

typedef unsigned char           CVE_U0Q8;
typedef unsigned char           CVE_U1Q7;
typedef unsigned char           CVE_U5Q3;
typedef unsigned short          CVE_U0Q16;
typedef unsigned short          CVE_U4Q12;
typedef unsigned short          CVE_U6Q10;
typedef unsigned short          CVE_U8Q8;
typedef unsigned short          CVE_U14Q2;
typedef unsigned short          CVE_U12Q4;
typedef short                   CVE_S14Q2;
typedef short                   CVE_S9Q7;
typedef short                   CVE_S1Q15;
typedef unsigned int            CVE_U22Q10;
typedef unsigned int            CVE_U25Q7;
typedef int                     CVE_S25Q7;
typedef int                     CVE_S16Q16;

typedef unsigned char           BYTE;
typedef unsigned long           DWORD;

#define CVE_OK			0

#define CVE_CMD_Resize			 0x00
#define CVE_CMD_Integral		 0x01
#define CVE_CMD_Filter			 0x02//模板滤波
#define CVE_CMD_Erode			 0x03//腐蚀
#define CVE_CMD_Dilate			 0x04//膨胀
#define CVE_CMD_Thresh			 0x05//图像阈值化
#define CVE_CMD_CCL				 0x06//连通区域标记
#define CVE_CMD_GradXY			 0x07//梯度计算
#define CVE_CMD_RegionFg		 0x08//区域前景计算
#define CVE_CMD_DilateBitOnce	 0x09//按数据位形态学膨胀图像一次
#define CVE_CMD_DilateBitTwice	 0x0A//按数据位形态学膨胀图像两次次
#define CVE_CMD_CloneByBit		 0x0B//按数据位复制图像
#define CVE_CMD_RgsRectFill		 0x0C//区域矩形填充
#define CVE_CMD_BgGradMask		 0x0D//梯度背景更新
#define CVE_CMD_MultiLayerBgLearning	0x0E//背景匹配算子
#define CVE_CMD_MultiLayerBgUpdating	0x0F//背景更新算子
#define CVE_CMD_TextureStat		 0x10//生成纹理图
#define CVE_CMD_GetAvegray		 0x11//灰度图区域均值算子
#define CVE_CMD_LineDilateX		 0x12//X方向线膨胀
#define CVE_CMD_LineDilateY		 0x13//Y方向线膨胀
#define CVE_CMD_LineCorrodeX	 0x14//X方向线腐蚀
#define CVE_CMD_LineCorrodeY	 0x15//Y方向线腐蚀
#define CVE_CMD_AreaStatBinary	 0x16//局部二值化算子
#define CVE_CMD_GetStrokeWidth	 0x17//笔画宽度统计算子
#define CVE_CMD_StrokeFeature	 0x18//笔画增强算子
#define CVE_CMD_ImageRectify	 0x19//图像旋转算子
#define CVE_CMD_PlateBoundary	 0x1A//图像边界估计算子
#define CVE_CMD_RadonHor	     0x1B//水平方向Radon变换
#define CVE_CMD_RadonVer	     0x1C//竖直方向拉动变换
#define CVE_CMD_CharSegment	     0x1D//字符分割算子
#define CVE_CMD_Normalize	     0x1E//图像均衡化算子
#define CVE_CMD_GaborFeature	 0x1F//Gabor特征生成算子
#define CVE_CMD_AnnPredict	     0x20//卷积神经网络算子
#define CVE_CMD_CalDepth         0x21//深度信息算子

struct CveIonAddr{
	void* 	phy_Addr;
	void* 	mmu_Addr;
	void* 	ion_handle; // handle to the ion heap
	int 	fd; 		// file to the visual address
	unsigned int length;
};

//#define CVE_SW
#define CVE_HW

//#define CVE_DEBUG

#if 1

//Resize
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式

#ifdef CVE_HW
	CVE_MEM_ADDR src;
	CVE_MEM_ADDR dst; 
	CVE_MEM_ADDR roi;  //真实roi起点，1pixel对齐
	CVE_MEM_ADDR roi_8Align;		//8pixel对齐的roi起点
#endif // CVE_HW

#ifdef CVE_SW
	CVE_U8 *src;
	CVE_U8 *dst; 
	CVE_U8 *roi;	//真实roi起点，1pixel对齐
	CVE_U8 *roi_8Align;		//8pixel对齐的roi起点
#endif // CVE_SW

	//CVE_U8 roi_8Align;		//8pixel对齐的roi起点
	CVE_U8 roi_addrOffset;	//roi_8Align + roi_addrOffset = roi

	CVE_U16 src_width;
	CVE_U16 src_height;
	CVE_U16 src_stride;

	CVE_U16 roi_width;		//from roi
	CVE_U16 roi_width_plus;	//from roi_8Align
	CVE_U16 roi_height;
	CVE_U16 roi_stride;
	
	CVE_U16 dst_width;
	CVE_U16 dst_height;
	CVE_U16 dst_stride;

	CVE_U32 xSD;
	CVE_U32 ySD;
}CVEResizeData,*PCVEResizeData;

//Integral
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
#ifdef CVE_HW
	CVE_MEM_ADDR src;
	CVE_MEM_ADDR dst;
#endif // CVE_HW
#ifdef CVE_SW
	CVE_U8 *src;
	CVE_U32 *dst;
#endif // CVE_SW
	CVE_U16 width;
	CVE_U16	height;
	CVE_U16	src_stride;
	CVE_U16 dst_stride;
}CVEIntegralData,*PCVEIntegralData;

//Filter
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
#ifdef CVE_HW
	CVE_MEM_ADDR src; 
	CVE_MEM_ADDR dst;
#endif // CVE_HW
#ifdef CVE_SW
	CVE_U8 *src; 
	CVE_U8 *dst;
#endif // CVE_SW
	
	CVE_U8 mask[9];  //mask[9]
	CVE_U8 norm; 
	CVE_U16 stride;
	CVE_U16 width;
	CVE_U16 height;
}CVEFilterData,*PCVEFilterData;

//Erode
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
#ifdef CVE_HW
	CVE_MEM_ADDR src; 
	CVE_MEM_ADDR dst;
#endif // CVE_HW
#ifdef CVE_SW
	CVE_U8 *src; 
	CVE_U8 *dst;
#endif // CVE_SW

	//CVE_U8 *mask;// mask[9]; 
	CVE_U8 mask[9];// mask[9]; 

	CVE_U16 src_stride;
	CVE_U16 dst_stride;
	CVE_U16 width;
	CVE_U16 height;
}CVEErodeData,*PCVEErodeData;

//Dilate
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
#ifdef CVE_HW
	CVE_MEM_ADDR src; 
	CVE_MEM_ADDR dst;
#endif // CVE_HW
#ifdef CVE_SW
	CVE_U8 *src; 
	CVE_U8 *dst;
#endif // CVE_SW

	CVE_U8 mask[9];// mask[9]; 
	CVE_U16 src_stride;
	CVE_U16 dst_stride;
	CVE_U16 width;
	CVE_U16 height;

}CVEDilateData,*PCVEDilateData;

//Thresh
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式

	CVE_MEM_ADDR src;
	CVE_MEM_ADDR dst;

	CVE_U16 src_stride; 
	CVE_U16 dst_stride; 	
	CVE_U16 width;
	CVE_U16 height;
	CVE_U8 lowThr; 
	CVE_U8 highThr; 
	CVE_U8 maxValue;
	CVE_U8 minValue;
	CVE_U8 mode;
}CVEThreshData,*PCVEThreshData;

//CCL
////////////////////////////////////////////
// 区域集合
#ifndef CVE_LRG
#define CVE_LRG

#define MAX_LRGN_CNT 4096
// 标记的区域
typedef struct
{
	CVE_S16 lb_x, lb_y;	// 左上角坐标
	CVE_S16 ru_x, ru_y;	// 右下角坐标
} CVE_RECT;

typedef struct
{
	CVE_U16 used, sn;                   // 前景图像中属于此区域的像素的标记
	//CVE_U16 next, pre;                  // 邻接区域标记
	CVE_S16 lb_x, lb_y;                 // 区域矩形左上角坐标
	CVE_S16 ru_x, ru_y;                 // 区域矩形右下角坐标
	CVE_S32 area_pixel;                 // 区域面积
} LREGION;


typedef struct
{
	CVE_S32 max_used_idx;               // 被使用的元素的最大数组索引
	CVE_U8 indexs[MAX_LRGN_CNT];        // 索引数组
	CVE_U16 colors[MAX_LRGN_CNT];       // 标记数组
	CVE_S32 areas[MAX_LRGN_CNT];        // 面积数组


	CVE_MEM_ADDR hw_img_data08;                 // 图像数据
	CVE_MEM_ADDR hw_img_data16;                // 图像数据
	CVE_MEM_ADDR hw_drg;          // 区域数组,FPGA地址
	CVE_S16 img_w, img_h,stride;               // 图像高度和宽度

	//#ifdef CVE_CCL_SW
	//#ifdef CVE_SW
	CVE_U8 *img_data08;                 // 图像数据
	CVE_U16 *img_data16;                // 图像数据
	LREGION drg[MAX_LRGN_CNT];          // 区域数组
	//#endif
} LREGIONS;

#endif

typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
	LREGIONS *rgs;
	CVE_RECT *rc;
	CVE_S32 maxrcnt;
	CVE_S32 th_rarea;
}CVECCLData,*PCVECCLData;





////////////////////////////////////////////
//GradXY
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
#ifdef CVE_HW
	CVE_MEM_ADDR src; 
	CVE_MEM_ADDR dst;
#endif // CVE_HW
#ifdef CVE_SW
	CVE_U8 *src; 
	CVE_S8 *dst;
#endif // CVE_SW
	
	CVE_U16 src_stride;	
	CVE_U16 dst_stride; 
	CVE_U16 width; 
	CVE_U16 height;
}CVEGradXYData,*PCVEGradXYData;
//////////////////////////////////////////////
//RegionFg
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
#ifdef CVE_HW
	CVE_MEM_ADDR diffFg;
	CVE_MEM_ADDR curGrad;
	CVE_MEM_ADDR bgGrad;	
	CVE_MEM_ADDR GradFg;
#endif // CVE_HW
#ifdef CVE_SW
	CVE_S8 *diffFg;
	CVE_S8 *curGrad;	
	CVE_S8 *bgGrad;	
	CVE_U8 *GradFg;
#endif // CVE_SW

	CVE_U16 stride1;
	CVE_U16 stride2;
	CVE_U16 stride3; 
	CVE_U16 stride4;
	CVE_U16 width;
	CVE_U16 height;CVE_U8 mode;
	CVE_U16 edwFactor;
	CVE_U8 crlCoefThr; 
	CVE_U8 magCrlThr;
	CVE_U8 minMagDiff; 
	CVE_U8 noiseVal;
	CVE_U8 edwDark;
}CVERegionFgData,*PCVERegionFgData;

//DialteBitOnce
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
#ifdef CVE_HW
	CVE_MEM_ADDR src; 
	CVE_MEM_ADDR dst; 
#endif // CVE_HW
#ifdef CVE_SW
	CVE_U8 *src; 
	CVE_U8 *dst; 
#endif // CVE_SW

	CVE_U16 stride;
	CVE_U16 width;
	CVE_U16 height;
	CVE_U8 mask;
}CVEDilateBitOnceData,*PCVEDilateBitOnceData;

//DilateBitTwice
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
#ifdef CVE_HW
	CVE_MEM_ADDR src; 
	CVE_MEM_ADDR dst; 
	CVE_MEM_ADDR med; 
#endif // CVE_HW
#ifdef CVE_SW
	CVE_U8 *src; 
	CVE_U8 *dst; 
	CVE_U8 *med; 
#endif // CVE_SW

	CVE_U16 stride;
	CVE_U16 width;
	CVE_U16 img_h; 
	CVE_U8 mask; 
}CVEDilateBitTwiceData,*PCVEDilateBitTwiceData;

//CloneByBit
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
#ifdef CVE_HW
	CVE_MEM_ADDR src; 
	CVE_MEM_ADDR dst; 
#endif // CVE_HW
#ifdef CVE_SW
	CVE_U8 *src; 
	CVE_U8 *dst; 
#endif // CVE_SW

	CVE_U16 stride;
	CVE_U16 width;
	CVE_U16 height; 
	CVE_U8 mask;
}CVECloneByBitData,*PCVECloneByBitData;

//RgsRectFill
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
#ifdef CVE_HW
	CVE_MEM_ADDR fg;
	CVE_MEM_ADDR rcs; 
#endif // CVE_HW
#ifdef CVE_SW
	CVE_U8 *fg;	
	CVE_RECT *rcs; 
#endif // CVE_SW
	

	CVE_U16 stride;
	CVE_U16 img_w;
	CVE_U16 img_h; 
	CVE_U16 rcnt;
}CVERgsRectFillData,*PCVERgsRectFillData;

//BgGradMask
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
#ifdef CVE_HW
	CVE_MEM_ADDR fg_mask;
	CVE_MEM_ADDR in_grad;
	CVE_MEM_ADDR bg_grad; 
	CVE_MEM_ADDR l2_grad; 
#endif // CVE_HW
#ifdef CVE_SW
	CVE_U8 *fg_mask;
	CVE_S16 *in_grad;
	CVE_S16 *bg_grad; 
	CVE_S16 *l2_grad; 
#endif // CVE_SW
	
	CVE_U16 stride; 
	CVE_U16 width;
	CVE_U16 height;
}CVEBgGradMaskData,*PCVEBgGradMaskData;

//MultiLayerBgLearning
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
#ifdef CVE_HW
	CVE_MEM_ADDR curImg; 
	CVE_MEM_ADDR bgModel; 
	CVE_MEM_ADDR fgFlag; 
	CVE_MEM_ADDR matchFg;	
	CVE_MEM_ADDR diffFg; 
	CVE_MEM_ADDR statData; 
#endif // CVE_HW
#ifdef CVE_SW
	CVE_U8 *curImg; 
	CVE_VOID *bgModel; 
	CVE_U8 *fgFlag; 
	CVE_S8 *matchFg;	
	CVE_S8 *diffFg; 
	CVE_U8 *statData; 
#endif // CVE_SW

	CVE_U16 stride1; 
	CVE_U16 modelWidth;
	CVE_U16 stride2;
	CVE_U16 stride3; 
	CVE_U16 width; 
	CVE_U16 height; 
	CVE_U32 curFrmNum; 
	CVE_U32 preFrmNum; 
	CVE_U16 u16TimeThr; 
	CVE_U8 diffThrCrlCoef; 
	CVE_U8 diffMaxThr; 
	CVE_U8 diffMinThr;
	CVE_U8 diffThrInc; 
	CVE_U8 fastLearnRate; 
	CVE_U8 detChgRegion;
}CVEMultiLayerBgLearningData,*PCVEMultiLayerBgLearningData;

//MultiLayerBgUpdating
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
#ifdef CVE_HW
	CVE_MEM_ADDR bgModel; 
	CVE_MEM_ADDR fgFlag; 
	CVE_MEM_ADDR bgImg;
	CVE_MEM_ADDR chgStaImg;
	CVE_MEM_ADDR chgStaFg; 
	CVE_MEM_ADDR chgStaLife;
	CVE_MEM_ADDR statData;
#endif // CVE_HW
#ifdef CVE_SW
	CVE_VOID *bgModel; 
	CVE_U8 *fgFlag; 
	CVE_U8 *bgImg;
	CVE_U8 *chgStaImg;
	CVE_S8 *chgStaFg; 
	CVE_U16 *chgStaLife;
	CVE_U8 *statData;
#endif // CVE_SW

	CVE_U16 modelWidth; 
	CVE_U16 stride1; 
	CVE_U16 stride2; 
	CVE_U16 stride3; 
	CVE_U16 width;
	CVE_U16 height; 
	CVE_U32 curFrmNum; 
	CVE_U32 preChkTime; 
	CVE_U32 frmChkPeriod; 
	CVE_U32 initMinTime; 
	CVE_U32 styBgMinBlendTime;
	CVE_U32 styBgMaxBlendTime;
	CVE_U32 dynBgMinBlendTime; 
	CVE_U32 fgMaxFadeTime; 
	CVE_U32 bgMaxFadeTime; 
	CVE_U32 staticDetMinTime;
	CVE_U8 styBgAccTimeRateThr;
	CVE_U8 chgBgAccTimeRateThr;
	CVE_U8 dyngBgAccTimeThr; 
	CVE_U8 dynBgDepth; 
	CVE_U8 bgEffStaRateThr;
	CVE_U8 acceBgLearn;
	CVE_U8 detChgRegion;
}CVEMultiLayerBgUpdatingData,*PCVEMultiLayerBgUpdatingData;

/////////////////////////////////////////////////////////////////////////////
///车牌部分；

/////////////Part1:车牌定位


//
///////////Part2&3:字符分割 & 字符识别
//GaborFeature
typedef struct
{
	CVE_U8 gabor_phase;
	CVE_U8 stepx;
	CVE_U8 stepy;
	CVE_U8 gaborheight;
	CVE_U8 gaborwidth;
	CVE_U8 feature_width;
	CVE_U8 feature_height;
}CVE_GABORFEATURE_PARA_S;
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
	CVE_GABORFEATURE_PARA_S *gaborpara;
	CVE_U8 iWidth;
	CVE_U8 iHeight;
	CVE_U16 iFeatureStartIndex;

#ifdef CVE_HW
	CVE_MEM_ADDR pucImg;
	CVE_MEM_ADDR IntArrayGaborKernelReal;
	CVE_MEM_ADDR IntArrayGaborKernelImag;
	CVE_MEM_ADDR IntArrayFeature;
#endif

#ifdef CVE_SW
	CVE_U8* pucImg;
	CVE_S32 * IntArrayGaborKernelReal;
	CVE_S32 * IntArrayGaborKernelImag;
	CVE_S32 * IntArrayFeature;	
#endif

}CVEGaborFeatureData,*PCVEGaborFeatureData;

//Normalize
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
	CVE_U16 fixvar;
	CVE_U16 fixmean;
	CVE_U16 imgwidth;
	CVE_U16 imgheight;

#ifdef CVE_HW
	CVE_MEM_ADDR imgin;
	CVE_MEM_ADDR imgout;
#endif

#ifdef	CVE_SW
	CVE_U8 *imgin;
	CVE_U8 *imgout;
#endif
	
}CVENormalizeData,*PCVENormalizeData;

//PlateBoundary
typedef struct
{	
	CVE_S16 s16Left;            //!< letf x
	CVE_S16 s16Top;             //!< top y
	CVE_S16 s16Right;           //!< right x
	CVE_S16 s16Bottom;          //!< bottom y
}CVE_RECT_S;
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
	CVE_U16 stride;
	CVE_U16 subimgwidth;
	CVE_U16 subimgheight;
	CVE_U16 lengthrate;
	CVE_U16 maxhisrate;
	CVE_U32 divw3h3;

#ifdef CVE_HW
	CVE_MEM_ADDR srcimg;
	CVE_MEM_ADDR boundaryrect;
#endif
	
#ifdef CVE_SW
	CVE_U8* srcimg;
	CVE_RECT_S *boundaryrect;
#endif
	
}CVEPlateBoundaryData,*PCVEPlateBoundaryData;

//RadonHor
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
	CVE_U16 stride1;
	CVE_U16 stride2;
	CVE_U16 width;
	CVE_U16 height;
	CVE_S8 thetamin;
	CVE_S8 thetamax;
	CVE_U8 thr;

#ifdef CVE_HW
	CVE_MEM_ADDR src;
	CVE_MEM_ADDR dst;
#endif

#ifdef CVE_SW
	CVE_U8* src;
	CVE_U16* dst;
#endif
	
}CVERadonHorData,*PCVERadonHorData;

//RadonVer
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
	CVE_U16 stride1;
	CVE_U16 stride2;
	CVE_U16 width;
	CVE_U16 height;
	CVE_S8 thetamin;
	CVE_S8 thetamax;
	CVE_U8 thr;

#ifdef CVE_HW
	CVE_MEM_ADDR src;
	CVE_MEM_ADDR dst;
#endif

#ifdef CVE_SW
	CVE_U8* src;
	CVE_U16* dst;
#endif
}CVERadonVerData,*PCVERadonVerData;

//StrokeFeature
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
	CVE_U16 stride1;
	CVE_U16 stride2;
	CVE_U16 stride3;
	CVE_U16 width;
	CVE_U16 height;
	CVE_S8* realMask;
	CVE_S8* magicMask;
	CVE_U8 mode;

#ifdef CVE_HW
	CVE_MEM_ADDR src;
	CVE_MEM_ADDR realDst;
	CVE_MEM_ADDR magicDst;
#endif

#ifdef CVE_SW
	CVE_U8* src;
	CVE_U8* realDst;
	CVE_U8* magicDst;
#endif

}CVEStrokeFeatureData,*PCVEStrokeFeatureData;

//GetStrokeWidth
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
	CVE_U16 stride;
	CVE_U16 widht;
	CVE_U16 height;
	CVE_U8 thrld1;
	CVE_U8 thrld2;
	CVE_U8 maxstkwidth;

#ifdef CVE_HW
	CVE_MEM_ADDR src;
	CVE_MEM_ADDR widthweightW;
	CVE_MEM_ADDR widthweightB;
#endif
	
#ifdef CVE_SW
	CVE_U8* src;
	CVE_U32* widthweightW;
	CVE_U32* widthweightB;
#endif
}CVEGetStrokeWidthData,*PCVEGetStrokeWidthData;

//AnnPredict
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式

#ifdef CVE_HW
	CVE_MEM_ADDR src;
	CVE_MEM_ADDR table;
	CVE_MEM_ADDR weight;
	CVE_MEM_ADDR weightLayerNum;
	CVE_MEM_ADDR dst;
	CVE_MEM_ADDR layerSize;
#endif // CVE_HW

#ifdef CVE_SW
	CVE_S16Q16 *src;
	CVE_S1Q15 *table;
	CVE_U8 *weight;
	CVE_U16 *weightLayerNum;
	CVE_S16Q16 *dst;
	CVE_U16 *layerSize;
#endif // CVE_SW

	CVE_U16 tabSize;
	CVE_U32 weightSize;
	CVE_U8	layerNum;
	CVE_U16 maxCount;
	CVE_U8 activFuncMode;
	CVE_U8 tabInUpper;
	CVE_U8 tabInPreci;
	CVE_U8 tabOutNorm;
}CVEAnnPredictData,*PCVEAnnPredictData;

//ImageRectify
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
	CVE_U16 stride;
	CVE_U16 subimgwidth;
	CVE_U16 subimgheight;
	CVE_S16 sintheta;
	CVE_S16 costheta;
	CVE_S16 tanbeta;
	CVE_U8 rectifymode;
	CVE_S32 x0;
	CVE_S32 y0;

#ifdef CVE_HW
	CVE_MEM_ADDR srcimg;
	CVE_MEM_ADDR outimg;
#endif

#ifdef CVE_SW
	CVE_U8* srcimg;
	CVE_U8* outimg;
#endif
	
}CVEImageRectifyData,*PCVEImageRectifyData;


//CharSegment
#define CVE_MAX_CHAR_POS_NUM     26
#define CVE_PLATE_CHAR_NUM		12	

typedef struct
{
	CVE_S16		platelftmax;
	CVE_S16		platelftmin;	
	CVE_S16		platergtmax;	
	CVE_S16		platergtmin;	
	CVE_U16		fGapRate;	
	CVE_U16		fBigGap;
	CVE_U16		fEnegyRate;	
	CVE_U16		fInterRate;	
	CVE_U16		fBlockWeight[CVE_PLATE_CHAR_NUM];	
	CVE_U16		fInterWeight[CVE_PLATE_CHAR_NUM];
	CVE_U16		fAveRate[CVE_PLATE_CHAR_NUM];	
	CVE_U8		iCharNum;						
	CVE_U8		iGapIndex;		
	CVE_S8		su8WidStepMin;	
	CVE_S8		su8WidStepMax;							
	CVE_S8		su8OffsetMin;					
	CVE_S8		su8OffsetMax;								
	CVE_U8      au8Reserved[CVE_PLATE_CHAR_NUM];						
}CVE_PLATE_MODELINT;

typedef struct
{
	CVE_U16 u16CharPos[CVE_MAX_CHAR_POS_NUM];		
	CVE_S32 s32CharDis;							
	CVE_S16 s16PlateTrusty;						
	CVE_U8  u8PlateType;						 
}CVE_PLATE_CHAR_POS_OUT_S;

typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
	CVE_U16 stride;
	CVE_U16	width;
	//CVE_VOID *plateInfo;
	CVE_U16 tabCount;
	//CVE_VOID *charPos;
	CVE_U8 plateTypeNum;
	CVE_U16 rectX;
	CVE_U16 rectY;
	CVE_U16 rectWidth;
	CVE_U16 rectHeight;
	CVE_U16 hDiv3;

#ifdef CVE_HW
	CVE_MEM_ADDR table;
	CVE_MEM_ADDR enegyHist;
	CVE_MEM_ADDR plateInfo;
	CVE_MEM_ADDR charPos;
#endif

#ifdef CVE_SW
	CVE_U16* table;
	CVE_U32* enegyHist;
	CVE_VOID *charPos;
	CVE_VOID *plateInfo;
#endif
	
}CVECharSegmentData,*PCVECharSegmentData;

//TextureStat
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
#ifdef CVE_HW
	CVE_MEM_ADDR src;
	CVE_MEM_ADDR dst;
#endif // CVE_HW
#ifdef CVE_SW
	CVE_U8 *src;
	CVE_U8 *dst;
#endif // CVE_SW
	CVE_U16 width;
	CVE_U16	height;
	CVE_U16	src_stride;
	CVE_U16 dst_stride;
	CVE_U8 maxval;
	CVE_U8 minval;
}CVETextureStatData,*PCVETextureStatData;


//GetAvegray
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
#ifdef CVE_HW
	CVE_MEM_ADDR src;
	CVE_MEM_ADDR max_min_thr;
#endif // CVE_HW
#ifdef CVE_SW
	CVE_U8 *src;
	CVE_U32 *max_min_thr;	//低4byte存放max_thr，高4byte存放min_thr
#endif // CVE_SW
	CVE_U16 xstart;
	CVE_U16	xend;
	CVE_U16	ystart;
	CVE_U16 yend;

	CVE_U16 src_width;
	CVE_U16 src_height;
	CVE_U16 roi_width;
	CVE_U16 roi_height;
	CVE_U16 stride;
}CVEGetAvegrayData,*PCVEGetAvegrayData;


//LineDilateX
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式
	
#ifdef CVE_HW
	CVE_MEM_ADDR src;
#endif // CVE_HW

#ifdef CVE_SW
	CVE_U8 *src;
#endif // CVE_SW

	CVE_U16 width;
	CVE_U16 height;
	CVE_U16 stride;

	CVE_U8 gapMinLen;
	CVE_U8 densityThr;
	CVE_U8 horThr;
}CVELineDilateXData,*PCVELineDilateXData;

//LineDilateY
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式

#ifdef CVE_HW
	CVE_MEM_ADDR src;
	CVE_MEM_ADDR med;
	//CVE_U16 med_stride;
#endif // CVE_HW

#ifdef CVE_SW
	CVE_U8 *src;
#endif // CVE_SW

	CVE_U16 stride;
	CVE_U16 width;
	CVE_U16 height;
	CVE_U8 verThr;
}CVELineDilateYData,*PCVELineDilateYData;

//LineCorrodeX
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式

#ifdef CVE_HW
	CVE_MEM_ADDR src;
#endif // CVE_HW

#ifdef CVE_SW
	CVE_U8 *src;
#endif // CVE_SW
	CVE_U16 stride;
	CVE_U16 width;
	CVE_U16 height;
	CVE_U8 Thr;
}CVELineCorrodeXData,*PCVELineCorrodeXData;


//LineCorrodeY
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式

#ifdef CVE_HW
	CVE_MEM_ADDR src;
	CVE_MEM_ADDR med;
	//CVE_U16 med_stride;
#endif // CVE_HW

#ifdef CVE_SW
	CVE_U8 *src;
#endif // CVE_SW
	CVE_U16 stride;
	CVE_U16 width;
	CVE_U16 height;
	CVE_U8 Thr;
	CVE_U8 ThrMax;
}CVELineCorrodeYData,*PCVELineCorrodeYData;

//AreaStatBinary
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式

#ifdef CVE_HW
	CVE_MEM_ADDR src;
	CVE_MEM_ADDR integ;
	CVE_MEM_ADDR dst;
#endif // CVE_HW

#ifdef CVE_SW
	CVE_U8 *src;
	CVE_U32 *integ;
	CVE_U8 *dst;
#endif // CVE_SW

	CVE_U16 src_stride;
	CVE_U16 integ_stride;
	CVE_U16 dst_stride;
	CVE_U16 width;
	CVE_U16 height;
	CVE_U8 rateThr;
	CVE_U8 halfwx;
	CVE_U8 halfwy;
	CVE_U8 valthrld;

	CVE_U8 lowThr; 
	CVE_U8 highThr; 
	CVE_U8 maxValue;
	CVE_U8 minValue;
	CVE_U8 mode;
}CVEAreaStatBinaryData,*PCVEAreaStatBinaryData;

//CalDepth
typedef struct
{
	CVE_U16 cmd_id;
	CVE_U8 seq_mod; //连接模式

	CVE_MEM_ADDR srcLft;
	CVE_MEM_ADDR srcRgt;
	CVE_MEM_ADDR dstLft;
	CVE_MEM_ADDR dstRgt;
	CVE_MEM_ADDR cost;
	CVE_MEM_ADDR dstDeep;
	CVE_MEM_ADDR divisiontbl;

	CVE_U16 width;
	CVE_U16 height;
	CVE_U16 stride;
	CVE_U8 ftzero;
	CVE_U8 maxDisparity;
	CVE_U8 SADWindowSize;
	CVE_U8 textureThreshold;

	CVE_U8 uniquenessRatio; 
	CVE_U8 disp12MaxDiff; 
}CVECalDepthData,*PCVECalDepthData;

//DMA
typedef struct
{
	CVE_MEM_ADDR src;
	CVE_MEM_ADDR dst; 
	CVE_MEM_ADDR roi;				//真实roi起点，1pixel对齐
	//CVE_MEM_ADDR roi_8Align;		//8pixel对齐的roi起点

	//CVE_U8 roi_8Align;			//8pixel对齐的roi起点
	//CVE_U8 roi_addrOffset;			//roi_8Align + roi_addrOffset = roi

	CVE_U16 src_width;
	CVE_U16 src_height;
	CVE_U16 src_stride;

	CVE_U16 roi_width;				//from roi
	//CVE_U16 roi_width_plus;			//from roi_8Align
	CVE_U16 roi_height;
	CVE_U16 roi_stride;

	CVE_U16 dst_width;
	CVE_U16 dst_height;
	CVE_U16 dst_stride;

	CVE_U8 distance_w;
	CVE_U8 distance_h;
}CVEDMAData,*PCVEDMAData;

typedef struct
{
	CVE_U16  height;
	CVE_U16  width;
	CVE_U16  stride;
	CVE_U8   *sw_output;  //1280*720
}CVEswOutPut,*PCVEswOutPut;

#endif

#endif
