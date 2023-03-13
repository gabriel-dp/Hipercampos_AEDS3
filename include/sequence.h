#ifndef SEQUENCE_H
#define SEQUENCE_H

typedef int Coordinate;

typedef struct {
    Coordinate x, y;
} Point;

typedef struct {
    int length;
    Point* data;
} Sequence;

typedef struct {
    Coordinate i, j;
} Vector;

// Functions used in main.c
void printSequence(Sequence);
Sequence getLongestPath(Sequence, Point, Point);

// Functions used in pointio.c
Sequence createSequence(int length);

// Functions used only inside sequence.c
int relativePosition(Point, Point, Point);
int validPoint(Point, Point, Point, Point);
void addPointToSequence(Sequence*, Point);
void restoreSequence(Sequence*, int);
void copySequence(Sequence, Sequence*);
void sortSequenceByY(Sequence);
void searchSequences(int, Point[], Sequence*, Sequence*, Point, Point);

#endif