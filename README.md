```
 __     ______     __    __     __  __    
/\ \   /\  == \   /\ "-./  \   /\_\_\_\   
\ \ \  \ \  __<   \ \ \-./\ \  \/_/\_\/_  
 \ \_\  \ \_\ \_\  \ \_\ \ \_\   /\_\/\_\ 
  \/_/   \/_/ /_/   \/_/  \/_/   \/_/\/_/ 
```                                  
<h2>Description </h2>

`irmx` is a set of console programs. It is also similar to the 
QEMU emulation program. The program is currently under 
development. Inside it includes the following routines:

- Disassembly
- Execution of arm commands
- Support for ARM5, ARM7, M0, M1, M4 architectures
- Validator
- Parser

<h2>How to use</h2>

```bash
$ git clone https://github.com/orca-li/irmx.git
$ make
$ ./dbg/irmx
ARM Instruction Set Format
Type     Immediate
Hex      e3a00003

COND NN I OPCD S REGN REGD RTAT IMMEDIAT
1110 00 1 1101 0 0000 0000 0000 00000011 

COND      1110        
NONAME    00          
TYPE      1           
OPCODE    1101         MOV
S         0           
REGN      0000        
REGD      0000        
ROTATE    0000        
IMMEDIATE 00000011    

mov r0, #3
```