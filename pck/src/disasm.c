#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <disasm.h>
#include <parser.h>

#define get_capacity(_type) (sizeof(_type) * 8)

struct STRUCT_IMRIXD_CONFIG cfg_irmxd = {
    .archname = NULL,
    .filename = NULL,
};

static struct STRUCT_IRMXD_T irmxd = {
    .capacity = 0,
    .endian = 0,
    .archname = NULL,
};

pfcli_t irmxd_pfcli = {
    .szbuf = 0,
    .buf = NULL,
    .basebuf = NULL,
};

static enum STATUS_irmx_et
irmxd_arch_init(const char *arch)
{
    static char archname[64];
    sprintf(archname, "%s", arch);

    if (strcmp("arm", arch) == 0)
    {
        irmxd.capacity = get_capacity(bitstr32_t);
        irmxd.endian = PXF_LITTLE_ENDIAN;
        irmxd.archname = archname;
        return irmxOK;
    }

    if (strcmp("test-little64", arch) == 0)
    {
        irmxd.capacity = get_capacity(bitstr64_t);
        irmxd.endian = PXF_LITTLE_ENDIAN;
        irmxd.archname = archname;
        return irmxOK;
    }

    if (strcmp("test-big64", arch) == 0)
    {
        irmxd.capacity = get_capacity(bitstr64_t);
        irmxd.endian = PXF_BIG_ENDIAN;
        irmxd.archname = archname;
        return irmxOK;
    }

    if (strcmp("test-little32", arch) == 0)
    {
        irmxd.capacity = get_capacity(bitstr32_t);
        irmxd.endian = PXF_LITTLE_ENDIAN;
        irmxd.archname = archname;
        return irmxOK;
    }

    if (strcmp("test-big32", arch) == 0)
    {
        irmxd.capacity = get_capacity(bitstr32_t);
        irmxd.endian = PXF_BIG_ENDIAN;
        irmxd.archname = archname;
        return irmxOK;
    }

    if (strcmp("test-little16", arch) == 0)
    {
        irmxd.capacity = get_capacity(bitstr16_t);
        irmxd.endian = PXF_LITTLE_ENDIAN;
        irmxd.archname = archname;
        return irmxOK;
    }

    if (strcmp("test-big16", arch) == 0)
    {
        irmxd.capacity = get_capacity(bitstr16_t);
        irmxd.endian = PXF_BIG_ENDIAN;
        irmxd.archname = archname;
        return irmxOK;
    }

    if (strcmp("test-little8", arch) == 0)
    {
        irmxd.capacity = get_capacity(bitstr8_t);
        irmxd.endian = PXF_LITTLE_ENDIAN;
        irmxd.archname = archname;
        return irmxOK;
    }

    if (strcmp("test-big8", arch) == 0)
    {
        irmxd.capacity = get_capacity(bitstr8_t);
        irmxd.endian = PXF_BIG_ENDIAN;
        irmxd.archname = archname;
        return irmxOK;
    }

    return irmxFAIL;
}

enum STATUS_irmx_et
irmxd_init(const char *src)
{
    int i;
    char arch[32];

    if (src != NULL)
    {
        strcpy(arch, src);
    }
    else
    {
        strcpy(arch, "arm");
    }

    for (i = 0; arch[i]; i++)
    {
        arch[i] = tolower(arch[i]);
    }

    if (irmxd_arch_init(arch))
    {
        return irmxOK;
    }
    return irmxFAIL;
}

static void
check_memory_and_pointers(void)
{
    /* POINTERS CHECK SECTION BEGIN */
    /* POINTERS CHECK SECTION END */

    /* CONFIGURATION SECTION BEGIN */
    /* CONFIGURATION SECTION END */

    /* INITIALIZATION SECTION BEGIN */
    /* INITIALIZATION SECTION END */

    /* CODE SECTION BEGIN */
    /* CODE SECTION END */

    /* CODE SECTION BEGIN */
    /* CODE SECTION END */

    /* RETURN SECTION BEGIN */
    /* RETURN SECTION END */
}

static void
free_memory(void)
{
    /* POINTERS CHECK SECTION BEGIN */
    /* POINTERS CHECK SECTION END */

    /* CONFIGURATION SECTION BEGIN */
    /* CONFIGURATION SECTION END */

    /* INITIALIZATION SECTION BEGIN */
    /* INITIALIZATION SECTION END */

    /* CODE SECTION BEGIN */
    /* CODE SECTION END */

    /* CODE SECTION BEGIN */
    /* CODE SECTION END */

    /* RETURN SECTION BEGIN */
    /* RETURN SECTION END */
}

