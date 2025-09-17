#include <stdio.h>
#include <getopt.h> // POSIX-compatible getopt_long
#include <stdlib.h>
#include <string.h>
#include "core/csv.h"
#include "core/normalize.h"
#include "format/format.h"

void print_usage(const char *program_name) {
    printf("Usage:\n");
    printf("  %s info [--file FILE]\n", program_name);
    printf("  %s find [--file FILE] [--type TYPE]\n", program_name);
    printf("Examples:\n");
    printf("  %s info --file data/pokemon.csv\n", program_name);
    printf("  %s find --type Electric --file data/pokemon.csv\n", program_name);
}


void run_info(const char *csv_file) {
    PokemonList list;
    if (csv_load_file(csv_file, &list, 1) == 0) {
        printf("Loaded %zu Pokémon!\n", list.records_size);
        print_table_header();
        for (size_t i = 0; i < list.records_size; i++) {
            print_table_row(list.records[i]);
        }
        csv_free(&list);
    } else {
        fprintf(stderr, "Error loading CSV\n");
    }
}

void run_find(const char *csv_file, const char *type_filter) {
    PokemonList list;
    if (csv_load_file(csv_file, &list, 1) == 0) {
        print_table_header();
        for (size_t i = 0; i < list.records_size; i++) {
            PokemonType t1 = parse_type(type_filter);
            uint32_t wanted_mask = (1u << t1) ;
            Pokemon pokemon = list.records[i];

            if (pokemon.type_mask == wanted_mask) {
                print_table_row(pokemon);
            }

        }
        csv_free(&list);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    char *subcommand = argv[1];
    const char *csv_file = "data/pokemon.csv";
    const char *type_filter = NULL;

    static struct option long_options[] = {
        {"file", required_argument, 0, 'f'},
        {"type", required_argument, 0, 't'},
        {0, 0, 0, 0}
    };

    int opt;
    int option_index = 0;

    // Shift argv so getopt_long starts at subcommand args
    optind = 2;

    while ((opt = getopt_long(argc, argv, "f:t:", long_options, &option_index)) != -1) {
        switch (opt) {
            case 'f':
                csv_file = optarg;
                break;
            case 't':
                type_filter = optarg;
                break;
            default:
                print_usage(argv[0]);
                return 2;
        }
    }

    printf("%s\n", type_filter);
    // Dispatch subcommands
    if (strcmp(subcommand, "info") == 0) {
        run_info(csv_file);

    } else if (strcmp(subcommand, "find") == 0) {
        run_find(csv_file, type_filter);
    } else {
        fprintf(stderr, "Unknown subcommand: %s\n", subcommand);
        // print_usage(argv[0]);
        return 2;
    }

    return 0;
}
