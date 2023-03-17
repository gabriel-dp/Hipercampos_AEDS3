#ifndef POINTLIB_H
#define POINTLIB_H

typedef int Coordinate;

typedef struct {
    Coordinate x, y;
} Point;

typedef struct {
    Coordinate i, j;
} Vector;

int relativePosition(Point, Point, Point);
int validPoint(Point, Point, Point, Point);

#endif