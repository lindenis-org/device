
#ifdef __cplusplus
extern "C" {
#endif

#ifndef __ADPCM_ENC_LIB_API__
#define __ADPCM_ENC_LIB_API__

#include <aenc_sw_lib.h>

extern struct __AudioENC_AC320 *AudioADPCMENCEncInit();
extern int AudioADPCMENCEncExit(struct __AudioENC_AC320 *p);

#endif // __ADPCM_ENC_LIB_API__

#ifdef __cplusplus
}
#endif

