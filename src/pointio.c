#include "../include/pointio.h"

#include <stdio.h>
#include <stdlib.h>

#include "../include/sequence.h"

void throwError(char* type, char* message) {
    printf("%s ERROR - %s\n", type, message);
    exit(EXIT_FAILURE);
}

Sequence getPointsInput(char* inputPath, Point* a, Point* b) {
    FILE* inputFile = fopen(inputPath, "r");
    if (inputFile == NULL) throwError("INPUT", "Cannot read file");

    // First line contains the number of points and the X coordinate of A and B
    int length;
    fscanf(inputFile, "%d %d %d", &length, &(a->x), &(b->x));

    // Y coordinate of A and B is locked at 0
    a->y = 0;
    b->y = 0;

    // Creates sequence and fill it with the points from the input file
    Sequence sequence = createSequence(length);
    for (int i = 0; i < sequence.length; i++) {
        Point newPoint;
        if (fscanf(inputFile, "%d %d", &newPoint.x, &newPoint.y) != 2) {
            throwError("INPUT", "Error reading the points");
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