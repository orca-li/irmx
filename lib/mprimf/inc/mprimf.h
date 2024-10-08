#if !defined __IRMX_MPRIMF_H__
#define __IRMX_MPRIMF_H__

#include <stdlib.h>

#define PXF_LITTLE_ENDIAN 'L'
#define PXF_MIDDLE_ENDIAN 'M'
#define PXF_BIG_ENDIAN 'B'

#define PXF_1ST_BYTE_MSK(_type) (_type)(0x00000000000000FFu)
#define PXF_BITSLEN_BYTE 8
#define PXF_SHIFT_BY_N_BYTE(_nbyte) ((_nbyte) * PXF_BITSLEN_BYTE)

enum STATUS_irmx_et
{
    irmxFAIL,
    irmxOK,
    irmxTRUE,
    irmxFALSE,
};

typedef struct X_MPRIMF_CLIENT
{
    char *buf;
    char *basebuf;
    size_t szbuf;
} pfcli_t;

struct X_MPRIMF_FLAGS
{
    unsigned char test;
};

struct itempcfg_t
{
    unsigned char base;
    char type;
    unsigned char indent;
};

struct X_MPRIMF
{
    struct X_MPRIMF_FLAGS flags;
};

enum STATUS_irmx_et pf_ftobuf(char *filename, pfcli_t *pfcli);
void pf_get_item(char *header, const void *item);

extern struct itempcfg_t itempcfg;
extern struct X_MPRIMF mprimf;

#endif /* __IRMX_MPRIMF_H__ */