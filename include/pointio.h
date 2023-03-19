#ifndef POINTIO_H
#define POINTIO_H

#include "pointlib.h"
#include "sequence.h"

void sortPointsArrayByY(PointsArray*);
void throwError(char*, char*);
PointsArray getPointsInput(char*, Point*, Point*);
void saveLongestLengthOutput(char*, int);
void saveResultsData(char*, int, int, long double);

#endif