#ifndef POINT_H
#define POINT_H

typedef int Coordinate;

typedef struct {
    Coordinate x, y;
} Point;

typedef struct {
    int length;
    Point* data;
} PointArray;

PointArray createPointArray(int length);
void getPointsFromInput(PointArray*, Coordinate*, Coordinate*, char*);
void sortPointsByY(Point[], int);
int validPoint(Point, Point, Coordinate, Coordinate);

#endif