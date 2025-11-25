//
// Created by User01 on 11/25/2025.
//

#include "split_str.h"

/** @copydoc split_str */
Split_str *split_str(const char *arr, char delim) {
  int ct_len = 0;
  int ct_delim = 0;
  while (arr[ct_len] != '\0') {
    if (arr[ct_len] == delim)
      ++ct_delim;
    ++ct_len;
  }

  int ct_split_arr = 0;
  int ct_split_arr_len = ct_delim + 1;
  char **split_arr = malloc(ct_split_arr_len * sizeof(char *));

  int ct_before_delim = 0;
  for (int i = 0; i <= ct_len; ++i) {
    if (arr[i] == delim || ct_len == i) {
      // Allocate and assign value for split_arr 2d array
      split_arr[ct_split_arr] =
          (char *)malloc(ct_before_delim + 1 * sizeof(char));
      for (int j = 0; j < ct_before_delim; ++j)
        split_arr[ct_split_arr][j] = arr[(i - ct_before_delim) + j];
      split_arr[ct_split_arr][ct_before_delim] = '\0';

      ct_before_delim = 0;
      ++ct_split_arr;
    } else {
      ++ct_before_delim;
    }
  }

  Split_str *new = malloc(sizeof(Split_str));
  new->len = ct_split_arr_len;
  new->arr = split_arr;
  return new;
}

/** @copydoc free_split_str */
void free_split_str(Split_str *split_str) {
  for (int i = 0; i < split_str->len; ++i)
    free(split_str->arr[i]);
  free(split_str->arr);
  free(split_str);
}

/** @copydoc flatten_split_str */
char *flatten_split_str(Split_str *split_str, char *delim) {
  int ct_char = 1 + split_str->len;
  for (int i = 0; i < split_str->len; ++i)
    ct_char += strlen(split_str->arr[i]);

  char *flattened = malloc(ct_char * sizeof(char));
  flattened[0] = '\0';

  for (int i = 0; i < split_str->len; ++i) {
    strcat(flattened, split_str->arr[i]);
    if (i != split_str->len - 1)
      strcat(flattened, delim);
  }

  return flattened;
}