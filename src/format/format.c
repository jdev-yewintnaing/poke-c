//
// Created by Ye Wint Naing on 17/9/25.
//
#include "format.h"
#include <stdio.h>

#include "core/normalize.h"

void print_table_row(const Pokemon p) {
    printf("| %-14s | %-7s | %-7s | %5d | %3d | %6d | %6d | %8d | %8d | %5d | %10d | %9s |\n",
           p.name,
           pokemon_type_to_string(p.type1),
           pokemon_type_to_string(p.type2),
           p.total,
           p.hp,
           p.attack,
           p.defense,
           p.attack_speed,
           p.defense_speed,
           p.speed,
           p.generation,
           p.legendary);
}
void print_table_header() {
    printf("+----------------+---------+---------+-------+-----+--------+--------+----------+----------+-------+------------+-----------+\n");
    printf("| %-14s | %-7s | %-7s | %5s | %3s | %6s | %6s | %8s | %8s | %5s | %10s | %9s |\n",
           "Name", "Type 1", "Type 2", "Total", "HP", "Attack", "Defense",
           "Sp. Atk", "Sp. Def", "Speed", "Generation", "Legendary");
    printf("+----------------+---------+---------+-------+-----+--------+--------+----------+----------+-------+------------+-----------+\n");
}