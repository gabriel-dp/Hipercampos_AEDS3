#include "point.h"

#include <stdio.h>
#include <stdlib.h>

Point* createPointsArray(int length) {
    Point* newArray = (Point*)(malloc(length * sizeof(Point)));
    return newArray;
}

void inputError(char* message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Point* getPointsFromInput(char* path, int* totalPoints, int* xa, int* xb) {
    FILE* file = fopen(path, "r");
    if (file == NULL) inputError("ERROR - Cannot read file");

    fscanf(file, "%d %d %d", totalPoints, xa, xb);

    Point* newPoints = createPointsArray(*totalPoints);

    for (int i = 0; i < *totalPoints; i++) {
        if (fscanf(file, "%d %d", &(newPoints[i].x), &(newPoints[i].y)) != 2) {
            inputError("ERROR - Missing points");
        }
    }

    return newPoints;
}