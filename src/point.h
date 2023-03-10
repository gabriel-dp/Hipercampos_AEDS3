#ifndef POINT_H
#define POINT_h

typedef struct {
    int x, y;  // Coordinates
} Point;

void getPointsFromInput(char*, Point*[], int*, int*, int*);
void sortPointsByY(Point[], int);

#endif