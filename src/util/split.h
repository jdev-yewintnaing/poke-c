//
// Created by Ye Wint Naing on 17/9/25.
//

#ifndef SPLIT_H
#define SPLIT_H

void free_split_array(char **array, int size);

char **split(const char *str, const char *delim, int *count);
#endif //SPLIT_H
