
#ifdef __cplusplus
extern "C" {
#endif

#ifndef AUDIO_ENC_API_H
#define AUDIO_ENC_API_H

#include <aenc_sw_lib.h>

// 8k sample_rate with fifo=32  can cache 32*128ms = 4096ms
// 22.05k                   128          128*46.4ms = 5939ms
// 44.1k                    192          192*23.2ms = 4454ms
#define FIFO_LEVEL	(192)    // 32 -> 128 -> 192 for higher sample_rate

typedef enum AUDIO_ENCODER_TYPE
{
       AUDIO_ENCODER_AAC_TYPE,
       AUDIO_ENCODER_LPCM_TYPE,    //only used by mpeg2ts
       AUDIO_ENCODER_ADPCM_TYPE,
       AUDIO_ENCODER_PCM_TYPE,
       AUDIO_ENCODER_MP3_TYPE,
       AUDIO_ENCODER_AMRNB_TYPE,
       AUDIO_ENCODER_G711_TYPE,
       AUDIO_ENCODER_G726_TYPE,
}AUDIO_ENCODER_TYPE;

typedef struct AUDIOENCCONTENT_t
{
	void *priv_data;
	int (*RequestWriteBuf)(void *handle, void * pInbuf, int inSize);
	int (*AudioEncPro)(void *handle);
	int (*GetAudioEncBuf)(void *handle, void ** pOutbuf, unsigned int * outSize, long long * timeStamp, int* pBufId);
    int (*ReleaseAudioEncBuf)(void *handle, void* pOutbuf, unsigned int outSize, long long timeStamp, int nBufId);
    
    int (*GetValidPcmDataSize)(void *handle);
    int (*GetTotalPcmBufSize)(void *handle);
    int (*GetEmptyFrameNum)(void *handle);
    int (*GetTotalFrameNum)(void *handle);
}AUDIOENCCONTENT_t;

AUDIOENCCONTENT_t * AudioEncInit(__audio_enc_inf_t * audio_inf, int encode_type);
void AudioEncExit(void *handle);


#endif // AUDIO_ENC_API_H

#ifdef __cplusplus
}
#endif

