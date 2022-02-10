#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include "stdbool.h"

#include "functions.h"

bool argumentCheck(int argc, char *argv[], int *port);

int main(int argc, char *argv[]) {
  int PORT;

  if(argumentCheck(argc, argv, &PORT)) {
    printf("PORT: %d\n", PORT);
  } else {
    printf("ERROR\n");
  }

  getCPUInfo();
  getHostname();
  getCPUActualLoad();

  return 0;
}

bool argumentCheck(int argc, char *argv[], int *port) {
  if(argc != 2) {
    return false;
  } else {
    char *p;
    *port = strtol(argv[1], &p, 10);

    if (*p != '\0') {
      return false;
    }
    return true;

  }
}