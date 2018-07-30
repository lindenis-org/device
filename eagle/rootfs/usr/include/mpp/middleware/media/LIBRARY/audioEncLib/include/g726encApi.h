
#ifdef __cplusplus
extern "C" {
#endif

#ifndef __G726_ENC_LIB_API__
#define __G726_ENC_LIB_API__

#include <aenc_sw_lib.h>

extern struct __AudioENC_AC320 *AudioG726ENCEncInit();
extern int AudioG726ENCEncExit(struct __AudioENC_AC320 *p);

#endif // __G726_ENC_LIB_API__

#ifdef __cplusplus
}
#endif

