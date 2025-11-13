//
// Created by User01 on 11/13/2025.
//

#include "file_handling.h"

// TODO write error if the code table is badly formatted
void file_to_morse_tree(Node **start, char *filename) {
  char *lines = read_all_lines(filename);
  Split_str *arr = split_str(lines, '\n');
  free(lines);
  for (int i = 0; i < arr->len; ++i) {
    Split_str *code = split_str(arr->arr[i], ' ');
    add_generate_morse(start, code->arr[1], code->arr[0][0]);
    free_split_str(code);
  }
  free_split_str(arr);
}

// TODO add error if file already exists
void write_to_file(char *text, char *filename) {
  FILE *fptr = fopen(filename, "w");
  fprintf(fptr, "%s", text);
  fclose(fptr);
}

void remove_new_line_chars(char **str) {
  int ct = 0;
  while ((*str)[ct] != '\0')
    if ((*str)[ct] == '\n')
      ++ct;

  int ct_final = 0;
  char *final = malloc((ct + 1) * sizeof(char));
  for (int i = 0; i < ct; ++i)
    if ((*str)[ct] == '\n')
      final[ct_final++] = (*str)[ct];
  final[ct] = '\0';

  free(*str);
  *str = final;
}
char *read_all_lines(char *filename) {
  FILE *fptr = fopen(filename, "r");
  int buffersize = 31;
  char *buff = malloc(buffersize * sizeof(char));
  buff[0] = '\0';
  char tmp[31];

  // TODO add error if the file cannot be opened
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
