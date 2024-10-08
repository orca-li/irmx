#if !defined __IRMX_DISASM_H__
#define __IRMX_DISASM_H__

#include <mprimf.h>

struct STRUCT_IRMXD_T
{
    unsigned char endian;
    unsigned char capacity;
    char *archname;
};

struct STRUCT_IMRIXD_CONFIG
{
    char *archname;
    char *filename;
};

enum STATUS_irmx_et
irmxd_init(const char *src);
void irmxdmain(void);

extern pfcli_t irmxd_pfcli;
extern struct STRUCT_IMRIXD_CONFIG cfg_irmxd;

#endif /* __IRMX_DISASM_H__ */