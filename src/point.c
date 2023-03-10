#include "point.h"

#include <stdlib.h>

Point* createPointsArray(int length) {
    Point* newArray = (Point*)(malloc(length * sizeof(Point)));
    return newArray;
}