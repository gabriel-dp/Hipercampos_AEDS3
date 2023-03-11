#include "point.h"

#include <stdio.h>
#include <stdlib.h>

Point* createPointsArray(int length) {
    Point* newArray = (Point*)(malloc(length * sizeof(Point)));
    return newArray;
}

void inputError(char* message) {
    printf("INPUT ERROR - %s\n", message);
    exit(EXIT_FAILURE);
}

void getPointsFromInput(char* path, Point* points[], int* totalPoints, int* xa, int* xb) {
    FILE* file = fopen(path, "r");
    if (file == NULL) inputError("Cannot read file");

    fscanf(file, "%d %d %d", totalPoints, xa, xb);

    *points = createPointsArray(*totalPoints);

    for (int i = 0; i < *totalPoints; i++) {
        Point newPoint;
        if (fscanf(file, "%d %d", &newPoint.x, &newPoint.y) != 2) {
            inputError("Missing points");
        }
        (*points)[i] = newPoint;
    }
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
