Version 0.0.1
```
 __     ______     __    __     __  __    
/\ \   /\  == \   /\ "-./  \   /\_\_\_\   
\ \ \  \ \  __<   \ \ \-./\ \  \/_/\_\/_  
 \ \_\  \ \_\ \_\  \ \_\ \ \_\   /\_\/\_\ 
  \/_/   \/_/ /_/   \/_/  \/_/   \/_/\/_/ 
```                                  
<h2>Description </h2>

`irmx` is a set of console programs. It is also similar to the 
QEMU emulation program. The program has its own settings that can be changed. It is currently under 
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
$ ./dbg/irmx -dt # architecture tests
$ ./dbg/irmx -d <filename> # arm test
$ ./dbg/irmx -d <filename> --set-arch="test-big64"
Architecture       test-big64
Capacity           64
Bytes read         8
Type-endian        big-endian
Input              fe1234eaa0e01221
Endian             2112e0a0ea3412fe
```