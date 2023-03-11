#include "../include/pointio.h"

#include <stdio.h>
#include <stdlib.h>

#include "../include/sequence.h"

void throwError(char* type, char* message) {
    printf("%s ERROR - %s\n", type, message);
    exit(EXIT_FAILURE);
}

Sequence getPointsInput(char* inputPath, Coordinate* xa, Coordinate* xb) {
    FILE* inputFile = fopen(inputPath, "r");
    if (inputFile == NULL) throwError("INPUT", "Cannot read file");

    int length;
    fscanf(inputFile, "%d %d %d", &length, xa, xb);

    Sequence sequence = createSequence(length);

    for (int i = 0; i < sequence.length; i++) {
        Point newPoint;
        if (fscanf(inputFile, "%d %d", &newPoint.x, &newPoint.y) != 2) {
            throwError("INPUT", "Too few points in file");
        }
        sequence.data[i] = newPoint;
    }

    fclose(inputFile);

    return sequence;
}

void saveLongestLengthOutput(char* outputPath, int value) {
    FILE* outputFile = fopen(outputPath, "w");
    if (outputFile == NULL) throwError("OUTPUT", "Cannot write file");

    fprintf(outputFile, "%d", value);

    fclose(outputFile);
}