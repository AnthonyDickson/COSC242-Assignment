#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <getopt.h>

#include "mylib.h"
#include "htable.h"

static const char *HELP_TEXT = 
    "Usage: asgn [options] dict_file\n"
    " options:\n"
    "  -r\t\t\tUse a robust chaining method.\n"
    "  -s table-capacity\tUse table-capacity as the capacity of the hash"
    " table.\n"
    "  -p\t\t\tPrint the hash table.\n"
    "  -i\t\t\tPrint information about how long things took and number of"
    " unknown words found.\n"
    "  -h\t\t\tPrint a help message.\n";

int main(int argc, char **argv) {
    char option;
    const char *optstring = "r-s:pih";
    int use_robust_chaining = 0;
    int capacity = 3877; /* Default capacity. */
    int print_hash_table = 0;
    int print_info = 0;
    
    char word[256];
    htable dict;        
    FILE *dict_file;
    int num_unknown_words = 0;
    clock_t fill_start, fill_end, search_start, search_end;
        
    while ((option = getopt(argc, argv, optstring)) != EOF) {
        switch (option) {
            case 'r':
                use_robust_chaining = 1;
                break;
            case 's':
                capacity = atoi(optarg);
                break;
            case 'p':
                print_hash_table = 1;
                break;
            case 'i':
                print_info = 1;
                break;
            case 'h':
                /* Drop through to default case for option h. */
            default:
                fprintf(stderr,"%s\n", HELP_TEXT);
                exit(EXIT_SUCCESS);
        }
    }

    fill_start = clock();

    /* Dicitionary file name will be at end of args list after getopt. */
    dict_file = fopen(argv[argc - 1], "r");

    /* Start reading first file, which will serve as the dictionary. */
    dict = htable_new(capacity, use_robust_chaining);
    while (getword(word, sizeof word, dict_file) != EOF) {
        htable_insert(dict, word);
    }

    fclose(dict_file);

    fill_end = clock();
    
    if (print_hash_table == 1) {
        htable_print(dict);
        htable_free(dict);
        /* After printing the hash table do nothing else.*/
        return EXIT_SUCCESS;
    } 

    search_start = clock();
    
    /* Start reading input file */
    while (getword(word, sizeof word, stdin) != EOF) {
        if (htable_search(dict, word) == 0) {
            printf("%s\n", word);
            num_unknown_words++;
        }
    }

    search_end = clock();

    if (print_info == 1) {
        fprintf(stderr, "Fill time : %.6f\n", 
            (fill_end - fill_start) / (double) CLOCKS_PER_SEC);
        fprintf(stderr, "Search time : %.6f\n", 
            (search_end - search_start) / (double) CLOCKS_PER_SEC);
        fprintf(stderr, "Unknown words : %d\n", num_unknown_words); 
    }

    htable_free(dict);

    return EXIT_SUCCESS;
}