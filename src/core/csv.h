//
// Created by Ye Wint Naing on 17/9/25.
//

#ifndef CSV_H
#define CSV_H
#include <stdio.h>

#include "model.h"

typedef struct {
    Pokemon *records;
    size_t records_size;
    size_t records_capacity;
} PokemonList;

// ---------- Function declarations ----------

/**
 * Load and parse the CSV file into a list of Pokemon structs.
 *
 * @param filename path to the CSV file (e.g., "data/pokemon.csv")
 * @param list pointer to the target PokemonList struct (will be filled)
 * @param fail_fast if true, stop at first bad row; else skip bad rows
 * @return 0 on success, non-zero on failure
 */
int csv_load_file(const char *filename, PokemonList *list, int fail_fast);

/**
 * Free memory used by a PokemonList
 */
void csv_free(PokemonList *list);

/**
 * Print headers of CSV (for debugging)
 */
void csv_print_headers(void); // optional


#endif //CSV_H
