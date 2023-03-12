#include "../include/sequence.h"

#include <stdio.h>
#include <stdlib.h>

// Function to valid a point position based on another
int validPoint(Point p, Point c, Coordinate xa, Coordinate xb) {
    // Davi
    return 1;
}

Sequence createSequence(int length) {
    Sequence newArray;
    newArray.data = (Point*)(malloc(length * sizeof(Point)));
    newArray.length = length;
    return newArray;
}

void addPointToSequence(Sequence* sequence, Point point) {
    sequence->data = realloc(sequence->data, (sequence->length + 1) * sizeof(Point));
    sequence->data[sequence->length] = point;
    sequence->length++;
}

void restoreSequence(Sequence* sequence, int originalLength) {
    sequence->data = realloc(sequence->data, originalLength * sizeof(Point));
    sequence->length = originalLength;
}

void copySequence(Sequence source, Sequence* copy) {
    free(copy->data);  // deallocates previous data array

    *copy = createSequence(source.length);
    for (int i = 0; i < copy->length; i++) {
        copy->data[i] = source.data[i];
    }
}

void printSequence(Sequence sequence) {
    for (int i = 0; i < sequence.length; i++) {
        printf("|(%d, %d)", sequence.data[i].x, sequence.data[i].y);
    }
    printf("|\n");
}

// Selection sort algorythm (efficient to few elements)
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

void searchSequences(int index, Point points[], Sequence* auxSequence, Sequence* longestPath, Coordinate xa, Coordinate xb) {
    int originalLength = auxSequence->length;

    for (int i = index; i >= 0; i--) {
        if (auxSequence->length == 0 || validPoint(points[i], auxSequence->data[auxSequence->length - 1], xa, xb)) {
            addPointToSequence(auxSequence, points[i]);
            // printSequence(*auxSequence);
            if (auxSequence->length > longestPath->length) {
                copySequence(*auxSequence, longestPath);
            }
            searchSequences(i - 1, points, auxSequence, longestPath, xa, xb);
            restoreSequence(auxSequence, originalLength);
        }
    }
}

Sequence getLongestPath(Sequence sequence, Coordinate xa, Coordinate xb) {
    // auxSequence is automatically freed due to restoreSequence() that runs realloc() with size 0
    Sequence auxSequence = createSequence(0);

    // longestPath will receive auxSequence points every time another sequence has a longest length
    Sequence longestPath = createSequence(0);

    // Sorted elements are better readable
    sortSequenceByY(sequence);

    // Recursive function to search for the longest sequence
    searchSequences(sequence.length - 1, sequence.data, &auxSequence, &longestPath, xa, xb);

    return longestPath;
}
