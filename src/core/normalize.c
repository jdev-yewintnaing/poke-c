//
// Created by Ye Wint Naing on 17/9/25.
//
#include <string.h>
#include <strings.h> // for strcasecmp()
#include "model.h"
#include "normalize.h"


static const char *TYPE_NAMES[TYPE_COUNT] = {
    "Normal","Fire","Water","Electric","Grass","Ice",
    "Fighting","Poison","Ground","Flying","Psychic","Bug",
    "Rock","Ghost","Dragon","Dark","Steel","Fairy"
};

const char *pokemon_type_to_string(PokemonType t) {
    if (t >= 0 && t < TYPE_COUNT) return TYPE_NAMES[t];
    return "";
}

PokemonType parse_type(const char *type_str) {
    if (type_str == NULL || *type_str == '\0') return TYPE_UNKNOWN;

    // Fast path: compare against table
    for (int i = 0; i < TYPE_COUNT; ++i) {
        if (strcasecmp(type_str, TYPE_NAMES[i]) == 0) {
            return (PokemonType)i;
        }
    }
    return TYPE_UNKNOWN;
}

uint32_t build_type_mask(PokemonType t1, PokemonType t2) {
    uint32_t mask = 0;
    if (t1 != TYPE_UNKNOWN) mask |= (1u << t1);
    if (t2 != TYPE_UNKNOWN && t2 != t1) mask |= (1u << t2);
    return mask;
}

