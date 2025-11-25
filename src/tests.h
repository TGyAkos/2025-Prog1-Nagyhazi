//
// Created by User01 on 11/17/2025.
//

#ifndef NAGYHAZI_TESTS_H
#define NAGYHAZI_TESTS_H

#ifndef NDEBUG
#include "debugmalloc.h"
#endif // NDEBUG

#include "file_handling.h"
#include "morse.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_all_tests(void);

// Mock functions
Node *mock_tree(void);
Split_str *mock_split_str(void);

// Morse tests
void test_encode_text(void);
void test_encode_word(void);
void test_encode_char(void);

void test_decode_text(void);
void test_decode_word(void);
void test_decode_char(void);

// String splitter tests
void test_split_str(void);
void test_free_split_str(void);
void test_flatten_split_str(void);

// Test basic morse binary tree functions
void test_init_node(void);
void test_add_generate_morse(void);
void test_free_tree(void);

// File Handling tests
void test_file_to_morse_tree(void);
void test_write_to_file(void);
void test_read_all_lines(void);
void test_remove_new_lines_chars(void);

#endif // NAGYHAZI_TESTS_H
