#ifndef __ANTISHAKE_HW__
#define __ANTISHAKE_HW__

//ref platform headers
#include <plat_defines.h>
#include <plat_errno.h>
#include <plat_math.h>
#include <plat_type.h>

//media api headers to app
#include <mm_common.h>
#include <mm_component.h>
#include <tmessage.h>
#include <tsemaphore.h>

#include "mm_comm_video.h"
//#include <mm_comm_region.h>
// GYRO data
#define MAX_GYRO_NUM 500
#define MAX_GYRO_BUF_LEN 2500 // 500 * 3 (a pkg have 3 float)

#define INV_ACCEL_X_RAW "/sys/devices/platform/soc/twi0/i2c-0/0-0068/iio:device0/in_accel_x_raw"
#define INV_ACCEL_Y_RAW "/sys/devices/platform/soc/twi0/i2c-0/0-0068/iio:device0/in_accel_y_raw"
#define INV_ACCEL_Z_RAW "/sys/devices/platform/soc/twi0/i2c-0/0-0068/iio:device0/in_accel_z_raw"

#define INV_ANGLVEL_X_RAW "/sys/devices/platform/soc/twi0/i2c-0/0-0068/iio:device0/in_anglvel_x_raw"
#define INV_ANGLVEL_Y_RAW "/sys/devices/platform/soc/twi0/i2c-0/0-0068/iio:device0/in_anglvel_y_raw"
#define INV_ANGLVEL_Z_RAW "/sys/devices/platform/soc/twi0/i2c-0/0-0068/iio:device0/in_anglvel_z_raw"
#define INV_ACCEL_ANGLVEL_RAW "/sys/devices/platform/soc/twi0/i2c-0/0-0068/iio:device0/in_accel_anglvel_raw"

#define INV_ACCEL_SCALE "/sys/devices/platform/soc/twi0/i2c-0/0-0068/iio:device0/in_accel_scale"


// MACRO:: Display the file name where errors occur.
#ifndef __FNAME__
	#define __FNAME__ (strrchr(__FILE__, '/') ? \
	strrchr(__FILE__, '/') + 1 : __FILE__)
#endif
// MACRO:: Check for ViSta Errors
#define __CHECK_FOR_VISTA_ERROR__ \
	if (retInfo->id != 0) { \
		printf("\nErrors captured: ------- [%s: %i] ----------------------- %s\n", \
		__FNAME__,__LINE__, IRIDALABS_ViSta_Errors()); \
		return -1; \
	}
// MACRO:: Check for ViSta Errors inside the Thread function
#define __CHECK_FOR_VISTA_ERROR_THREAD__ \
	if (retInfo->id != 0) { \
		printf("\nErrors captured: ------- [%s: %i] ----------------------- %s\n", \
		__FNAME__,__LINE__, IRIDALABS_ViSta_Errors());\
	}

// Time utils
#define TIME_INIT_START_END(x) static struct timeval start_##x; \
                       static struct timeval end_##x; \
                       static float DiffTime_##x;
#define TIME_GET_START(x) (gettimeofday(&start_##x, NULL))
#define TIME_GET_END(x) (gettimeofday(&end_##x, NULL)); \
                (DiffTime_##x = \
                (((end_##x.tv_sec + end_##x.tv_usec * 1e-6) - \
                (start_##x.tv_sec + start_##x.tv_usec * 1e-6)) * 1000))
#define TIME_PRINT_DIFF(x) (DiffTime_##x)

// gyro
typedef struct __gyro_t
{
    unsigned int gyro_num;
    float *gyro_xyz;
    size_t frameid;
    unsigned int t_time; // default value = 0;
    uint64_t *gyro_mpts;
    struct list_head mList;
} gyro_t ;

typedef struct __gyro_grp_list_t
{
    struct list_head idle_list;
    struct list_head ready_list;
} gyro_grp_list_t;

// video input & output
typedef struct __video_stabilization_frame_t
{
    VIDEO_FRAME_S VFrame;
    //unsigned int mPoolId;
    unsigned int mId;   //id identify frame uniquely
    struct list_head mList;
} video_stabilization_frame_t;

// video input
typedef struct __video_input_list_t
{
    struct list_head idle_list;
    struct list_head ready_list;
} video_input_list_t;

// video stabilizztion (video output)
typedef struct __video_stabilization_list_t
{
    struct list_head idle_list;
    struct list_head ready_list;
    struct list_head used_list;
} video_stabilization_list_t;

typedef struct __video_stabilization_t
{
	int 							stabilization_mode;
	int 							fps;
    // gyro
    gyro_t                          gyro;
    gyro_grp_list_t                 gyro_list;
    pthread_mutex_t                 gyro_mutex;

    // video frame info management
    int                             intput_bufs_num;
    int                             frame_width_stride;
    int                             frame_height_stride;
    video_stabilization_frame_t     video_input;
    video_input_list_t              video_input_list;
    pthread_mutex_t                 video_input_mutex;

    // video stabilizztion output
    int                             output_bufs_num;
    video_stabilization_frame_t     video_stabilization; // output attr
    video_stabilization_list_t      video_stabilization_list;
    pthread_mutex_t                 video_stabilization_mutex;

    cdx_sem_t sync_exit;
    cdx_sem_t gyro_exit; // sync for gyro thread
    cdx_sem_t stbl_exit; // sync for video stabilization thread

    pthread_barrier_t thd_bar;
} video_stabilization_t;

int ReadGyroScaleValue(const char *filename, float *scale);
int ReadVGropyValue(const char *filename, float *fx, float *fy, float *fz, float accel_scale, float angle_scale);
int video_stabilization_destory_gyro(video_stabilization_t *video_stabilization);
int video_stabilization_destory_fin_fout_queue(video_stabilization_t *video_stabilization);
int video_stabilization_create(video_stabilization_t *video_stabilization);

#endif
