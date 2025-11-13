//
// Created by User01 on 11/13/2025.
//

#ifndef NAGYHAZI_MORZE_H
#define NAGYHAZI_MORZE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Node {
  char character;
  struct Node *dot;
  struct Node *dash;
} Node;

Node *init_node(void);
void try_add_node(Node** node);
char find_char(Node *start, char* code);
void add_generate(Node **start, const char * code, char character);

void dump_tree(Node *start);

#endif // NAGYHAZI_MORZE_H
