//
// Created by Ye Wint Naing on 17/9/25.
//

#ifndef MODEL_H
#define MODEL_H
#include <stdint.h>

// src/core/model.h

typedef enum {
    TYPE_NORMAL = 0,
    TYPE_FIRE,
    TYPE_WATER,
    TYPE_ELECTRIC,
    TYPE_GRASS,
    TYPE_ICE,
    TYPE_FIGHTING,
    TYPE_POISON,
    TYPE_GROUND,
    TYPE_FLYING,
    TYPE_PSYCHIC,
    TYPE_BUG,
    TYPE_ROCK,
    TYPE_GHOST,
    TYPE_DRAGON,
    TYPE_DARK,
    TYPE_STEEL,
    TYPE_FAIRY,
    TYPE_COUNT,          // == 18
    TYPE_UNKNOWN = 255   // for empty/invalid inputs; never set this bit
} PokemonType;

typedef struct Pokemon {
    char name[64];
    PokemonType type1;
    PokemonType type2;
    char legendary[10];
    int id;
    int total;
    int hp;
    int attack;
    int defense;
    int speed;
    int attack_speed;
    int defense_speed;
    int generation;
    uint32_t type_mask;
} Pokemon;



#endif //MODEL_H
