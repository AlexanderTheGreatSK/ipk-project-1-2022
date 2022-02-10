//
// Created by alex on 10. 2. 2022.
//

#include "functions.h"

void cpuLoadData(CPULoad *cpuLoad, char data[100]);
void debugPrintStructure(CPULoad *cpuLoad);

void getHostname() {
  system("cat /proc/sys/kernel/hostname");
}

void getCPUInfo() {
  system("lscpu | grep \"Model name:\" | sed -r 's/Model name:\\s{1,}//g'");
}
void getCPUActualLoad() {
  FILE *fp;
  char path[100];


  CPULoad *prev = malloc(sizeof(CPULoad));
  CPULoad *curr = malloc(sizeof(CPULoad));
  char *p;

  fp = popen("cat /proc/stat | grep \"cpu \" | awk '{print $2, $3, $4, $5, $6, $7, $8, $9}'", "r");

  while (fgets(path, 100, fp) != NULL)
    printf("%s", path);

  cpuLoadData(prev, path);
  debugPrintStructure(prev);

  sleep(1);

  fp = popen("cat /proc/stat | grep \"cpu \" | awk '{print $2, $3, $4, $5, $6, $7, $8, $9}'", "r");

  while (fgets(path, 100, fp) != NULL)
    printf("%s", path);

  cpuLoadData(curr, path);
  debugPrintStructure(curr);

  int prevIdle = prev->idle + prev->iowait;
  int idle = curr->idle + curr->iowait;

  int prevNonIdle = prev->user + prev->nice + prev->system + prev->irq + prev->softirq + prev->steal;
  int nonIdle = curr->user + curr->nice + curr->system + curr->irq + curr->softirq + curr->steal;

  int prevTotal = prevIdle + prevNonIdle;
  int total = idle + nonIdle;

  int totalFinal = total - prevTotal;
  int idleFinal = idle - prevIdle;

  float cpuPercentage = (float)(totalFinal - idleFinal)/totalFinal*100;

  printf("CPU percentage = %f %\n", cpuPercentage);

  free(prev);
  prev = NULL;

  free(curr);
  curr = NULL;

}

void cpuLoadData(CPULoad *cpuLoad, char data[100]) {
  char *token;
  char *p;

  token = strtok(data, " ");
  cpuLoad->user = strtol(token, &p ,10);

  token = strtok(NULL, " ");
  cpuLoad->nice = strtol(token, &p ,10);

  token = strtok(NULL, " ");
  cpuLoad->system = strtol(token, &p ,10);

  token = strtok(NULL, " ");
  cpuLoad->idle = strtol(token, &p ,10);

  token = strtok(NULL, " ");
  cpuLoad->iowait = strtol(token, &p ,10);

  token = strtok(NULL, " ");
  cpuLoad->irq = strtol(token, &p ,10);

  token = strtok(NULL, " ");
  cpuLoad->softirq = strtol(token, &p ,10);

  token = strtok(NULL, " ");
  cpuLoad->steal = strtol(token, &p ,10);
}

void debugPrintStructure(CPULoad *cpuLoad) {
  printf("user : %d\n", cpuLoad->user);
  printf("nice : %d\n", cpuLoad->nice);
  printf("system : %d\n", cpuLoad->system);
  printf("idle : %d\n", cpuLoad->idle);
  printf("iowait : %d\n", cpuLoad->iowait);
  printf("irq : %d\n", cpuLoad->irq);
  printf("softirq : %d\n", cpuLoad->softirq);
  printf("steal : %d\n", cpuLoad->steal);
}
