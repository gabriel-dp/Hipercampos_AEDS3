#ifndef POINTIO_H
#define POINTIO_H

#include "pointlib.h"
#include "sequence.h"

void sortSequenceByY(Sequence*);
void throwError(char*, char*);
Sequence getPointsInput(char*, Point*, Point*);
void saveLongestPathLengthOutput(char*, int);
void saveResultsData(char*, int, int, long double);

#endif