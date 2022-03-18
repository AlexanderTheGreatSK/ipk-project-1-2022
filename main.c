#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <signal.h>

#include "functions.h"

int PORT;

/*
 * Function for checking if arguments are right
 *
 * @param integer which represents number of given arguments
 * @param array of given arguments
 * @param pointer to integer which represents given port
 *
 * @return true if arguments are correct, otherwise false
 */
bool argumentCheck(int argc, char *argv[], int *port);

/*
 * Function for checking if request is right
 *
 * @param received request
 * @param pointer to integer which represents which function will be executed
 *
 * @return status code, 200 of success, otherwise 400
 */
int requestCheck(uint8_t *request, int *function);

/*
 * Function for generating response message
 *
 * @param answer to client
 *
 * @return response message
 */
char* responseMsg(char *response);

/*
 * function for catching kill signal
 *
 * @param signal
 */
void catchSignal(int signal) {
  if (signal == SIGINT) {
    close(PORT);
    exit(0);
  }
}

int main(int argc, char *argv[]) {
  signal(SIGINT, catchSignal);

  struct sockaddr_in serverAddress;
  int listenServer, n;
  uint8_t buffer[1000];
  uint8_t reciveLine[1000];
  int connFD;
  int function;
  int statusCode;

  if(argumentCheck(argc, argv, &PORT)) {
  } else {
    printf("ERROR\n");
    return 1;
  }

  if((listenServer = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("ERROR SOCKET\n");
    return 1;
  }

  bzero(&serverAddress, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
  serverAddress.sin_port = htons(PORT);

  if((bind(listenServer, (struct sockaddr*) &serverAddress, sizeof(serverAddress))) < 0) {
    printf("BIND ERROR\n");
  }

  if((listen(listenServer, 10)) < 0) {
    printf("ERROR LISTEN\n");
  }

  setsockopt(listen, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));

  while(1) {

    fflush(stdout);
    connFD = accept(listenServer, (struct sockaddr*) NULL, NULL);

    memset(reciveLine,0, 1000);

    while((n=read(connFD, reciveLine, 1000-1)) > 0) {

      statusCode = requestCheck(reciveLine, &function);

      if(statusCode == 200) {
        if(function == 0) {
          char *name = malloc(sizeof(char) * 100);
          getHostname(&name);
          send(connFD, responseMsg(name), 2000, 1);
        } else if(function == 1) {
          char *name = malloc(sizeof(char) * 100);
          getCPUInfo(&name);
          send(connFD, responseMsg(name), 2000, 1);
        } else if(function == 2) {
          int cpuPercentage = getCPUActualLoad();
          char *str = malloc(sizeof(char) * 10);
          sprintf(str, "%d%%", cpuPercentage);
          send(connFD, responseMsg(str), 2000, 1);
        }
      } else {
        snprintf((char *) buffer, sizeof(buffer), "HTTP/1.1 404 Not Found\r\n\r\n");
      }

      if(reciveLine[n-1] == '\n') {
        break;
      }
      memset(reciveLine, 0, 1000);
    }

    if(n < 0) {
      return 1;
    }

    write(connFD, (char*)buffer, strlen((char *)buffer));
    close(connFD);

  }


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

int requestCheck(uint8_t *request, int *function) {
  char *token;

  token = strtok(request, " ");

  if(strcmp(token, "GET") != 0) {
    return 400;
  }

  token = strtok(NULL, " ");

  if(strcmp(token, "/hostname") == 0) {
    *function = 0;
  } else if(strcmp(token, "/cpu-name") == 0) {
    *function = 1;
  } else if(strcmp(token, "/load") == 0) {
    *function = 2;
  } else {
    *function = -1;
    return 400;
  }

  return 200;
}

char* responseMsg(char *response) {
  int len = strlen(response);

  char *reply = malloc(sizeof(char) * 1000);

  sprintf(reply, "HTTP/1.1 200 OK\n"
                  "Content-Type: text/plain\n"
                  "Content-Length: %d\n"
                  "Connection: close\n\n%s", len, response);

  return reply;
}