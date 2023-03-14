#include "../include/sequence.h"

#include <stdio.h>
#include <stdlib.h>

// Creates a new Sequence and allocates space for the data based on the given length
Sequence createSequence(int length) {
    Sequence newArray;
    newArray.data = (Point*)(malloc(length * sizeof(Point)));
    newArray.length = length;
    return newArray;
}

// Reallocates the Sequence space to length + 1 and then stores the new point in that space
void addPointToSequence(Sequence* sequence, Point point) {
    sequence->data = realloc(sequence->data, (sequence->length + 1) * sizeof(Point));
    sequence->data[sequence->length] = point;
    sequence->length++;
}

// Reallocates space for data based on the given length N, keeping the first N elements and removing the others
void restoreSequence(Sequence* sequence, int length) {
    sequence->data = realloc(sequence->data, length * sizeof(Point));
    sequence->length = length;
}

// Prints each point coordinates from a sequence
void printSequence(Sequence* sequence) {
    for (int i = 0; i < sequence->length; i++) {
        printf("|(%d, %d)", sequence->data[i].x, sequence->data[i].y);
    }
    printf("|\n");
}

// Creates a new Sequence of the same length and copies point-by-point from the original to the new Sequence data
void copySequence(Sequence* source, Sequence* copy) {
    // Deallocates previous data array
    free(copy->data);

    *copy = createSequence(source->length);
    for (int i = 0; i < copy->length; i++) {
        copy->data[i] = source->data[i];
    }
}

// Recursive function to search for the longest path
void searchSequences(int iterationIndex, Point points[], Sequence* activeSequence, Sequence* longestPath, Point a, Point b) {
    // Stores the initial state before the loop
    int previousLength = activeSequence->length;

    for (int i = iterationIndex; i >= 0; i--) {
        // Breaks loop if the longest sequence length is greater or equal to all the next possible sequences
        if (longestPath->length >= activeSequence->length + (i + 1)) {
            break;
        }

        // Adds a new point to the active sequence if it is empty or the point is valid
        if (activeSequence->length == 0 || validPoint(points[i], activeSequence->data[activeSequence->length - 1], a, b)) {
            addPointToSequence(activeSequence, points[i]);

            // The active sequence will be the longest sequence if its length is greater than the previous longest
            if (activeSequence->length > longestPath->length) {
                copySequence(activeSequence, longestPath);
            }

            // Searches for sequences in the i-1 remaining points
            searchSequences(i - 1, points, activeSequence, longestPath, a, b);

            // Restores activeSequence to the initial state before the iteration
            restoreSequence(activeSequence, previousLength);
        }
    }
}

// Call the function to search sequences and returns the one with the longest path
Sequence getLongestPath(Sequence* sequence, Point a, Point b) {
    // Creates an auxiliar sequence that is automatically deallocated
    Sequence auxSequence = createSequence(0);

    // The longest path will receive the auxiliar sequence data every time that sequence has a greater length
    Sequence longestPath = createSequence(0);

    // Searches for the longest sequence
    searchSequences(sequence->length - 1, sequence->data, &auxSequence, &longestPath, a, b);

    return longestPath;
}
