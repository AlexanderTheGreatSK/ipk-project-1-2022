//
// Created by alex on 10. 2. 2022.
//

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

void getHostname();
void getCPUInfo();
void getCPUActualLoad();

#endif //IPK_PROJECT_1_2022_FUNCTIONS_H

