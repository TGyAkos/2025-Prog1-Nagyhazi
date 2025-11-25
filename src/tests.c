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

  printf("All tests passed!\n");
}

Node *mock_tree(void) {
  Node *root = malloc(sizeof(Node));
  root->character = '\0';

  // a: .-
  root->dot = malloc(sizeof(Node));
  root->dot->character = '\0';
  root->dot->dash = malloc(sizeof(Node));
  root->dot->dash->character = 'a';
  root->dot->dash->dot = NULL;
  root->dot->dash->dash = NULL;

  // b: ..
  root->dot->dot = malloc(sizeof(Node));
  root->dot->dot->character = 'b';
  root->dot->dot->dot = NULL;
  root->dot->dot->dash = NULL;

  // c: --
  root->dash = malloc(sizeof(Node));
  root->dash->character = '\0';
  root->dash->dot = NULL;
  root->dash->dash = malloc(sizeof(Node));
  root->dash->dash->character = 'c';
  root->dash->dash->dot = NULL;
  root->dash->dash->dash = NULL;

  return root;
}

Split_str *mock_split_str(void) {
  Split_str *mock = malloc(sizeof(Split_str));
  assert(mock != NULL);
  mock->len = 3;
  mock->arr = malloc(mock->len * sizeof(char *));
  assert(mock->arr != NULL);
  mock->arr[0] = malloc((strlen("a") + 1) * sizeof(char));
  mock->arr[1] = malloc((strlen("b") + 1) * sizeof(char));
  mock->arr[2] = malloc((strlen("c") + 1) * sizeof(char));
  strcpy(mock->arr[0], "a");
  strcpy(mock->arr[1], "b");
  strcpy(mock->arr[2], "c");
  return mock;
}

void test_encode_text(void) {
  Node *tree = mock_tree();
  assert(tree != NULL);
  char *encoded = encode_text(tree, "a b c");
  assert(encoded != NULL);
  assert(strcmp(encoded, ".-\t..\t--") == 0);
  free_tree(tree);
  free(tree);
  free(encoded);
}

void test_encode_word(void) {
  Node *tree = mock_tree();
  assert(tree != NULL);
  char *encoded = encode_word(tree, "abc");
  assert(encoded != NULL);
  assert(strcmp(encoded, ".- .. --") == 0);
  free_tree(tree);
  free(tree);
  free(encoded);
}

void test_encode_char(void) {
  Node *tree = mock_tree();
  assert(tree != NULL);
  char *encoded_a = encode_char(tree, 'a');
  assert(encoded_a != NULL);
  assert(strcmp(encoded_a, ".-") == 0);
  free_tree(tree);
  free(tree);
  free(encoded_a);
}

void test_decode_text(void) {
  Node *tree = mock_tree();
  assert(tree != NULL);
  char *decoded = decode_morse_text(tree, ".-\t..\t--");
  assert(decoded != NULL);
  assert(strcmp(decoded, "a b c") == 0);
  free_tree(tree);
  free(tree);
  free(decoded);
}

void test_decode_word(void) {
  Node *tree = mock_tree();
  assert(tree != NULL);
  char *decoded = decode_morse_word(tree, ".- .. --");
  assert(decoded != NULL);
  assert(strcmp(decoded, "abc") == 0);
  free_tree(tree);
  free(tree);
  free(decoded);
}

void test_decode_char(void) {
  Node *tree = mock_tree();
  assert(tree != NULL);
  char decoded_a = decode_morse_char(tree, ".-");
  assert(decoded_a == 'a');
  char decoded_b = decode_morse_char(tree, "..");
  assert(decoded_b == 'b');
  char decoded_c = decode_morse_char(tree, "--");
  assert(decoded_c == 'c');
  free_tree(tree);
  free(tree);
}

void test_split_str(void) {
  Split_str *result = split_str("a b c", ' ');
  assert(result != NULL);
  Split_str *expected = mock_split_str();
  assert(expected != NULL);

  assert(result->len == expected->len);
  assert(strcmp(result->arr[0], expected->arr[0]) == 0);
  assert(strcmp(result->arr[1], expected->arr[1]) == 0);
  assert(strcmp(result->arr[2], expected->arr[2]) == 0);

  free_split_str(result);
  free_split_str(expected);
}

void test_free_split_str(void) {
  Split_str *s = split_str("test data split", ' ');
  assert(s != NULL);
  assert(s->len == 3);
  free_split_str(s);
}

void test_flatten_split_str(void) {
  Split_str *s = split_str("a b c", ' ');
  assert(s != NULL);
  assert(s->len == 3);
  char *flattened = flatten_split_str(s, "-");
  assert(flattened != NULL);
  assert(strcmp(flattened, "a-b-c") == 0);
  free(flattened);
  free_split_str(s);
}

void test_init_node(void) {
  Node *n = init_node();
  assert(n != NULL);
  assert(n->character == '\0');
  assert(n->dot == NULL);
  assert(n->dash == NULL);
  free(n);
}

void test_add_generate_morse(void) {
  Node *root = init_node();
  assert(root != NULL);
  add_generate_morse(&root, ".-", 'a');
  assert(root->dot != NULL);
  assert(root->dot->dash != NULL);
  assert(root->dot->dash->character == 'a');
  free_tree(root);
  free(root);
}

void test_free_tree(void) {
  Node *tree = mock_tree();
  assert(tree != NULL);
  free_tree(tree);
  free(tree);
}

void test_file_to_morse_tree(void) {
  const char *filename = "./test_codetable.txt";
  FILE *f = fopen(filename, "w");
  assert(f != NULL);
  fprintf(f, "a .-\n");
  fprintf(f, "b ..\n");
  fprintf(f, "c --");
  fclose(f);

  Node *root = init_node();
  file_to_morse_tree(&root, (char *)filename);
  assert(root != NULL);

  assert(decode_morse_char(root, ".-") == 'a');
  assert(decode_morse_char(root, "..") == 'b');
  assert(decode_morse_char(root, "--") == 'c');

  free_tree(root);
  free(root);
  remove(filename);
}

void test_write_to_file(void) {
  const char *filename = "./test_output.txt";
  remove(filename);

  write_to_file(".-  ..  --", (char *)filename);

  FILE *f = fopen(filename, "r");
  assert(f != NULL);
  char buffer[100] = {0};
  fgets(buffer, sizeof(buffer), f);
  fclose(f);

  assert(strcmp(buffer, ".-  ..  --") == 0);
  remove(filename);
}

void test_read_all_lines(void) {
  const char *filename = "./test_read_lines.txt";
  FILE *f = fopen(filename, "w");
  assert(f != NULL);
  fprintf(f, "a b c\n");
  fclose(f);

  char *content = read_all_lines((char *)filename);
  assert(content != NULL);
  assert(strstr(content, "a b c") != NULL);

  free(content);
  remove(filename);
}

void test_remove_new_lines_chars(void) {
  char *test_str = malloc(64 * sizeof(char));
  strcpy(test_str, "a b c\ntest\r\ndata");
  remove_new_line_chars(&test_str);

  assert(test_str != NULL);
  assert(strchr(test_str, '\n') == NULL);
  assert(strchr(test_str, '\r') == NULL);

  free(test_str);
}
