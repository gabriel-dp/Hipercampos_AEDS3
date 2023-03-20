#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "pointlib.h"

typedef struct {
    Point point;
    int connections;
} Element;

typedef struct {
    Element *data;
    int length;
} Sequence;

Sequence createSequence(int);
void addToSequence(Sequence *, Point);
int getGreatestPathLength(Sequence *, Point, Point);

#endif