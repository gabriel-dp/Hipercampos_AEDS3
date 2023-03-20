#ifndef POINTIO_H
#define POINTIO_H

#include "pointlib.h"
#include "sequence.h"

void sortSequenceByY(Sequence*);
void throwError(char*, char*);
Sequence getPointsInput(char*, Point*, Point*);
void saveGreatestPathLengthOutput(char*, int);

#endif