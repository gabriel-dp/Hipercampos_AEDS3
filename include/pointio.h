#ifndef POINTIO_H
#define POINTIO_H

#include "pointlib.h"
#include "sequence.h"

void sortSequenceArrayByY(SequenceArray*);
void throwError(char*, char*);
SequenceArray getPointsInput(char*, Point*, Point*);
void saveLongestLengthOutput(char*, int);

#endif