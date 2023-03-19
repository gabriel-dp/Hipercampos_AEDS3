#ifndef POINTLIB_H
#define POINTLIB_H

typedef int Coordinate;

typedef struct {
    Coordinate x, y;
} Point;

typedef struct {
    Point *data;
    int length;
} PointsArray;

typedef struct {
    Coordinate i, j;
} Vector;

PointsArray createPointsArray(int);
void printPointsArray(PointsArray *);
int relativePosition(Point, Point, Point);
int validPoint(Point, Point, Point, Point);

#endif