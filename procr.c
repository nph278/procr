#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "procr.h"

#define usage "Usage: procr [pid]\n"

int main(int argc, char **argv) {

  // No PID
  if (argc == 1) {
    printf(usage);
    return 1;
  }

  // Too many arguments
  if (argc > 2) {
    printf(usage);
    return 1;
  }

  // Valid usage

  // Check if proccess directory exists (PID is valid)
  char proccess_path[12];
  strcpy(proccess_path, "/proc/");
  strcat(proccess_path, argv[1]);
  DIR *proccess_dir;
  proccess_dir = opendir(proccess_path);

  if (proccess_dir) {
    closedir(proccess_dir);

    // Get PID
    printf("PID (Process ID): %s\n", argv[1]);

    // Get SID
    char session_id[50];
    read_process_file(proccess_path, "sessionid", session_id);
    printf("SID (Session ID): %s\n", session_id);

    // Get cmdline
    char cmd_line[255];
    read_process_file(proccess_path, "cmdline", cmd_line);
    printf("Command Line: %s\n", cmd_line);

    return 0;
  } else {
    printf("Error reading from /proc/%s. (invalid PID)\n", argv[1]);
    return 1;
  }
}
