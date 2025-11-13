//
// Created by User01 on 11/13/2025.
//

#ifndef NAGYHAZI_FILE_HANDLING_H
#define NAGYHAZI_FILE_HANDLING_H

#include "morse.h"

#include "debugmalloc.h"
#include <stdlib.h>

void file_to_morse_tree(Node **start, char *filename);
void write_to_file(char *text, char *filename);

char *read_all_lines(char *filename);
void remove_new_line_chars(char **str);

#endif // NAGYHAZI_FILE_HANDLING_H
