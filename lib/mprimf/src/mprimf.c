#include <mprimf.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define PSEUDO_SZFILE 32

struct X_MPRIMF mprimf = {
    .flags = {
        .test = 0,
    },
};

struct itempcfg_t itempcfg = {
    .base = 0,
    .indent = 0,
    .type = 'v',
};

enum STATUS_irmx_et
pf_ftobuf(char *filename, pfcli_t *pfcli)
{
    FILE *hfile;
    size_t sfile;

    if (pfcli == NULL)
    {
        fprintf(stderr, "pfcli: (null)\n");
        exit(1);
    }

    if (filename == NULL)
    {
        hfile = fopen("", "r");
    }
    else
    {
        hfile = fopen(filename, "r");
    }

    if (hfile == NULL)
    {
        if (mprimf.flags.test == irmxTRUE)
        {
            sfile = PSEUDO_SZFILE;
        }
        else
        {
            return irmxFAIL;
        }
    }
    else
    {
        fseek(hfile, 0, SEEK_END);
        sfile = ftell(hfile);
        rewind(hfile);
    }

    pfcli->szbuf = sfile;
    pfcli->buf = (char *)malloc(sfile);
    if (pfcli->buf == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    pfcli->basebuf = pfcli->buf;

    if (hfile == NULL)
    {
        size_t i;
        for (i = 0; i < PSEUDO_SZFILE; i++)
        {
            *pfcli->buf++ = i;
        }
        pfcli->buf = pfcli->basebuf;
    }
    else
    {
        if (fread(pfcli->buf, 1, sfile, hfile) != sfile)
        {
            return irmxFAIL;
        }
    }

    if (hfile != NULL)
    {
        fclose(hfile);
    }

    return irmxOK;
}

void pf_get_item(char *header, const void *item)
{
    size_t remains;

    char fmt[16];
    sprintf(fmt, "%%-%ds", itempcfg.indent);
    printf(fmt, header);

    if (itempcfg.type == 's')
    {
        printf("%s\n", (char *)item);
        return;
    }

    if (itempcfg.type == 'h')
    {
        unsigned char i;
        for (i = 0; i < (itempcfg.base / 8); i++)
        {
            printf("%02hhx", *(uint8_t *)item++);
        }
        putchar('\n');
        return;
    }

    if (itempcfg.type == 'x')
    {
        switch (itempcfg.base)
        {
        case 8:
            printf("%02hhx\n", *(uint8_t *)item);
            return;

        case 16:
            printf("%04hx\n", *(uint16_t *)item);
            return;

        case 32:
            printf("%08x\n", *(uint32_t *)item);
            return;

        case 64:
            printf("%016lx\n", *(uint64_t *)item);
            return;

        default:
            printf("pf_get_item: %%x UNKNOWN BASE\n");
            return;
        }
    }

    if (itempcfg.type == 'd')
    {
        switch (itempcfg.base)
        {
        case 8:
            printf("%hhu\n", *(uint8_t *)item);
            return;

        case 16:
            printf("%hu\n", *(uint16_t *)item);
            return;

        case 32:
            printf("%d\n", *(uint32_t *)item);
            return;

        case 64:
            printf("%ld\n", *(uint64_t *)item);
            return;

        default:
            printf("pf_get_item: %%d UNKNOWN BASE\n");
            return;
        }
    }

    printf("pf_get_item: UNKNOWN FORMAT\n");
}