#ifndef POINT_H
#define POINT_h

typedef struct {
    int x, y;  // Coordinates
} Point;

Point* getPointsFromInput(char*, int*, int*, int*);

#endif