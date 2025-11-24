//
// Created by User01 on 11/13/2025.
//

#ifndef NAGYHAZI_FILE_HANDLING_H
#define NAGYHAZI_FILE_HANDLING_H

#include "morse.h"

#include "debugmalloc.h"
#include <stdlib.h>

/**
 * Reads morse code definitions from a file and builds a morse code binary tree
 * The file should contain lines with format: character morse_code
 * Each line consists of a single character, a space, and its morse code (dots and dashes)
 * For example: a .- b -.. c -.-.
 * @param start Pointer to the root node of the morse tree to be populated
 * @param filename Path to the file containing morse code definitions
 */
void file_to_morse_tree(Node **start, char *filename);

/**
 * Writes text content to a file, creating the file if it does not exist
 * If the file already exists, the function will exit with an error
 * @param text Text content string to be written to the file
 * @param filename Path where the file should be created and written to
 */
void write_to_file(char *text, char *filename);

/**
 * Reads all lines from a file into a single dynamically allocated string
 * Preserves newline characters from the file in the returned string
 * Removes carriage return characters that may be present on Windows systems
 * @param filename Path to the file to be read
 * @return String containing all file contents, or NULL if file cannot be opened
 */
char *read_all_lines(char *filename);

/**
 * Removes newline and carriage return characters from a string
 * Replaces '\\n' and '\\r' characters with spaces to clean up text
 * Modifies the string in place by creating a new cleaned string
 * @param str Pointer to a string pointer to be modified with cleaned content
 */
void remove_new_line_chars(char **str);

#endif // NAGYHAZI_FILE_HANDLING_H
