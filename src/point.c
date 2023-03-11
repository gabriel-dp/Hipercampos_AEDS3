#include "point.h"

#include <stdio.h>
#include <stdlib.h>

PointArray createPointArray(int length) {
    PointArray newArray;
    newArray.data = (Point*)(malloc(length * sizeof(Point)));
    newArray.length = length;
    return newArray;
}

void inputError(char* message) {
    printf("INPUT ERROR - %s\n", message);
    exit(EXIT_FAILURE);
}

void getPointsFromInput(PointArray* points, Coordinate* xa, Coordinate* xb, char* path) {
    FILE* file = fopen(path, "r");
    if (file == NULL) inputError("Cannot read file");

    int length;
    fscanf(file, "%d %d %d", &length, xa, xb);

    *points = createPointArray(length);

    for (int i = 0; i < points->length; i++) {
        Point newPoint;
        if (fscanf(file, "%d %d", &newPoint.x, &newPoint.y) != 2) {
            inputError("Missing points");
        }
        (*points).data[i] = newPoint;
    }

    sortPointsByY(points->data, points->length);
}

// Selection sort algorythm (efficient to few elements)
void sortPointsByY(Point points[], int length) {
    int min;
    for (int i = 0; i < length; i++) {
        min = i;
        for (int j = i + 1; j < length; j++) {
            if (points[j].y < points[min].y) {
                min = j;
            }
        }
        if (min != i) {
            Point aux = points[min];
            points[min] = points[i];
            points[i] = aux;
        }
    }
}

int validPoint(Point p, Point c, Coordinate xa, Coordinate xb) {
    return 1;
}
