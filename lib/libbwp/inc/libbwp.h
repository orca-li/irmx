#if !defined(__LIBBWP_H__)
#define __LIBBWP_H__

#include <stdint.h>

typedef uint8_t bitstr8_t;
typedef uint16_t bitstr16_t;
typedef uint32_t bitstr32_t;
typedef uint64_t bitstr64_t;

typedef bitstr64_t bitstr_t;
typedef bitstr64_t bitstrl_t;

#define __BWP_BITSIZEOF_BYTE 8u
#define bitsizeof(_type) (sizeof(_type) * __BWP_BITSIZEOF_BYTE)

#define _BWP_FIELD_SIZEOF_
#define _BWP_FIELD_OFFSET_
#define _BWP_FIELD_MASK_
#define bwp_sizefld(_field)         (_BWP_FIELD_SIZEOF_ ## _field)
#define bwp_offsetfld(_field)       (_BWP_FIELD_OFFSET_ ## _field)
#define bwp_getmskfld(_field)       (_BWP_FIELD_MASK_ ## _field)
#define bwp_mkfld(_field)           ((~((0x1FFFFFFFFu) << (bwp_sizefld(_field) + bwp_offsetfld(_field) + 1)) \
    & ((0xFFFFFFFFu) << bwp_offsetfld(_field))) & 0xFFFFFFFF)
#define bwp_getfld(_field, _bits)   ((_bits & bwp_getmskfld(_field)) >> (bwp_offsetfld(_field)))

void
sbitputc(char *buf, bitstr_t *bits, char bitc, const bitstr_t hbit);
void
sbitputs(char *buf, bitstr_t bits, const char *argf);

#endif /* __LIBBWP_H__ */