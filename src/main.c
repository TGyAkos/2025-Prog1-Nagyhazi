//
// Created by User01 on 11/13/2025.
//

#ifdef DEBUG_MALLOC
#include "debugmalloc.h"
#endif // DEBUG_MALLOC

#include "file_handling.h"
#include "morse.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
#ifdef ENABLE_TESTS
#include "tests.h"
  run_all_tests();
  return 0;
#endif // ENABLE_TESTS
  int is_reverse = 0;
  if (strcmp(argv[1], "-r") == 0)
    is_reverse = 1;

  if (argc < 3 && !is_reverse) {
    print_error_and_exit(6, "Kerem adja meg a kodtablat es a forditando fajlt is\n"
                            "Pl: ./morze.exe ./t_codetable.txt ./t_text.txt\n");
  } else if (argc < 4 && is_reverse) {
    print_error_and_exit(7, "Kerem adja meg a kodtablat es a forditando fajlt is\n"
                            "Pl: ./morze.exe -r ./t_codetable.txt ./t_text.txt\n");
  }

  char *out_filename = malloc((strlen("./result.txt") + 1) * sizeof(char));
  strcpy(out_filename, "./result.txt");
  if (argc > 2) {
    free(out_filename);
    out_filename = malloc((strlen(argv[argc - 1]) + 1) * sizeof(char));
    strcpy(out_filename, argv[argc - 1]);
  }


  Node *start = init_node();
  char *text_content = read_all_lines(argv[2 + is_reverse]);
  file_to_morse_tree(&start, argv[1 + is_reverse]);

  char *coded_text = is_reverse ? decode_morse_text(start, text_content)
                                : encode_text(start, text_content);

  const int write_rtn = write_to_file(coded_text, out_filename);
  if (write_rtn == 0)
    printf("Sikeres forditas %s -> %s\n", argv[2 + is_reverse], out_filename);

  free(coded_text);
  free(out_filename);
  free(text_content);
  free_tree(start);
  free(start);

  if (write_rtn == 1)
    print_error_and_exit(4, "A kimeneti fajl mar letezik");

  return 0;
}