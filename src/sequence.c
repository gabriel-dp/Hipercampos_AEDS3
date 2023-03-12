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

void restoreSequence(Sequence* sequence, int length) {
    sequence->data = realloc(sequence->data, length * sizeof(Point));
    sequence->length = length;
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

void searchSequences(int iterationIndex, Point points[], Sequence* activeSequence, Sequence* longestPath, Coordinate xa, Coordinate xb) {
    int previousLength = activeSequence->length;

    for (int i = iterationIndex; i >= 0; i--) {
        // Break loop if the longest sequence length is greater or equal to all the next possible sequences
        if (longestPath->length >= activeSequence->length + (i + 1)) {
            break;
        }

        // Add a new point to the active sequence if it is empty or the point is valid
        if (activeSequence->length == 0 || validPoint(points[i], activeSequence->data[activeSequence->length - 1], xa, xb)) {
            addPointToSequence(activeSequence, points[i]);

            // The active sequence will be the longest sequence if its length is greater than the previous longest
            if (activeSequence->length > longestPath->length) {
                copySequence(*activeSequence, longestPath);
            }

            // Search for sequences in the i-1 remaining points
            searchSequences(i - 1, points, activeSequence, longestPath, xa, xb);

            // Restore activeSequence to the initial state before the iteration
            restoreSequence(activeSequence, previousLength);
        }
    }
}

Sequence getLongestPath(Sequence sequence, Coordinate xa, Coordinate xb) {
    // auxSequence is automatically freed due to restoreSequence() that runs realloc() with size 0
    Sequence auxSequence = createSequence(0);

    // longestPath will receive auxSequence data every time a sequence has a longest length
    Sequence longestPath = createSequence(0);

    // Sorted elements are better readable
    sortSequenceByY(sequence);

    // Recursive function to search for the longest sequence
    searchSequences(sequence.length - 1, sequence.data, &auxSequence, &longestPath, xa, xb);

    return longestPath;
}
