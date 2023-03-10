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

void addPointSortedY(Point newPoint, Point** pointsArray, int total) {
    int index = 0;

    // Find array index to put the new point
    while (index < total && newPoint.y >= (*pointsArray)[index].y) {
        index++;
    }

    // Dislocates all elements after "index" to free that position
    for (int i = total; i >= index; i--) {
        (*pointsArray)[i + 1] = (*pointsArray)[i];
    }

    (*pointsArray)[index] = newPoint;
}

void getPointsFromInput(char* path, Point** points, int* totalPoints, int* xa, int* xb) {
    FILE* file = fopen(path, "r");
    if (file == NULL) inputError("Cannot read file");

    fscanf(file, "%d %d %d", totalPoints, xa, xb);

    *points = createPointsArray(*totalPoints);

    for (int i = 0; i < *totalPoints; i++) {
        Point newPoint;
        if (fscanf(file, "%d %d", &newPoint.x, &newPoint.y) != 2) {
            inputError("Missing points");
        }
        addPointSortedY(newPoint, points, i);
    }
}