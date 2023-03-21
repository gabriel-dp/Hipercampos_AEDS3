#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "pointlib.h"

typedef struct {
    Point *points;
    int length;
} Sequence;

Sequence createSequence(int);
void addToSequence(Sequence *, Point);
void printSequence(Sequence *);
Sequence getLongestPath(Sequence *, Point, Point);

#endif