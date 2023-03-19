#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "pointlib.h"

typedef struct element_t {
    Point point;
    struct element_t *next, *previous;
} Element;

typedef struct {
    Element *first, *last;
    int length;
} Sequence;

Sequence createSequence();
void addSequence(Sequence *, Point);
void popSequence(Sequence *);
void restoreSequence(Sequence *, int);
void printSequence(Sequence *);
void copySequenceToArray(Sequence *, PointsArray *);
void searchSequences(int, Point[], Sequence *, PointsArray *, Point, Point);
PointsArray getLongestPath(PointsArray *, Point, Point);

#endif