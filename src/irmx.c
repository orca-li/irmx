#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <irmx.h>

int main(int argc, char *argv[])
{
    int optc, opti;
    unsigned char irmxmain;

    static struct option long_options[] = {
        {"set-arch", required_argument, 0, 'a'},
        {0, 0, 0, 0},
    };

    static char list_options[] =
        "t"   // flags
        "a::" // configs
        "d";  // packets

    while ((optc = getopt_long(argc, argv, list_options, long_options, &opti)) != -1)
    {
        switch (optc)
        {
        case 'a':
            if (optarg != NULL)
            {
                cfg_irmxd.archname = optarg;
            }
            else
            {
                fprintf(stderr, "Unknown option: -a\n");
                exit(1);
            }
            break;
        case 'd':
            irmxmain = 'd';
            break;

        case 't':
            mprimf.flags.test = irmxTRUE;
            break;

        default:
            return 1;
        }
    }

    switch (irmxmain)
    {
    case 'd':
        if (optind < argc)
        {
            cfg_irmxd.filename = argv[optind];
        }
        else if(mprimf.flags.test != irmxTRUE)
        {
            fprintf(stderr, "Please using <filename>\n");
            exit(1);
        }

        if (irmxd_init(cfg_irmxd.archname) != irmxOK)
        {
            fprintf(stderr, "Unknown arch\n");
            exit(1);
        }

        if (pf_ftobuf(cfg_irmxd.filename, &irmxd_pfcli) != irmxOK)
        {
            fprintf(stderr, "Cann't open file\n");
            exit(1);
        }

        irmxdmain();
        break;

    default:
        fprintf(stderr, "Unknown main line\n"
                        "Please using other option\n");
        exit(1);
        return 1;
    }

    return 0;
}