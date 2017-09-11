#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static const char *HELP_TEXT = 
    "Usage: asgn [options] file_1 file_2\n"
    " options:\n"
    "  -r\t\tUse a robust chaining method.\n"
    "  -s table-size\tUse table-size as the size of the hash table.\n"
    "  -p\t\tPrint the hash table.\n"
    "  -i\t\tPrint information about how long things took and number of"
    " unknown words found.\n"
    "  -h\t\tPrint a help message.\n";

int main(int argc, char **argv) {
    char option;
    const char *optstring = "r-s:pih";

    int use_robust_chaining = 0;
    int size = 3877;

    if (argc < 3) {
        fprintf(stderr,"%s\n", HELP_TEXT);
        exit(EXIT_FAILURE);
    }

    while ((option = getopt(argc, argv, optstring)) != EOF) {
        switch (option) {
            case 'r':
                use_robust_chaining = 1;
                break;
            case 's':
                size = *optarg;
                break;
            case 'p':
                printf("option %c\n", option);
                break;
            case 'i':
                printf("option %c\n", option);
                break;
            case 'h':
                /* Drop through to default case for option h. */
            default:
                fprintf(stderr,"%s\n", HELP_TEXT);
                exit(EXIT_SUCCESS);
        }
    }

    return EXIT_SUCCESS;
}