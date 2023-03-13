#include "../include/sequence.h"

#include <stdio.h>
#include <stdlib.h>

/*
 *  ____POINT VERIFICATIONS____
 *  - Relative Position
 *      Compare a point to an edge, returns a positive value if on the left or negative if on the right
 *  - Valid Point
 *      Returns true if a point is inside a triangle
 */

int relativePosition(Point p, Point c, Point anchor) {
    Vector edge, aux;
    edge.i = c.x - anchor.x;
    edge.j = c.y - anchor.y;
    aux.i = p.x - anchor.x;
    aux.j = p.y - anchor.y;

    int crossProduct = edge.i * aux.j - edge.j * aux.i;

    return crossProduct;
}

int validPoint(Point p, Point c, Point a, Point b) {
    int leftPosition = relativePosition(p, c, a);
    int rightPosition = relativePosition(p, c, b);

    return (leftPosition < 0 && rightPosition > 0);
}

/*
 *  ____BASIC SEQUENCE OPERATIONS____
 *
 *  - Create new
 *      Creates a new Sequence and allocates space for the data based on the given length
 *  - Add point
 *      Reallocates the Sequence space to length + 1 and then stores the new point in that space
 *  - Restore
 *      Reallocates space for data based on the given length N, keeping the first N elements and removing the others
 *  - Print
 *      Print each point coordinates from a sequence
 *  - Copy
 *      Creates a new Sequence of the same length and copies point-by-point from the original to the new Sequence data
 */

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

void printSequence(Sequence sequence) {
    for (int i = 0; i < sequence.length; i++) {
        printf("|(%d, %d)", sequence.data[i].x, sequence.data[i].y);
    }
    printf("|\n");
}

void copySequence(Sequence source, Sequence* copy) {
    free(copy->data);  // deallocates previous data array

    *copy = createSequence(source.length);
    for (int i = 0; i < copy->length; i++) {
        copy->data[i] = source.data[i];
    }
}

/*
 *  ____COMPLEX SEQUENCE OPERATIONS____
 *
 *  - Sort by Y
 *      Selection sort algorythm (efficient to few elements)
 *  - Search
 *      Recursive function to search for the longest sequence
 *  - Get longest path
 *      Responsible for calling the function to search sequences and returning the longest one
 */

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

void searchSequences(int iterationIndex, Point points[], Sequence* activeSequence, Sequence* longestPath, Point a, Point b) {
    int previousLength = activeSequence->length;

    for (int i = iterationIndex; i >= 0; i--) {
        // Break loop if the longest sequence length is greater or equal to all the next possible sequences
        if (longestPath->length >= activeSequence->length + (i + 1)) {
            break;
        }

        // Add a new point to the active sequence if it is empty or the point is valid
        if (activeSequence->length == 0 || validPoint(points[i], activeSequence->data[activeSequence->length - 1], a, b)) {
            addPointToSequence(activeSequence, points[i]);

            // The active sequence will be the longest sequence if its length is greater than the previous longest
            if (activeSequence->length > longestPath->length) {
                copySequence(*activeSequence, longestPath);
            }

            // Search for sequences in the i-1 remaining points
            searchSequences(i - 1, points, activeSequence, longestPath, a, b);

            // Restore activeSequence to the initial state before the iteration
            restoreSequence(activeSequence, previousLength);
        }
    }
}

Sequence getLongestPath(Sequence sequence, Point a, Point b) {
    // Create a sorted copy of the original sequence
    Sequence sortedSequence = createSequence(0);
    copySequence(sequence, &sortedSequence);
    sortSequenceByY(sequence);

    // Create an auxiliar sequence that is automatically deallocated due to restoreSequence()
    Sequence auxSequence = createSequence(0);

    // longestPath will receive auxSequence data every time a sequence has a longest length
    Sequence longestPath = createSequence(0);

    searchSequences(sequence.length - 1, sequence.data, &auxSequence, &longestPath, a, b);

    return longestPath;
}
