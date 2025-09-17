//
// Created by Ye Wint Naing on 17/9/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "split.h"

// Function to free the memory allocated for the array of strings
void free_split_array(char **array, int size) {
    if (array == NULL) {
        return;
    }
    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);
}

// Function to split a string by a delimiter and return a dynamically allocated array of strings
// The caller is responsible for freeing the returned array using free_split_array()
char **split(const char *str, const char *delim, int *count) {
    if (str == NULL || delim == NULL || count == NULL) {
        return NULL;
    }

    // Allocate an initial array of pointers. We will reallocate as needed.
    int capacity = 10;
    char **result = malloc(capacity * sizeof(char *));
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }

    *count = 0;
    const char *current_pos = str;
    const char *next_delim;

    while ((next_delim = strstr(current_pos, delim)) != NULL) {
        // Calculate the length of the current token
        size_t token_len = next_delim - current_pos;

        // Reallocate memory for the array of pointers if needed
        if (*count >= capacity) {
            capacity *= 2;
            char **temp = realloc(result, capacity * sizeof(char *));
            if (temp == NULL) {
                free_split_array(result, *count);
                return NULL;
            }
            result = temp;
        }

        // Allocate memory for the token and copy it
        result[*count] = malloc(token_len + 1);
        if (result[*count] == NULL) {
            free_split_array(result, *count);
            return NULL;
        }
        strncpy(result[*count], current_pos, token_len);
        result[*count][token_len] = '\0'; // Null-terminate the new string

        (*count)++;
        current_pos = next_delim + strlen(delim); // Move past the delimiter
    }

    // Handle the last token (or the only token if no delimiter was found)
    size_t last_token_len = strlen(current_pos);
    if (*count >= capacity) {
        capacity += 1; // Add one more slot for the last token
        char **temp = realloc(result, capacity * sizeof(char *));
        if (temp == NULL) {
            free_split_array(result, *count);
            return NULL;
        }
        result = temp;
    }

    result[*count] = malloc(last_token_len + 1);
    if (result[*count] == NULL) {
        free_split_array(result, *count);
        return NULL;
    }
    strcpy(result[*count], current_pos);

    (*count)++;

    return result;
}