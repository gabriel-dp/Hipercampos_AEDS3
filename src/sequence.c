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

// Deallocates a sequence points array
void freeSequence(Sequence* sequence) {
    free(sequence->points);
}

// Search sequences and returns the one with the longest path
Sequence getLongestPath(Sequence* sequence, Point a, Point b) {
    // Creates an temp array to store each point connections number
    Connection* connections = (Connection*)malloc(sequence->length * sizeof(Connection));

    // Initializes longestPath length and start index variables
    int longestPathLength = 0;
    int longestPathIndex = 0;

    // The process starts from the lowest Y coordinate to the highest
    for (int i = 0; i < sequence->length; i++) {
        // If there is a point, the connection is at least 1
        connections[i].connections = 1;

        // Searches for the point j (below point i) that has more connections
        int greatestSubLength = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (validPoint(sequence->points[j], sequence->points[i], a, b)) {
                if (connections[j].connections > greatestSubLength) {
                    greatestSubLength = connections[j].connections;
                    connections[i].indexNext = j;
                }
            }
        }

        // Adds the greatest point j connections to the point i connections
        connections[i].connections += greatestSubLength;

        // The longestPathLength is the greatest number of connections of all points
        if (connections[i].connections > longestPathLength) {
            longestPathLength = connections[i].connections;
            longestPathIndex = i;
        }
    }

    printSequence(sequence);

    // Creates the sequence based on the connections previously created
    Sequence longestPath = createSequence(longestPathLength);
    int index = longestPathIndex;
    for (int i = 0; i < longestPathLength; i++) {
        addToSequence(&longestPath, sequence->points[index]);
        index = connections[index].indexNext;
    }

    // Deallocates the connections array
    free(connections);

    return longestPath;
}
