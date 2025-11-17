//
// Created by User01 on 11/17/2025.
//

#include "tests.h"

void run_all_tests(void) {
  test_encode_text();
  test_encode_word();
  test_encode_char();

  test_decode_text();
  test_decode_word();
  test_decode_char();

  test_split_str();
  test_free_split_str();
  test_flatten_split_str();

  test_init_node();
  test_add_generate_morse();
  test_free_tree();

  test_file_to_morse_tree();
  test_write_to_file();
  test_read_all_lines();
  test_remove_new_lines_chars();
}

Node *mock_tree(void) {

}
Split_str *mock_split_str(void) {

}

void test_encode_text(void) {}
void test_encode_word(void) {}
void test_encode_char(void) {}

void test_decode_text(void) {}
void test_decode_word(void) {}
void test_decode_char(void) {}

void test_split_str(void) {}
void test_free_split_str(void) {}
void test_flatten_split_str(void) {}

void test_init_node(void) {}
void test_add_generate_morse(void) {}
void test_free_tree(void) {}

void test_file_to_morse_tree(void) {}
void test_write_to_file(void) {}
void test_read_all_lines(void) {}
void test_remove_new_lines_chars(void) {}
