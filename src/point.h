#ifndef POINT_H
#define POINT_H

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

// Functions used in files.c
Sequence createSequence(int length);

#endif