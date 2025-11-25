//
// Created by User01 on 11/13/2025.
//

#include "morse.h"

/** @copydoc encode_text */
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

/** @copydoc encode_word */
char *encode_word(Node *start, char *word) {
  Split_str *encoded = malloc(sizeof(Split_str));
  encoded->len = strlen(word);
  encoded->arr = malloc(encoded->len * sizeof(char *));
  for (int i = 0; i < encoded->len; ++i) {
    char *encoded_char = encode_char(start, word[i]);
    if (encoded_char == NULL)
      print_error_and_exit(5, "Sikertelen forditas hianyos kodtabla miatt");
    int encoded_char_len = strlen(encoded_char);
    encoded->arr[i] = encoded_char;
    encoded->arr[i][encoded_char_len] = '\0';
  }
  char *flattened_encoded_char = flatten_split_str(encoded, " ");
  free_split_str(encoded);
  return flattened_encoded_char;
}

/** @copydoc encode_char */
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

/** @copydoc decode_morse_text */
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

/** @copydoc decode_morse_word */
char *decode_morse_word(Node *start, char *morse_word) {
  Split_str *arr = split_str(morse_word, ' ');
  char *decoded = malloc((arr->len + 1) * sizeof(char));
  for (int i = 0; i < arr->len; ++i)
    decoded[i] = decode_morse_char(start, arr->arr[i]);
  decoded[arr->len] = '\0';
  free_split_str(arr);
  return decoded;
}

/** @copydoc init_node */
Node *init_node(void) {
  Node *new = malloc(sizeof(Node));
  new->character = '\0';
  new->dot = NULL;
  new->dash = NULL;
  return new;
}

/** @copydoc decode_morse_char */
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
      // printf("error: decode_morse_char code[%d]: %c\n", i, code[i]);
      print_error_and_exit(5, "Sikertelen forditas hianyos kodtabla miatt");
      break;
    }
  }
  // TODO add error case if current is NULL pointer
  return current->character;
}

/** @copydoc add_generate_morse */
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
      print_error_and_exit(2, "Nem ASCII karakter van a kodtablaban vagy a "
                              "kodolando/dekodolando szovegben");
      break;
    }
  }
  current->character = character;
}

/** @copydoc try_add_node */
void try_add_node(Node **node) {
  if (*node != NULL)
    return;
  *node = init_node();
}

/** @copydoc free_tree */
void free_tree(Node *start) {
  if (start == NULL)
    return;
  free_tree(start->dot);
  free(start->dot);
  free_tree(start->dash);
  free(start->dash);
}

/** @copydoc dump_tree */
void dump_tree(Node *start) { dump_node(start, 0); }

/** @copydoc dump_node */
void dump_node(Node *start, int counter) {
  if (start == NULL)
    return;
  printf("%c\n", start->character);
  ++counter;
  dump_node(start->dot, counter);
  dump_node(start->dash, counter);
}

/** @copydoc print_error_and_exit */
void print_error_and_exit(const int error_code, char *description) {
  printf("Hiba: %d - %s\n", error_code, description);
  exit(1);
}
