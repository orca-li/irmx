#if !defined(__IRMX_PARSER_H__)
#define __IRMX_PASRSER_H__

#include <libbwp.h>

#define _BWP_FIELD_SIZEOF_cond      (4)
#define _BWP_FIELD_SIZEOF_nn        (2)
#define _BWP_FIELD_SIZEOF_i         (1)
#define _BWP_FIELD_SIZEOF_opcode    (4)
#define _BWP_FIELD_SIZEOF_s         (1)
#define _BWP_FIELD_SIZEOF_rn        (4)
#define _BWP_FIELD_SIZEOF_rd        (4)
#define _BWP_FIELD_SIZEOF_op2       (12)

#define _BWP_FIELD_SIZEOF_shift     (8)
#define _BWP_FIELD_SIZEOF_rm        (4)
#define _BWP_FIELD_SIZEOF_rotate    (4)
#define _BWP_FIELD_SIZEOF_imm       (8)

#define _BWP_FIELD_OFFSET_cond      (28)
#define _BWP_FIELD_OFFSET_nn        (26)
#define _BWP_FIELD_OFFSET_i         (25)
#define _BWP_FIELD_OFFSET_opcode    (21)
#define _BWP_FIELD_OFFSET_s         (20)
#define _BWP_FIELD_OFFSET_rn        (16)
#define _BWP_FIELD_OFFSET_rd        (12)
#define _BWP_FIELD_OFFSET_op2       (0)

#define _BWP_FIELD_OFFSET_shift     (4)
#define _BWP_FIELD_OFFSET_rm        (0)
#define _BWP_FIELD_OFFSET_rotate    (8)
#define _BWP_FIELD_OFFSET_imm       (0)

#define _BWP_FIELD_MASK_cond    (bwp_mkfld(cond))
#define _BWP_FIELD_MASK_nn      (bwp_mkfld(nn))
#define _BWP_FIELD_MASK_i       (bwp_mkfld(i))
#define _BWP_FIELD_MASK_opcode  (bwp_mkfld(opcode))
#define _BWP_FIELD_MASK_s       (bwp_mkfld(s))
#define _BWP_FIELD_MASK_rn      (bwp_mkfld(rn))
#define _BWP_FIELD_MASK_rd      (bwp_mkfld(rd))
#define _BWP_FIELD_MASK_shift   (bwp_mkfld(shift))
#define _BWP_FIELD_MASK_rm      (bwp_mkfld(rm))
#define _BWP_FIELD_MASK_rotate  (bwp_mkfld(rotate))
#define _BWP_FIELD_MASK_imm     (bwp_mkfld(imm))

#define _BWP_OPCODE_CASE_
#define _BWP_OPCODE_CASE_and    (0b0000)
#define _BWP_OPCODE_CASE_eor    (0b0001)
#define _BWP_OPCODE_CASE_sub    (0b0010)
#define _BWP_OPCODE_CASE_rsb    (0b0011)
#define _BWP_OPCODE_CASE_add    (0b0100)
#define _BWP_OPCODE_CASE_adc    (0b0101)
#define _BWP_OPCODE_CASE_sbc    (0b0110)
#define _BWP_OPCODE_CASE_rsc    (0b0111)
#define _BWP_OPCODE_CASE_tst    (0b1000)
#define _BWP_OPCODE_CASE_teq    (0b1001)
#define _BWP_OPCODE_CASE_cmp    (0b1010)
#define _BWP_OPCODE_CASE_cmn    (0b1011)
#define _BWP_OPCODE_CASE_orr    (0b1100)
#define _BWP_OPCODE_CASE_mov    (0b1101)
#define _BWP_OPCODE_CASE_bic    (0b1110)
#define _BWP_OPCODE_CASE_mvn    (0b1111)

#define irmx_case_inst(_inst) (_BWP_OPCODE_CASE_ ## _inst)

typedef struct STRUCT_INST_SET_FMT {
    uint32_t cond       :bwp_sizefld(cond);
    uint32_t nn         :bwp_sizefld(nn);
    uint32_t i          :bwp_sizefld(i);
    uint32_t opcode     :bwp_sizefld(opcode);
    uint32_t s          :bwp_sizefld(s);
    uint32_t rn         :bwp_sizefld(rn);
    uint32_t rd         :bwp_sizefld(rd);
    uint32_t shift      :bwp_sizefld(shift);
    uint32_t rm         :bwp_sizefld(rm);
    uint32_t rotate     :bwp_sizefld(rotate);
    uint32_t imm        :bwp_sizefld(imm);
} isetfmt_t;

typedef struct STRUCT_TABLE_ITEM {
    uint8_t index;
    uint8_t size;
    char *msg;
} stritem_t;

void
isfdump(bitstr_t bits);

#endif /* __IRMX_PASRSER_H__ */