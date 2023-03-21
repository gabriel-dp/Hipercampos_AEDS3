#include "../include/sequence.h"

#include <stdio.h>
#include <stdlib.h>

// Creates a new empty Sequence
Sequence createSequence(int length) {
    Sequence newSequence;
    newSequence.points = (Point*)malloc(length * sizeof(Point));
    newSequence.length = 0;

    return newSequence;
}

// Adds a new point to a Sequence
void addToSequence(Sequence* sequence, Point point) {
    sequence->points[sequence->length] = point;
    sequence->length++;
}

// Prints each point coordinates from sequence
void printSequence(Sequence* sequence) {
    printf("Sequence length: %d\n", sequence->length);
    if (sequence->length == 0) return;

    for (int i = 0; i < sequence->length; i++) {
        printf("|(%d, %d)", sequence->points[i].x, sequence->points[i].y);
    }
    printf("|\n");
}

// Call the function to search sequences and returns the one with the longest path
Sequence getLongestPath(Sequence* sequence, Point a, Point b) {
    int* connections = (int*)calloc(sequence->length, sizeof(int));

    int greatestLength = 0;
    for (int i = 0; i < sequence->length; i++) {
        connections[i]++;

        int greatestSubLength = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (validPoint(sequence->points[j], sequence->points[i], a, b)) {
                if (connections[j] > greatestSubLength) {
                    greatestSubLength = connections[j];
                }
            }
        }

        connections[i] += greatestSubLength;
        if (connections[i] > greatestLength) {
            greatestLength = connections[i];
        }
    }

    Sequence longestPath = createSequence(greatestLength);
    for (int i = sequence->length - 1; i >= 0 && greatestLength > 0; i--) {
        if (connections[i] == greatestLength) {
            addToSequence(&longestPath, sequence->points[i]);
            greatestLength--;
        }
    }

    free(connections);

    return longestPath;
}
