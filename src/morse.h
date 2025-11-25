//
// Created by User01 on 11/13/2025.
//

#ifndef NAGYHAZI_MORSE_H
#define NAGYHAZI_MORSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char character;
  struct Node *dot;
  struct Node *dash;
} Node;

typedef struct Split_str {
  int len;
  char **arr;
} Split_str;

/**
 * Encodes a complete text string into morse code by encoding each word separately
 * Words in the input text are separated by spaces and encoded individually
 * The encoded words are joined with tab characters in the output
 * @param start Root node of the morse code binary tree
 * @param text Text string to be encoded into morse code
 * @return Encoded morse code string with words separated by tabs, or NULL on error
 */
char *encode_text(Node *start, char *text);

/**
 * Encodes a single word into morse code by encoding each character
 * Characters within the word are encoded and separated by spaces in the output
 * @param start Root node of the morse code binary tree
 * @param word Word string to be encoded into morse code
 * @return Encoded morse code string with characters separated by spaces, or NULL on error
 */
char *encode_word(Node *start, char *word);

/**
 * Encodes a single character into its morse code representation
 * Recursively traverses the morse tree to find the character and returns its path
 * @param start Root node of the morse code binary tree
 * @param character Single character to be encoded into morse code
 * @return Morse code string (dots and dashes) representing the character, or NULL if not found
 */
char *encode_char(Node *start, char character);

/**
 * Decodes a complete morse code text string back into plain text
 * Morse words in the input are separated by tabs and decoded individually
 * The decoded words are joined with spaces in the output
 * @param start Root node of the morse code binary tree
 * @param morse_text Morse code text string to be decoded
 * @return Decoded plain text string with words separated by spaces, or NULL on error
 */
char *decode_morse_text(Node *start, char *morse_text);

/**
 * Decodes a morse code word back into a plain text word
 * Individual morse characters within the word are separated by spaces
 * @param start Root node of the morse code binary tree
 * @param morse_word Morse code word string to be decoded
 * @return Decoded plain text word, or NULL on error
 */
char *decode_morse_word(Node *start, char *morse_word);

/**
 * Decodes a single morse code character into its plain text representation
 * Traverses the morse tree following the dot (.) and dash (-) pattern
 * @param start Root node of the morse code binary tree
 * @param code Morse code string containing dots and dashes
 * @return Decoded character, or null character if morse code not found in tree
 */
char decode_morse_char(Node *start, char *code);

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

/**
 * Initializes a new morse tree node with default values
 * Allocates memory for a Node and sets all fields to empty/NULL values
 * The character is set to null terminator and both pointers are set to NULL
 * @return Pointer to newly allocated and initialized Node structure
 */
Node *init_node(void);

/**
 * Attempts to allocate a new node if the target pointer is NULL
 * If the pointer already points to allocated memory, the function does nothing
 * Used as a helper to safely create child nodes during tree construction
 * @param node Pointer to a node pointer that may need allocation
 */
void try_add_node(Node **node);

/**
 * Generates morse code nodes in the tree based on a morse code pattern
 * Traverses the tree following the dot (.) and dash (-) characters in the code
 * Creates new nodes as needed and stores the character at the final position
 * @param start Pointer to the root node of the morse code tree
 * @param code Morse code pattern string containing dots and dashes
 * @param character Character to be stored at the end of the morse code path
 */
void add_generate_morse(Node **start, const char *code, char character);

/**
 * Recursively frees all memory allocated for a morse code tree
 * Performs depth-first traversal to deallocate all nodes in both branches
 * @param start Root node of the morse tree to be freed
 */
void free_tree(Node *start);

/**
 * Prints a visual representation of the morse code tree structure
 * Useful for debugging and verifying the contents of the tree
 * @param start Root node of the tree to be displayed
 */
void dump_tree(Node *start);

/**
 * Recursively prints morse tree nodes with indentation based on depth
 * Helper function for dump_tree that handles the recursive traversal
 * @param start Current node being printed
 * @param counter Indentation level counter for formatting output
 */
void dump_node(Node *start, int counter);

/**
 * Prints an error message to standard output and terminates the program
 * Used for critical errors that prevent program continuation
 * @param error_code Numeric error code identifying the error type
 * @param description Human-readable error description message
 */
void print_error_and_exit(int error_code, char *description);

#endif // NAGYHAZI_MORSE_H
