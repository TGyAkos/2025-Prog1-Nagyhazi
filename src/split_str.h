//
// Created by User01 on 11/25/2025.
//

#ifndef NAGYHAZI_SPLIT_STR_H
#define NAGYHAZI_SPLIT_STR_H

#ifdef DEBUG_MALLOC
#include "debugmalloc.h"
#endif // DEBUG_MALLOC

#include <stdlib.h>
#include <string.h>

typedef struct Split_str {
  int len;
  char **arr;
} Split_str;

/**
 * Splits a string into an array of substrings based on a delimiter character
 * Creates a Split_str structure containing the array of parts and their count
 * @param arr String to be split into parts
 * @param delim Delimiter character used to identify split points
 * @return Split_str structure containing the split parts and their count
 */
Split_str *split_str(const char *arr, char delim);

/**
 * Frees all memory allocated for a Split_str structure
 * Deallocates each individual string in the array and the array itself
 * @param split_str Split_str structure to be freed
 */
void free_split_str(Split_str *split_str);

/**
 * Flattens a Split_str structure back into a single string
 * Joins all parts together with the specified delimiter string between them
 * The delimiter is not added after the final part
 * @param split_str Split_str structure containing parts to be flattened
 * @param delim Delimiter string to insert between parts
 * @return Flattened string with parts separated by the delimiter
 */
char *flatten_split_str(Split_str *split_str, char *delim);

#endif // NAGYHAZI_SPLIT_STR_H
