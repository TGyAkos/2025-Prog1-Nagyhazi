//
// Created by User01 on 11/13/2025.
//

#include "morze.h"

Node *init_node(void) {
  Node *new = malloc(sizeof(Node));
  new->character = '\0';
  new->dot = NULL;
  new->dash = NULL;
  return new;
}
char find_char(Node *start, char *code) {
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
      printf("error");
      break;
    }
  }
  // TODO add error case if current is NULL pointer
  return current->character;
}

void add_generate(Node **start, const char *code, const char character) {
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
      printf("error");
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

void dump_tree(Node *start) {
  // TODO add recursive dump function
}
