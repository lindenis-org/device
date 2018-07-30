
#ifdef __cplusplus
extern "C" {
#endif

#ifndef __G711_ENC_LIB_API__
#define __G711_ENC_LIB_API__

#include <aenc_sw_lib.h>

extern struct __AudioENC_AC320 *AudioG711ENCEncInit();
extern int AudioG711ENCEncExit(struct __AudioENC_AC320 *p);

#endif // __G711_ENC_LIB_API__

#ifdef __cplusplus
}
#endif

