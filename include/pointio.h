#ifndef POINTIO_H
#define POINTIO_H

#include "sequence.h"

// Functions used in main.c
Sequence getPointsInput(char*, Point*, Point*);
void saveLongestLengthOutput(char*, int);

// Functions used only in pointio.c
void throwError(char*, char*);

#endif