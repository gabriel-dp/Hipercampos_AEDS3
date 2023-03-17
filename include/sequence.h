#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "pointlib.h"

typedef struct {
    int length;
    Point* data;
} Sequence;

Sequence createSequence(int length);
void addPointToSequence(Sequence*, Point);
void restoreSequence(Sequence*, int);
void printSequence(Sequence*);
void copySequence(Sequence*, Sequence*);
void searchSequences(int, Point[], Sequence*, Sequence*, Point, Point);
Sequence getLongestPath(Sequence*, Point, Point);

#endif