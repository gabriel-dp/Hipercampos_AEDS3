#include "pointio.h"

#include <stdio.h>
#include <stdlib.h>

void throwError(char* type, char* message) {
    printf("%s ERROR - %s\n", type, message);
    exit(EXIT_FAILURE);
}

Sequence getPointsFromInput(char* path, Coordinate* xa, Coordinate* xb) {
    FILE* file = fopen(path, "r");
    if (file == NULL) throwError("INPUT", "Cannot read file");

    int length;
    fscanf(file, "%d %d %d", &length, xa, xb);

    Sequence sequence = createSequence(length);

    for (int i = 0; i < sequence.length; i++) {
        Point newPoint;
        if (fscanf(file, "%d %d", &newPoint.x, &newPoint.y) != 2) {
            throwError("INPUT", "Too few points in file");
        }
        sequence.data[i] = newPoint;
    }

    return sequence;
}