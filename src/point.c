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
    Point aux;
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            if (points[i].y > points[j].y) {
                aux = points[j];
                points[j] = points[i];
                points[i] = aux;
            }
        }
    }
}