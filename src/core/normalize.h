//
// Created by Ye Wint Naing on 17/9/25.
//

#ifndef NORMALIZE_H
#define NORMALIZE_H


#include <stdint.h>
#include "model.h"  // for PokemonType enum

// Converts string like "Fire" to TYPE_FIRE enum
PokemonType parse_type(const char *type_str);

// Builds bitmask from two types
uint32_t build_type_mask(PokemonType t1, PokemonType t2);

const char *pokemon_type_to_string(PokemonType type);

#endif

