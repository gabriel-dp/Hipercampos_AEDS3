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

// Functions used in main.c
void printSequence(Sequence);
void sortSequenceByY(Sequence);
Sequence getLongestPath(Sequence, Coordinate, Coordinate);

// Functions used in pointio.c
Sequence createSequence(int length);

// Functions used just inside sequence.c
int validPoint(Point, Point, Coordinate, Coordinate);
void addPointToSequence(Sequence*, Point);
void restoreSequence(Sequence*, int);
void copySequence(Sequence, Sequence*);
void searchSequences(int, Point[], Sequence*, Sequence*, Coordinate, Coordinate);

#endif