#include <parser.h>
#include <stdlib.h>
#include <stdio.h>

const char IRMX_ISF_ARM_IMM[] = {
    31,
    bwp_sizefld(cond), bwp_sizefld(nn),
    bwp_sizefld(i), bwp_sizefld(opcode), 
    bwp_sizefld(s),
    bwp_sizefld(rn), bwp_sizefld(rd),
    bwp_sizefld(rotate), bwp_sizefld(imm),
    0,
};

const char IRMX_ISF_ARM_RM[] = {
    31,
    bwp_sizefld(cond), bwp_sizefld(nn),
    bwp_sizefld(i), bwp_sizefld(opcode), 
    bwp_sizefld(s),
    bwp_sizefld(rn), bwp_sizefld(rd),
    bwp_sizefld(shift), bwp_sizefld(rm),
    0,
};

void
isetfmt_init(isetfmt_t *inst, bitstr_t bits)
{
    inst->cond = bwp_getfld(cond, bits);
    inst->nn = bwp_getfld(nn, bits);
    inst->i = bwp_getfld(i, bits);
    inst->opcode = bwp_getfld(opcode, bits);
    inst->s = bwp_getfld(s, bits);
    inst->rn = bwp_getfld(rn, bits);
    inst->rd = bwp_getfld(rd, bits);
    inst->shift = bwp_getfld(shift, bits);
    inst->rm = bwp_getfld(rm, bits);
    inst->rotate = bwp_getfld(rotate, bits);
    inst->imm = bwp_getfld(imm, bits);
}

void
print_rotate(bitstr_t rotate)
{
    switch (rotate)
    {
    case 0:
        printf("r0, ");
        break;

    case 1:
        printf("r1, ");
        break;
    
    case 2:
        printf("r2, ");
        break;

    case 3:
        printf("r3, ");
        break;

    case 4:
        printf("r4, ");
        break;
    
    default:
        printf("unk, ");
        break;
    }
}

void
print_inst(bitstr_t opcode, bitstr_t rotate, bitstr_t imm)
{
    switch (opcode)
    {
    case irmx_case_inst(mov):
        printf("mov ");
        break;
    
    default:
        printf("unk ");
        break;
    }

    print_rotate(rotate);
    printf("#%d", imm);
}

void
print_opcode(bitstr_t opcode, bitstr_t bits)
{
    char bfmt[3], buffer[128];

    bfmt[0] = bwp_sizefld(opcode) - 1;
    bfmt[1] = bwp_sizefld(opcode);
    bfmt[2] = 0;

    sbitputs(buffer, bwp_getfld(opcode, bits), bfmt);
    printf("%-10s%-12s ", "OPCODE", buffer);

    switch (opcode)
    {
    
    case irmx_case_inst(mov):
        printf("MOV");
        break;

    case irmx_case_inst(tst):
        printf("TST");
        break;

    default:
        printf("Unknown opcode");
        break;
    }
    putchar('\n');
}

#define isfdump_getitem(_str, _fld)                     \
    bfmt[0] = bwp_sizefld(_fld) - 1;                    \
    bfmt[1] = bwp_sizefld(_fld);                        \
    bfmt[2] = 0;                                        \
                                                        \
    sbitputs(buffer, bwp_getfld(_fld, bits), bfmt);     \
    printf("%-10s%-12s\n", _str, buffer);


bitstr_t
arm_readstr(bitstr_t bits)
{
    bitstr_t ret, tmp1, tmp2;
    ret = 0;
    tmp1 = tmp2 = bits;
    tmp1 &= 0xff000000;
    tmp2 &= 0x000000ff;
    ret |= (tmp1 >> 24);
    ret |= (tmp2 << 24);

    tmp1 = tmp2 = bits;
    tmp1 &= 0x00ff0000;
    tmp2 &= 0x0000ff00;
    ret |= (tmp1 >> 8);
    ret |= (tmp2 << 8);

    return ret;
}

void
isfdump(bitstr_t bits)
{
    char buffer[256];

    bits = arm_readstr(bits);

    isetfmt_t inst;
    isetfmt_init(&inst, bits);

    printf("ARM Instruction Set Format\n");
    if(inst.i == 1)
    {
        printf("%-8s %s\n", "Type", "Immediate");
        
    }
    printf("%-8s %08x\n", "Hex", bits);

    putchar('\n');

    if(inst.i == 1)
    {
        printf("COND NN I OPCD S REGN REGD RTAT IMMEDIAT\n");
        sbitputs(buffer, bits, IRMX_ISF_ARM_IMM);
        printf("%s\n\n", buffer);
    }
    else
    {
        printf("COND NN I OPCD S REGN REGD RTAT IMMEDIAT\n");
        sbitputs(buffer, bits, IRMX_ISF_ARM_IMM);
        printf("%s\n\n", buffer);
    }
    
    char bfmt[3];
    isfdump_getitem("COND", cond);
    isfdump_getitem("NONAME", nn);
    isfdump_getitem("TYPE", i);

    print_opcode(inst.opcode, bits);

    isfdump_getitem("S", s);
    isfdump_getitem("REGN", rn);
    isfdump_getitem("REGD", rd);

    if(inst.i == 1)
    {
        isfdump_getitem("ROTATE", rotate);
        isfdump_getitem("IMMEDIATE", imm);
        putchar('\n');
        print_inst(inst.opcode, inst.rotate, inst.imm);
    } 
    else
    {
        isfdump_getitem("SHIFT", shift);
        isfdump_getitem("REGM", rm);
        putchar('\n');
        print_inst(inst.opcode, inst.rotate, inst.imm);
    }
}