#ifndef _AW_AI_COMMON_TYPE_H
#define _AW_AI_COMMON_TYPE_H

#include "aw_type.h"
#include "mm_comm_video.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */


//base type
//----------------------------------------------
// The common data type, will be used in the whole project.
//----------------------------------------------
#if 0
typedef unsigned char           AW_U8;
typedef unsigned short          AW_U16;
typedef unsigned int            AW_U32;
typedef char                    AW_S8;
typedef short                   AW_S16;
typedef int                     AW_S32;
typedef float 					AW_FLOAT;
typedef char                    AW_CHAR;
typedef void*                   AW_HANDLE;
typedef void*                   AW_PVOID;
typedef double                  AW_DOUBLE;

#ifndef _M_IX86
    typedef unsigned long long  AW_U64;
    typedef long long           AW_S64;
#else
    typedef uint64_t            AW_U64;
    typedef int64_t             AW_S64;
#endif
#endif

#define   AW_NULL            0L
#define   AW_SUCCESS         0
#define   AW_FAILURE         (-1)
#define  AW_MAX_POLYGON_NUM  32 //max polygon nums
#define  AW_MAX_TRAJECT_LEN	 40 //max trajectory nums
#define  AW_MAX_TGT_NUM      64 //max target nums
#define  AW_MAX_EVE_TGT_NUM  128 //max eve target nums
#define  AW_MAX_BLOB_NUM     128  
#define  AW_MAX_ROI_NUM      8       //max roi number

//version 
#define AW_AI_VERSION_A( type1, type2, seri_m1, seri_m2, seri_s ) \
	( 0	\
	| ( (((AW_U32)type1)		& 0xFF) << 24 ) \
	| ( (((AW_U32)type2)		& 0xFF) << 16 ) \
	| ( (((AW_U32)seri_m1)		& 0x0F) << 12 ) \
	| ( (((AW_U32)seri_m2)		& 0x1F) << 7 ) \
	| ( (((AW_U32)seri_s)		& 0x7F) << 0 ) \
	)

#define AW_AI_VER_A_TYPE1( ver )		( (((AW_U32)ver)>>24)	& 0xFF )
#define AW_AI_VER_A_TYPE2( ver )		( (((AW_U32)ver)>>16)	& 0xFF )
#define AW_AI_VER_A_SER_M1( ver )		( (((AW_U32)ver)>>12)	& 0x0F )
#define AW_AI_VER_A_SER_M2( ver )		( (((AW_U32)ver)>>7)	& 0x1F )
#define AW_AI_VER_A_SER_S( ver )		( (((AW_U32)ver)>>0)	& 0x7F )

#if 0
//BOOL 
typedef enum {
    AW_FALSE = 0,
    AW_TRUE  = 1,
} AW_BOOL;
#endif

//Status
typedef enum
{
	AW_STATUS_ERROR = 0,                           //!< Error
	AW_STATUS_OK    = 1,                           //!< Ok
	AW_STATUS_SKIP  = 2,                           //!< Skip
}AW_STATUS_E;

