#include "../include/pointio.h"

#include <stdio.h>
#include <stdlib.h>

// Selection sort algorythm, great for few elements
void sortPointsArrayByY(PointsArray* array) {
    int min;
    for (int i = 0; i < array->length; i++) {
        min = i;
        for (int j = i + 1; j < array->length; j++) {
            if (array->data[j].y < array->data[min].y) {
                min = j;
            }
        }
        if (min != i) {
            Point aux = array->data[min];
            array->data[min] = array->data[i];
            array->data[i] = aux;
        }
    }
}

// Function to stop the program in case of I/O errors
void throwError(char* type, char* message) {
    printf("%s ERROR - %s\n", type, message);
    exit(EXIT_FAILURE);
}

// The input file contains the number of points + Ax + Bx and all other points
PointsArray getPointsInput(char* inputPath, Point* a, Point* b) {
    // Try to open the input file in read mode
    FILE* inputFile = fopen(inputPath, "r");
    if (inputFile == NULL) throwError("INPUT", "Cannot read file");

    // First line contains the total number of points and the X coordinate of A and B
    int length;
    fscanf(inputFile, "%d %d %d", &length, &(a->x), &(b->x));

    // Y coordinate of A and B is locked at 0
    a->y = 0;
    b->y = 0;

    // Creates an array and fill it with the points from the input file
    PointsArray allPoints = createPointsArray(length);
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
    sortPointsArrayByY(&allPoints);

    return allPoints;
}

// The output file saves the number of points in the longest path
void saveLongestLengthOutput(char* outputPath, int value) {
    // Try to open the output file in write mode
    FILE* outputFile = fopen(outputPath, "w");
    if (outputFile == NULL) throwError("OUTPUT", "Cannot write file");

    // Writes the value
    fprintf(outputFile, "%d", value);

    // Closes output file
    fclose(outputFile);
}

// The results file stores data from all code executions in a single file
void saveResultsData(char* resultsPath, int totalPoints, int validPoints, long double elapsedTime) {
    // Try to open the results file in append mode
    FILE* resultsFile = fopen(resultsPath, "a");
    if (resultsFile == NULL) throwError("RESULTS", "Cannot open file");

    // Writes a new line with totalPoints + validPoints + elapsedTime
    fprintf(resultsFile, "%d %d %Lf\n", totalPoints, validPoints, elapsedTime);
    printf("Results written in '%s'\n", resultsPath);

    // Closes results file
    fclose(resultsFile);
}
