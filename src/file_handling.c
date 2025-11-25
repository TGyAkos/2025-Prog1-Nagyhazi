//
// Created by User01 on 11/13/2025.
//

#include "file_handling.h"

/** @copydoc file_to_morse_tree */
void file_to_morse_tree(Node **start, char *filename) {
  char *lines = read_all_lines(filename);
  Split_str *arr = split_str(lines, '\n');
  free(lines);
  for (int i = 0; i < arr->len; ++i) {
    Split_str *code = split_str(arr->arr[i], ' ');
    if (code->len != 2) {
      free_split_str(code);
      free_split_str(arr);
      free_tree(*start);
      free(*start);
      print_error_and_exit(3, "Helytelen kodtabla formatum");
    }
    add_generate_morse(start, code->arr[1], code->arr[0][0]);
    free_split_str(code);
  }
  free_split_str(arr);
}

/** @copydoc write_to_file */
int write_to_file(char *text, char *filename) {
  FILE *checkfp = fopen(filename, "r");
  if (checkfp != NULL) {
    fclose(checkfp);
    return 1;
  }
  FILE *fptr = fopen(filename, "w");
  fprintf(fptr, "%s", text);
  fclose(fptr);
  return 0;
}

/** @copydoc remove_new_line_chars */
void remove_new_line_chars(char **str) {
  int ct = 0;
  int ct_no_new_lines = 0;
  while ((*str)[ct++] != '\0')
    if ((*str)[ct] != '\n')
      ++ct_no_new_lines;

  int ct_final = 0;
  char *final = malloc((ct_no_new_lines + 1) * sizeof(char));
  for (int i = 0; i < ct_no_new_lines; ++i)
    if ((*str)[ct_no_new_lines] == '\n')
      final[ct_final++] = (*str)[ct_no_new_lines];
  final[ct_no_new_lines] = '\0';

  free(*str);
  *str = final;
}

/** @copydoc read_all_lines */
char *read_all_lines(char *filename) {
  FILE *fptr = fopen(filename, "r");
  if (fptr == NULL) {
    fclose(fptr);
    print_error_and_exit(6, "Ilyen nevu fajl nem letezik");
  }
  int buffersize = 31;
  char *buff = malloc(buffersize * sizeof(char));
  buff[0] = '\0';
  char tmp[31];

  while (fgets(tmp, sizeof(tmp), fptr) != NULL) {
    if (buffersize + strlen(tmp) + 1 > buffersize) {
      buffersize += 31;
      char *new_buff = malloc(buffersize * sizeof(char));
      strcpy(new_buff, buff);
      free(buff);
      buff = new_buff;
    }
    strcat(buff, tmp);
  }

  int ct = 0;
  while (buff[ct] != '\0')
    if (buff[ct] != '\r')
      ++ct;

  int ct_final = 0;
  char *final = malloc((ct + 1) * sizeof(char));
  for (int i = 0; i < ct; ++i)
    if (buff[ct] != '\r')
      final[ct_final++] = buff[i];
  final[ct] = '\0';

  free(buff);
  fclose(fptr);
  return final;
}
