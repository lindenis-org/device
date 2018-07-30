/*
 * Copyright(c) 2013-2016 Allwinnertech Co., Ltd.
 *
 *		http://www.allwinnertech.com
 *		Author: Ryan <ryanchen@allwinnertech.com>
 *
 * Allwinner IP protction library
 *
 */

#ifndef __AW_DLFCN_H__
#define __AW_DLFCN_H__

#ifdef __cplusplus
extern "C" {
#endif

int aw_dlinit(const char *filename,const char *aes_opt, const char *aes_key, int aes_len ,\
				const char*rsa_file, const char *cid,const char *version);
void  *aw_dlopen(const char *, int);
void  *aw_dlsym(void *, const char *);
int    aw_dlclose(const char *,void *);
char  *aw_dlerror(void);
/*
*ip_path : the asb path of IP to be protected
*so_path: the abs path of so lib which provide the protection capbility
*/
int aw_dlinit_ext(const char *ip_path, const char *aes_opt,const char *aes_key, int aes_len ,
				const char*rsa_file, const char *cid,const char *version, const char* so_path);

/*
*ip_path : the asb path of IP to be protected
*so_path: the abs path of so lib which provide the protection capbility
*cli_tmpfs: allow user to assign the  abs path which the iploader server must have write auth
*/
int aw_dlinit_ext_131(const char *ip_path, const char *aes_opt,const char *aes_key, int aes_len ,
				const char*rsa_file, const char *cid,const char *version, const char* so_path,
				const char* cli_tmpfs);


#ifdef __cplusplus
}
#endif

#endif

