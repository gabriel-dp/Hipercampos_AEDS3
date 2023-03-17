#ifndef RUSAGE_H
#define RUSAGE_H

#include <sys/resource.h>

long double getTimeCPU();
void printElapsedTime(long double, long double);

#endif