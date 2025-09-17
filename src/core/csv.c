//
// Created by Ye Wint Naing on 17/9/25.
//
#include "csv.h"

#include <stdlib.h>
#include <string.h>

#include "normalize.h"
#include "util/split.h"


int csv_load_file(const char *filename, PokemonList *list, int fail_fast) {
    printf("Loading csv file %s\n", filename);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    // initialize the list
    list->records_size = 0;
    list->records_capacity = 128;
    list->records = malloc(list->records_capacity * sizeof(Pokemon));

    if (list->records == NULL) {
        printf("Could not allocate memory for records\n");
        return 1;
    }

    char line[1024]; // enough for one row; increase if needed

    if (fgets(line, sizeof(line), fp) == NULL) {
        fprintf(stderr, "File is empty or unreadable.\n");
        fclose(fp);
        return 1;
    }
    const char *delim = ",";

    while (fgets(line, sizeof(line), fp)) {
        // char *token = strtok(line, delim);
        //

        int count = 0;
        char **result_array = split(
            line,
            delim,
            &count
        );

        Pokemon p;
        //
        // int id = atoi(token);
        p.id = atoi(result_array[0]);


        strncpy(p.name, result_array[1], sizeof(p.name));

        p.type1 = parse_type(result_array[2]);
        p.type2 = parse_type(result_array[3]);

        p.total = atoi(result_array[4]);

        p.hp = atoi(result_array[5]);

        p.attack = atoi(result_array[6]);

        p.defense = atoi(result_array[7]);

        p.attack_speed = atoi(result_array[8]);

        p.defense_speed = atoi(result_array[9]);

        p.speed = atoi(result_array[10]);

        p.generation = atoi(result_array[11]);

        p.type_mask = build_type_mask(p.type1, p.type2);

        strncpy(p.legendary, result_array[12], sizeof(p.legendary));

        free_split_array(result_array, count);

        list->records[list->records_size] = p;
        list->records_size++;

        if (list->records_size == list->records_capacity) {
            list->records_capacity *= 2;
            Pokemon *new_size = realloc(list->records, list->records_size * sizeof(Pokemon));
            if (new_size == NULL) {
                fprintf(stderr, "Could not allocate memory for records.\n");
                fclose(fp);
                return 1;
            }

            list->records = new_size;
        }
    }

    printf("%zu\n", list->records_size);
    fclose(fp);


    return 0;
}

void csv_free(PokemonList *list) {
    if (list->records != NULL) {
        free(list->records);
    }
    list->records = NULL;
    list->records_size = 0;
    list->records_capacity = 0;
}
