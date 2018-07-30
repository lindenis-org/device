#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#define CVEMIDDLEWAREDLL_API

#ifdef __cplusplus
extern "C"{
#endif

CVEMIDDLEWAREDLL_API CVE_S32 CVE_InitModules(void);
CVEMIDDLEWAREDLL_API CVE_S32 CVE_ReleaseModules(void);
CVEMIDDLEWAREDLL_API CVE_S32 CVE_CreateTask(int command_num);
CVEMIDDLEWAREDLL_API CVE_S32 CVE_CreateCommand(CveTaskHandle task,int cmd_op,void* ptr_data,int seq_mod);
CVEMIDDLEWAREDLL_API CVE_S32 CVE_ExecuteTask(CveTaskHandle task,int runMode);
CVEMIDDLEWAREDLL_API CVE_S32 CVE_QueryTask(CveTaskHandle task);
CVEMIDDLEWAREDLL_API CVE_S32 CVE_DestoryTask(CveTaskHandle task);
CVEMIDDLEWAREDLL_API CVE_S32 CVE_Malloc( struct CveIonAddr* addr, unsigned long numOfBytes );
CVEMIDDLEWAREDLL_API CVE_S32 CVE_Free( struct CveIonAddr* addr );

CVEMIDDLEWAREDLL_API CVE_S32 CVE_MemCopyToDev(CVE_U32 data_size,void* ptr_src_addr,struct CveIonAddr* addr);
CVEMIDDLEWAREDLL_API CVE_S32 CVE_MemCopyFromDev(CVE_U32 data_size,struct CveIonAddr* addr,void* ptr_dst_addr);

CVEMIDDLEWAREDLL_API CVE_S32 CVE_DMA_Create(CVEDMAData *DMAData);
CVEMIDDLEWAREDLL_API CVE_S32 CVE_DMA_Execute(CVEDMAData *DMAData);

CVEMIDDLEWAREDLL_API CVE_U32 DEBUG_CVE_QueryTaskCycle();

//CVEMIDDLEWAREDLL_API CVE_S32 CVE_MemFlushCache(struct CveIonAddr* addr, CVE_U32 data_size);
CVEMIDDLEWAREDLL_API CVE_S32 CVE_MemFlushCache(CVE_U32 mmu_Addr, CVE_U32 data_size);
#ifdef __cplusplus
}
#endif
