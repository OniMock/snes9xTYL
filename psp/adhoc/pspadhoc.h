#ifndef __pspadhoc_h__
#define __pspadhoc_h__

int adhocLoadDrivers(SceModuleInfo* modInfoPtr);
int psp_load_adhoc_drivers(void);
int adhocSelect(void);
int adhocTerm();
int adhocInit(char *MatchingData);
int adhocSendRecvAck(void *buffer, int length);
int adhocRecvSendAck(void *buffer, unsigned int *length);
int adhocSend(void *buffer, int length);
int adhocRecv(void *buffer, unsigned int *length);
int adhocRecvBlocked(void *buffer, unsigned int *length,int max_retry);

#endif
