#ifndef IPK_PROJECT_1_2022_FUNCTIONS_H
#define IPK_PROJECT_1_2022_FUNCTIONS_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct {
  int user;
  int nice;
  int system;
  int idle;
  int iowait;
  int irq;
  int softirq;
  int steal;
} CPULoad;

/*
 * It will set given pointer to string
 * which contains from hostname of your computer
 *
 * @param pointer to pointer char
 */
void getHostname(char **name);

/*
 * It will set given pointer to string
 * which contains from your CPU model name
 *
 * @param pointer to pointer char
 */
void getCPUInfo(char **name);

/*
 * It will calculate current load of your CPU
 *
 * @return integer which represents current CPU load in percentage
 */
int getCPUActualLoad();

#endif