static void
change_endian(bitstrl_t *bits)
{

    if (irmxd.capacity > get_capacity(bitstr8_t))
    {
        unsigned char i, hbyte;
        bitstrl_t bitstmp = 0;
        bitstrl_t pushbits = 0;

        hbyte = irmxd.capacity / PXF_BITSLEN_BYTE;

        for (i = 0; i < (hbyte / 2); i++)
        {
            bitstmp = ((*bits & (PXF_1ST_BYTE_MSK(bitstr_t) << PXF_SHIFT_BY_N_BYTE(i))) << PXF_SHIFT_BY_N_BYTE(hbyte - 1 - (i * 2))) | ((*bits & (PXF_1ST_BYTE_MSK(bitstr_t) << PXF_SHIFT_BY_N_BYTE(hbyte - 1 - i))) >> PXF_SHIFT_BY_N_BYTE(hbyte - 1 - (i * 2)));
            pushbits |= bitstmp;
        }
        *bits = pushbits;
    }
}

static bitstrl_t
get_instbits(void)
{
    bitstrl_t bits = 0u;
    unsigned char i, szinst;

    szinst = irmxd.capacity / PXF_BITSLEN_BYTE;
    for (i = 0; i < szinst; i++)
    {
        bits >>= PXF_BITSLEN_BYTE;
        bits |= ((bitstrl_t)((bitstr8_t)*irmxd_pfcli.buf++)) << ((szinst - 1) * PXF_BITSLEN_BYTE);
    }

    if (irmxd.endian == PXF_BIG_ENDIAN)
    {
        change_endian(&bits);
    }

    return bits;
}

static void
test_arch(void)
{
    /* POINTERS CHECK SECTION BEGIN */
    if(irmxd.archname == NULL)
    {
        fprintf(stderr, "irmxd.arhcname (null)\n");
        exit(1);
    }
    /* POINTERS CHECK SECTION END */

    /* CONFIGURATION SECTION BEGIN */
    /* CONFIGURATION SECTION END */

    /* INITIALIZATION SECTION BEGIN */
    /* INITIALIZATION SECTION END */

    /* CODE SECTION BEGIN */
    itempcfg.type = 's';
    pf_get_item("Architecture", irmxd.archname);

    itempcfg.type = 'd';
    itempcfg.base = 8;
    pf_get_item("Capacity", &irmxd.capacity);
    itempcfg.base = 64;
    pf_get_item("Bytes read", &irmxd_pfcli.szbuf);
    /* CODE SECTION END */

    /* MEMORY RELEASE SECTION BEGIN */
    /* MEMORY RELEASE SECTION END */

    /* RETURN SECTION BEGIN */
    /* RETURN SECTION END */
}

static void
test_endians(void)
{
    /* POINTERS CHECK SECTION BEGIN */
    if (irmxd_pfcli.buf == NULL)
    {
        fprintf(stderr, "irmxd_pfcli (null)");
        exit(1);
    }
    /* POINTERS CHECK SECTION END */

    /* CONFIGURATION SECTION BEGIN */
    /* CONFIGURATION SECTION END */

    /* INITIALIZATION SECTION BEGIN */
    char *pbits;
    /* INITIALIZATION SECTION END */

    /* CODE SECTION BEGIN */
    pbits = irmxd_pfcli.buf;

    itempcfg.type = 's';
    pf_get_item("Type-endian", irmxd.endian == PXF_LITTLE_ENDIAN ? "little-endian" : "big-endian");
    itempcfg.type = 'h';
    itempcfg.base = irmxd.capacity;
    pf_get_item("Input", pbits);
    bitstrl_t bits = get_instbits();
    pf_get_item("Endian", &bits);
    /* CODE SECTION END */

    /* MEMORY RELEASE SECTION BEGIN */
    /* MEMORY RELEASE SECTION END */

    /* RETURN SECTION BEGIN */
    irmxd_pfcli.buf = irmxd_pfcli.basebuf;
    /* RETURN SECTION END */
}

static void
test_main(void)
{
    int i;
    char *archs[] = {
        "arm",
        "test-little8",
        "test-little16",
        "test-little32",
        "test-little64",
        "test-big8",
        "test-big16",
        "test-big32",
        "test-big64",
    };

    for (i = 0; i < (sizeof(archs) / sizeof(char *)); i++)
    {
        if (irmxd_init(archs[i]) != irmxOK)
        {
            fprintf(stderr, "Unknown arch\n");
            exit(1);
        }
        test_arch();
        test_endians();
        putchar('\n');
    }
}

void irmxdmain(void)
{
    itempcfg.indent = 19;

    if (mprimf.flags.test == irmxTRUE)
    {
        test_main();
        return;
    }

    test_arch();
    test_endians();
    putchar('\n');
}