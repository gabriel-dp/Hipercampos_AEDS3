#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "point.h"

// A Sequence is a stack of Points using a linked list

typedef struct Node {
    Point point;
    struct Node *next;
} Node;

typedef struct {
    int length;
    Node *top;
} Sequence;

PointArray getLongestPath(PointArray, Coordinate, Coordinate);

#endif