#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "pointlib.h"

typedef struct {
    Point *points;
    int length;
} Sequence;

typedef struct {
    int connections;
    int indexNext;
} Connection;

Sequence createSequence(int);
void addToSequence(Sequence *, Point);
void printSequence(Sequence *);
void freeSequence(Sequence *);
Sequence getLongestPath(Sequence *, Point, Point);

#endif