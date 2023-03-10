#ifndef POINT_H
#define POINT_h

typedef struct {
    int x, y;  // Coordinates
} Point;

Point* createPointsArray(int);
int isInside(Point, Point, Point, Point);

#endif