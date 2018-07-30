#ifndef __AMRNB_ENCODER_H__
#define __AMRNB_ENCODER_H__

enum AMRNB_BAND_MODE
{
    MR475 = 0,/* 4.75 kbps */
    MR515,    /* 5.15 kbps */
    MR59,     /* 5.90 kbps */
    MR67,     /* 6.70 kbps */
    MR74,     /* 7.40 kbps */
    MR795,    /* 7.95 kbps */
    MR102,    /* 10.2 kbps */
    MR122,    /* 12.2 kbps */
    MRDTX,    /* DTX       */
    N_MODES   /* Not Used  */
};

extern void *amrnbEncodeInit(int enableDtx);
extern void amrnbEncodeExit(void *enc);
extern int amrnbEncode(void *enc, int mode, short *pInput, uint8_t *pOutput);

#endif /* __AMRNB_ENCODER_H__ */