#if 0
//image format
typedef enum PIXEL_FORMAT_E
{
    PIXEL_FORMAT_RGB_1BPP = 0,
    PIXEL_FORMAT_RGB_2BPP,
    PIXEL_FORMAT_RGB_4BPP,
    PIXEL_FORMAT_RGB_8BPP,
    PIXEL_FORMAT_RGB_444,

    PIXEL_FORMAT_RGB_4444,
    PIXEL_FORMAT_RGB_555,
    PIXEL_FORMAT_RGB_565,
    PIXEL_FORMAT_RGB_1555,

    /*  9 reserved */
    PIXEL_FORMAT_RGB_888,
    PIXEL_FORMAT_RGB_8888,

    PIXEL_FORMAT_RGB_PLANAR_888,
    PIXEL_FORMAT_RGB_BAYER_8BPP,
    PIXEL_FORMAT_RGB_BAYER_10BPP,
    PIXEL_FORMAT_RGB_BAYER_12BPP,
    PIXEL_FORMAT_RGB_BAYER_14BPP,

    PIXEL_FORMAT_RGB_BAYER,         /* 16 bpp */

    PIXEL_FORMAT_YUV_A422,
    PIXEL_FORMAT_YUV_A444,

    PIXEL_FORMAT_YUV_PLANAR_422,
    PIXEL_FORMAT_YUV_PLANAR_420,    //YU12

    PIXEL_FORMAT_YUV_PLANAR_444,

    PIXEL_FORMAT_YUV_SEMIPLANAR_422,    //NV16
    PIXEL_FORMAT_YUV_SEMIPLANAR_420,    //NV12
    PIXEL_FORMAT_YUV_SEMIPLANAR_444,

    PIXEL_FORMAT_UYVY_PACKAGE_422,
    PIXEL_FORMAT_YUYV_PACKAGE_422,
    PIXEL_FORMAT_VYUY_PACKAGE_422,
    PIXEL_FORMAT_YCbCr_PLANAR,

    PIXEL_FORMAT_SINGLE,

    PIXEL_FORMAT_YVU_PLANAR_420,    //YV12
    PIXEL_FORMAT_YVU_SEMIPLANAR_422,    //NV61
    PIXEL_FORMAT_YVU_SEMIPLANAR_420,    //NV21
    PIXEL_FORMAT_BUTT
} PIXEL_FORMAT_E;
#endif

//point
typedef struct _AW_POINT_S
{
	AW_S16  s16X;
	AW_S16  s16Y;
}AW_POINT_S, *lpAW_POINT_S;

//rectangle
typedef struct _AW_RECT_S
{
	AW_S16 s16Left;            //!< letf x
	AW_S16 s16Top;             //!< top y
	AW_S16 s16Right;           //!< right x
	AW_S16 s16Bottom;          //!< bottom y
}AW_RECT_S, *lpAW_RECT_S;

typedef struct _AW_BLOB_S
{
	AW_S16 s16X;            
	AW_S16 s16Y;             
	AW_S16 s16Width;           
	AW_S16 s16Height;          
}AW_BLOB_S, *lpAW_BLOB_S;

typedef struct _AW_BLOB_CONF_S
{
	AW_S16 s16X;            
	AW_S16 s16Y;             
	AW_S16 s16Width;           
	AW_S16 s16Height;
	AW_S16 s16Confidence;
	AW_S16 s16Scale;
}AW_BLOB_CONF_S, *lpAW_BLOB_CONF_S;

typedef struct _AW_BLOB_SET_S
{
	AW_S32 s32Num;
	AW_BLOB_S blob[AW_MAX_BLOB_NUM];        
}AW_BLOB_SET_S, *lpAW_BLOB_SET_S;

typedef struct _AW_SIZE_S
{
	AW_S16 s16Width;
	AW_S16 s16Height;
}AW_SIZE_S, *lpAW_SIZE_S;

//line 
typedef struct _AW_LINE_S
{
	AW_POINT_S  stPStart;
	AW_POINT_S  stPEnd;
}AW_LINE_S, *lpAW_LINE_S;

//polygon
typedef struct _AW_POLYGON_S
{
	AW_S32 s32Num;             //!< polygon point num
	AW_POINT_S astPoints[AW_MAX_POLYGON_NUM]; //!< polygon point array
}AW_POLYGON_S, *lpAW_POLYGON_S;

//trajectory
typedef struct _AW_TARGET_TRAJ_S
{
	AW_S32 length; 						//!< 轨迹长度
	AW_POINT_S points[AW_MAX_TRAJECT_LEN];//!< 轨迹点数组
} AW_TARGET_TRAJ_S, *lpAW_TARGET_TRAJ_S;

//image struct
typedef struct AW_IMAGE_S
{
	PIXEL_FORMAT_E  mPixelFormat;  //image pixel format, ref PIXEL_FORMAT_E
	AW_U32    mPhyAddr[3];  //physical address
	AW_PVOID  mpVirAddr[3]; //virtual  address
	AW_U32  mWidth;         //image wdith
	AW_U32  mHeight;        //image height
	AW_U32  mStride[3];     //image stride
}AW_IMAGE_S, *lpAW_IMAGE_S;

//classifier path struct
typedef struct _AW_CLSPATH_S
{
	AW_S8* path;	// path to classifier file
	AW_U8* key;		// the key of target file, used by decrypt function
}AW_CLSPATH_S;

