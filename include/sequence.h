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
} SequenceList;

typedef struct {
    Point *data;
    int length;
} SequenceArray;

SequenceList createSequenceList();
SequenceArray createSequenceArray(int);
void addSequenceList(SequenceList *, Point);
void popSequenceList(SequenceList *);
void printSequenceList(SequenceList *);
void printSequenceArray(SequenceArray *);
void copySequenceListToArray(SequenceList *, SequenceArray *);
void searchSequences(int, Point[], SequenceList *, SequenceArray *, Point, Point);
SequenceArray getLongestPath(SequenceArray *, Point, Point);

#endif