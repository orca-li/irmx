#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <irmx.h>

int main(int argc, char *argv[])
{
    int optc, opti;
    char *echo_demo_getopt = NULL;
    int value_demo_getopt = 0;

    static struct option long_options[] = {
        {"echo", required_argument, 0, 'e'},
        {"value", required_argument, 0, 'v'},
        {0, 0, 0, 0}};

    while ((optc = getopt_long(argc, argv, "v:e:", long_options, &opti)) != -1)
    {
        switch (optc)
        {
        case 'e':
            echo_demo_getopt = optarg;
            execl("/bin/echo", "echo", echo_demo_getopt, (char *)NULL);
            break;

        case 'v':
            value_demo_getopt = atoi(optarg);
            printf("CASE value: %d\n", value_demo_getopt);
            break;

        default:
            return 1;
        }
    }

    bitstr32_t bstr = 0x0300A0E3;
    
    isfdump(bstr);

    return 0;
}