//object define
typedef enum
{
	AW_TGT_TYPE_UNKNOWN			= 0,        //!< 未知
	AW_TGT_TYPE_HUMAN			= 1,        //!< 人
	AW_TGT_TYPE_VEHICLE			= 2         //!< 车
}AW_TGT_TYPE_E;

typedef struct
{
	AW_S32 length;							//!< 轨迹长度
	AW_POINT_S	points[AW_MAX_TRAJECT_LEN];//!< 轨迹点数组
} AW_TGT_TRAJECT_S;

//target
typedef struct _AW_TARGET_S
{
	AW_U32 u32ID;                          //!< 目标ID
	AW_S32 u32Type;                        //!< 目标类型，参考\ref AW_TGT_TYPE
	AW_POINT_S stPoint;                    //!< 目标位置
	AW_RECT_S stRect;                      //!< 目标矩形框
	AW_S32 s32AreaPix;                     //!< 目标面积(单位：像素)
	AW_S32 s32Area;                        //!< 目标面积(单位：平方厘米)
	AW_S32 s32Direct;                      //!< 运动方向(单位：角度)
	AW_FLOAT fSpeed;                       //!< 运动速度(单位：千米/小时)
	AW_TGT_TRAJECT_S stTraject;			   //!< 目标轨迹
} AW_TARGET_S, *lpAW_TARGET_S;

//target set
typedef struct _AW_TARGET_SET_S
{
	AW_S32 s32TargetNum;                    //!< 有效目标数目
	AW_TARGET_S astTargets[AW_MAX_TGT_NUM]; //!< 目标数组
}AW_TARGET_SET_S, *lpAW_TARGET_SET_S;

//target set
typedef struct _AW_EVETARGET_SET_S
{
	AW_S32 s32TargetNum;                    //!< 有效目标数目
	AW_TARGET_S astTargets[AW_MAX_EVE_TGT_NUM]; //!< 目标数组
}AW_EVETARGET_SET_S, *lpAW_EVETARGET_SET_S;

//roi set
typedef struct _AW_ROI_SET_S
{
	AW_S32     s32RoiNum;
	AW_S32     sID[AW_MAX_ROI_NUM];  //roi id
	AW_RECT_S  sRoi[AW_MAX_ROI_NUM]; //roi, support maximize 8 rois.
}AW_ROI_SET_S, *lpAW_ROI_SET_S;

//! \ingroup group_core
//! 事件状态
typedef enum
{
	AW_EVT_STATUS_NOSTA	= 0,                //!< 无状态
	AW_EVT_STATUS_START	= 1,                //!< 开始
	AW_EVT_STATUS_END	= 2                 //!< 结束
} AW_EVT_STATUS;

//event 
typedef struct _AW_EVENT_S
{
	AW_U32 u32Type;                        //!< 事件类型，参考\ref AW_EVT_TYPE
	AW_U32 u32ID;                          //!< 事件标识
	AW_U32 u32Status;                      //!< 事件状态，参考\ref AW_EVT_STATUS
	AW_U32 u32Zone;                        //!< 事件发生区域
	AW_U32 u32TgtID;                       //!< 目标标识
	AW_U8  u8Data[16];                     //!< 事件私有数据
}AW_EVENT_S, *lpAW_EVENT_S;

typedef struct _AW_EVENT_SET_S
{
	AW_S32	s32EventNum;                    //!< 有效事件数目
	AW_EVENT_S astEvents[AW_MAX_EVE_TGT_NUM];   //!< 事件数组
} AW_EVENT_SET_S, *lpAW_EVENT_SET_S;

//! system time definition
typedef struct _AW_SYSTEMTIME_S
{
	AW_U16 u16Year;								//!< year
	AW_U16 u16Month;								//!< month
	AW_U16 u16DayOfWeek;							//!< week
	AW_U16 u16Day;									//!< day
	AW_U16 u16Hour;								//!< hour
	AW_U16 u16Minute;								//!< minute
	AW_U16 u16Second;								//!< second
	AW_U16 u16Milliseconds;						//!< milliseconds
}AW_SYSTEMTIME_S, *lpAW_SYSTEMTIME_S;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
