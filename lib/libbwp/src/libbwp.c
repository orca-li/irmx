#include <stdio.h>
#include <libbwp.h>
#include <stdlib.h>

void
sbitputc(char *buf, bitstr_t *bits, char bitc, const bitstr_t hbit)
{
    while(bitc--)
    {
        *buf++ = (*bits & hbit) ? '1' : '0';
        *bits <<= 1;
    }
    *buf = '\0';
}

void
sbitputs(char *buf, bitstr_t bits, const char *argf)
{
    bitstr_t hbit;

    hbit = (1 << *argf);

    while(*(++argf))
    {
        sbitputc(buf, &bits, *argf, hbit);
        buf += *argf;
        *buf++ = ' ';
    }
    *buf = '\0';
}