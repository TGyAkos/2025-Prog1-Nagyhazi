//
// Created by User01 on 11/13/2025.
//

#include "morse.h"

char *encode_text(Node *start, char *text) {
  Split_str *arr = split_str(text, ' ');
  for (int i = 0; i < arr->len; ++i) {
    char *temp = encode_word(start, arr->arr[i]);
    free(arr->arr[i]);
    arr->arr[i] = temp;
  }

  char *encoded = flatten_split_str(arr, "\t");
  free_split_str(arr);
  return encoded;
}

char *encode_word(Node *start, char *word) {
  Split_str *encoded = malloc(sizeof(Split_str));
  encoded->len = strlen(word);
  encoded->arr = malloc(encoded->len * sizeof(char *));
  for (int i = 0; i < encoded->len; ++i) {
    char *encoded_char = encode_char(start, word[i]);
    int encoded_char_len = strlen(encoded_char);
    encoded->arr[i] = encoded_char;
    encoded->arr[i][encoded_char_len] = '\0';

  }
  char *flattened_encoded_char = flatten_split_str(encoded, " ");
  free_split_str(encoded);
  return flattened_encoded_char;
}

// char *encode_char(Node *start, char character, char *morse_code,
//                   const char *morse_char) {
//   strcat(morse_code, morse_char);
//
//   if (start->character == character)
//     return morse_code;
//
//   if (start->dot == NULL && start->dash == NULL)
//     return "\0";
//
//   encode_char(start->dot, character, morse_code, ".");
//   encode_char(start->dash, character, morse_code, "-");
//
//   return morse_code;
// }

char *encode_char(Node *start, char character) {
  if (start == NULL)
    return NULL;

  if (start->character == character) {
    char *base = malloc(1);
    if (base == NULL)
      return NULL;
    base[0] = '\0';
    return base;
  }

  char *dot_path = encode_char(start->dot, character);
  if (dot_path != NULL) {
    char *res = malloc((strlen(dot_path) + 2) * sizeof(char));
    if (res == NULL) {
      free(dot_path);
      return NULL;
    }
    res[0] = '.';
    strcpy(res + 1, dot_path);
    free(dot_path);
    return res;
  }

  char *dash_path = encode_char(start->dash, character);
  if (dash_path != NULL) {
    char *res = malloc((strlen(dash_path) + 2) * sizeof(char));
    if (res == NULL) {
      free(dash_path);
      return NULL;
    }
    res[0] = '-';
    strcpy(res + 1, dash_path);
    free(dash_path);
    return res;
  }

  return NULL;
}

char *decode_morse_text(Node *start, char *morse_text) {
  Split_str *arr = split_str(morse_text, '\t');
  for (int i = 0; i < arr->len; ++i) {
    char *temp = decode_morse_word(start, arr->arr[i]);
    free(arr->arr[i]);
    arr->arr[i] = temp;
  }

  char *decoded = flatten_split_str(arr, " ");
  free_split_str(arr);
  return decoded;
}

char *decode_morse_word(Node *start, char *morse_word) {
  Split_str *arr = split_str(morse_word, ' ');
  char *decoded = malloc((arr->len + 1) * sizeof(char));
  for (int i = 0; i < arr->len; ++i)
    decoded[i] = decode_morse_char(start, arr->arr[i]);
  decoded[arr->len] = '\0';
  free_split_str(arr);
  return decoded;
}

Node *init_node(void) {
  Node *new = malloc(sizeof(Node));
  new->character = '\0';
  new->dot = NULL;
  new->dash = NULL;
  return new;
}

char decode_morse_char(Node *start, char *code) {
  int len = strlen(code);
  Node *current = start;
  for (int i = 0; i < len; ++i) {
    switch (code[i]) {
    case '.':
      current = current->dot;
      break;
    case '-':
      current = current->dash;
      break;
    default:
      // TODO print proper error
      printf("error: decode_morse_char code[%d]: %c\n", i, code[i]);
      break;
    }
  }
  // TODO add error case if current is NULL pointer
  return current->character;
}

void add_generate_morse(Node **start, const char *code, const char character) {
  int len = strlen(code);
  Node *current = *start;
  for (int i = 0; i < len; ++i) {
    switch (code[i]) {
    case '.':
      try_add_node(&current->dot);
      current = current->dot;
      break;
    case '-':
      try_add_node(&current->dash);
      current = current->dash;
      break;
    default:
      // TODO: print error here in a proper manner
      printf("error add_generate_morse\n");
      break;
    }
  }
  current->character = character;
}
void try_add_node(Node **node) {
  if (*node != NULL)
    return;
  *node = init_node();
}

Split_str *split_str(const char *arr, char delim) {
  int ct_len = 0;
  int ct_delim = 0;
  while (arr[ct_len] != '\0') {
    if (arr[ct_len] == delim)
      ++ct_delim;
    ++ct_len;
  }

  // TODO will give unpredictable result if arr ends in delim
  // TODO THROW ERROR 03 before EVER getting here
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

void free_split_str(Split_str *split_str) {
  for (int i = 0; i < split_str->len; ++i)
    free(split_str->arr[i]);
  free(split_str->arr);
  free(split_str);
}

char *flatten_split_str(Split_str *split_str, char *delim) {
  int ct_char = 1 + split_str->len;
  for (int i = 0; i < split_str->len; ++i)
    ct_char += strlen(split_str->arr[i]);

  char *flattened = malloc(ct_char * sizeof(char));
  flattened[0] = '\0';

  for (int i = 0; i < split_str->len; ++i) {
    strcat(flattened, split_str->arr[i]);
    if (i != split_str->len -1)
      strcat(flattened, delim);
  }

  return flattened;
}

void free_tree(Node *start) {
  if (start == NULL)
    return;
  free_tree(start->dot);
  free(start->dot);
  free_tree(start->dash);
  free(start->dash);
}

void dump_tree(Node *start) { dump_node(start, 0); }

void dump_node(Node *start, int counter) {
  if (start == NULL)
    return;
  printf("%c\n", start->character);
  ++counter;
  dump_node(start->dot, counter);
  dump_node(start->dash, counter);
}