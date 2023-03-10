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

void getPointsFromInput(char* path, Point** points, int* totalPoints, int* xa, int* xb) {
    FILE* file = fopen(path, "r");
    if (file == NULL) inputError("Cannot read file");

    fscanf(file, "%d %d %d", totalPoints, xa, xb);

    *points = createPointsArray(*totalPoints);

    for (int i = 0; i < *totalPoints; i++) {
        if (fscanf(file, "%d %d", &((*points)[i].x), &((*points)[i].y)) != 2) {
            inputError("Missing points");
        }
    }
}