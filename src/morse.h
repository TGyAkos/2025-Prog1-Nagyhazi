//
// Created by User01 on 11/13/2025.
//

#ifndef NAGYHAZI_MORSE_H
#define NAGYHAZI_MORSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debugmalloc.h"

typedef struct Node {
  char character;
  struct Node *dot;
  struct Node *dash;
} Node;

typedef struct Split_str {
  int len;
  char **arr;
} Split_str;

char *encode_text(Node *start, char *text);
char *encode_word(Node *start, char *word);
char *encode_char(Node *start, char character);

char *decode_morse_text(Node *start, char *morse_text);
char *decode_morse_word(Node *start, char *morse_word);
char decode_morse_char(Node *start, char *code);

// String splitter
Split_str *split_str(const char *arr, char delim);
void free_split_str(Split_str *split_str);
char *flatten_split_str(Split_str *split_str, char *delim);

// Basic morse binary tree functions
Node *init_node(void);
void try_add_node(Node **node);
void add_generate_morse(Node **start, const char *code, char character);
void free_tree(Node *start);

// Debug functions
void dump_tree(Node *start);
void dump_node(Node *start, int counter);

#endif // NAGYHAZI_MORSE_H
