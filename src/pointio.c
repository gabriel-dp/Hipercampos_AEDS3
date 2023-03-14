#include "../include/pointio.h"

#include <stdio.h>
#include <stdlib.h>

#include "../include/sequence.h"

// Selection sort algorythm, great for few elements
void sortSequenceByY(Sequence sequence) {
    int min;
    for (int i = 0; i < sequence.length; i++) {
        min = i;
        for (int j = i + 1; j < sequence.length; j++) {
            if (sequence.data[j].y < sequence.data[min].y) {
                min = j;
            }
        }
        if (min != i) {
            Point aux = sequence.data[min];
            sequence.data[min] = sequence.data[i];
            sequence.data[i] = aux;
        }
    }
}

// Function to stop the program in case of I/O errors
void throwError(char* type, char* message) {
    printf("%s ERROR - %s\n", type, message);
    exit(EXIT_FAILURE);
}

// The input file contains the number of points + Ax + Bx and all other points
Sequence getPointsInput(char* inputPath, Point* a, Point* b) {
    // Try to open the input file in read mode
    FILE* inputFile = fopen(inputPath, "r");
    if (inputFile == NULL) throwError("INPUT", "Cannot read file");

    // First line contains the total number of points and the X coordinate of A and B
    int length;
    fscanf(inputFile, "%d %d %d", &length, &(a->x), &(b->x));

    // Y coordinate of A and B is locked at 0
    a->y = 0;
    b->y = 0;

    // Creates a sequence and fill it with the points from the input file
    Sequence allPoints = createSequence(length);
    for (int i = 0; i < allPoints.length; i++) {
        Point newPoint;
        if (fscanf(inputFile, "%d %d", &newPoint.x, &newPoint.y) != 2) {
            throwError("INPUT", "Error reading the points");
        }
        allPoints.data[i] = newPoint;
    }

    // Closes input file
    fclose(inputFile);

    // Sorts all points in ascending order
    sortSequenceByY(allPoints);

    return allPoints;
}

// The output is the number of points in the longest path
void saveLongestLengthOutput(char* outputPath, int value) {
    // Try to open the output file in write mode
    FILE* outputFile = fopen(outputPath, "w");
    if (outputFile == NULL) throwError("OUTPUT", "Cannot write file");

    // Writes the value
    fprintf(outputFile, "%d", value);

    // Closes output file
    fclose(outputFile);
}