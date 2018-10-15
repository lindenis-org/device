/*
 * Copyright(c) 2013-2016 Allwinnertech Co., Ltd.
 *
 *
 * For V5 ipc function code bonding api
 *
 */

#ifndef KFC_API_REL_H
#define KFC_API_REL_H

#define MAGIC_RET 0x50607080U
#define FF_MAGIC_1 0x26987452U /*0x01*/
#define FF_MAGIC_A10 0xA1074452U /*0x10*/
#define FF_MAGIC_B11 0xB1174258U/*0x11*/
#define FF_MAGIC_SERVER_DEAD 0xdeadbeefU /*server dead*/
#define FF_MAGIC_EXCEPTION 0xdeadeeeeU /*unknown err*/

#define MAX_MODULE_NUM 16
struct rsp_code_s {
	unsigned int mod[MAX_MODULE_NUM];
	unsigned int auth[MAX_MODULE_NUM];
	unsigned int rand[MAX_MODULE_NUM + 16];
	unsigned char veri[32];/*only 16bytes valid*/
} __attribute__((__packed__));

enum module_type {
	MODULE_CVE = 1000,
	MODULE_EVE,
	MODULE_ISE,
	MOUDLE_ISP,
	MODULE_VE,
	MODULE_EIS,
	MODULE_NUM
};

#ifdef __cplusplus
extern "C"{
#endif

extern int (*aw_kfcapi_comm_ckcfcc)(struct rsp_code_s* res, int module);

/*scramble head macro begin*/
#define SCRAMBLE_KFC_API_CHECK(module, cap) \
do { \
	struct rsp_code_s rsp_exp;\
	volatile int t = 0x12568741U;\
	volatile int tmp_ret = aw_kfcapi_comm_ckcfcc(&rsp_exp, (module));\
	cap = (tmp_ret^0x12568741U^t);\
} while (0);

#ifdef __cplusplus
}
#endif
/*scramble head macro end*/
#endif
