#include <stdio.h>
#include <string.h>

char* read_process_file(char* proccess_path, char* lower_path, char* str) {
      char full_path[20];
      strcpy(full_path, proccess_path);
      strcat(full_path, "/");
      strcat(full_path, lower_path);
      FILE *file;
      file = fopen(full_path, "r");
      fgets(str, 255, (FILE*)file);
      fclose(file);
}
