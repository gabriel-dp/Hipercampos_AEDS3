#include "../include/sequence.h"

#include <stdio.h>
#include <stdlib.h>

// Creates a new empty Sequence
Sequence createSequence(int length) {
    Sequence newSequence;
    newSequence.data = (Element*)malloc(length * sizeof(Element));
    newSequence.length = 0;

    return newSequence;
}

// Adds a new point to a Sequence
void addToSequence(Sequence* sequence, Point point) {
    sequence->data[sequence->length].point = point;
    sequence->data[sequence->length].connections = 1;
    sequence->length++;
}

// Call the function to search sequences and returns the one with the longest path
int getGreatestPathLength(Sequence* sequence, Point a, Point b) {
    int greatestLength = 0;

    for (int i = 0; i < sequence->length; i++) {
        int greatestSubLength = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (validPoint(sequence->data[j].point, sequence->data[i].point, a, b)) {
                if (sequence->data[j].connections > greatestSubLength) {
                    greatestSubLength = sequence->data[j].connections;
                }
            }
        }
        sequence->data[i].connections += greatestSubLength;
        if (sequence->data[i].connections > greatestLength) {
            greatestLength = sequence->data[i].connections;
        }
    }

    return greatestLength;
}
