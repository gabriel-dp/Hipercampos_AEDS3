#include "../include/sequence.h"

#include <stdio.h>
#include <stdlib.h>

// Creates a new empty Sequence
Sequence createSequence() {
    Sequence newSequence;
    newSequence.first = NULL;
    newSequence.last = NULL;
    newSequence.length = 0;

    return newSequence;
}

// Add a new point to a Sequence
void addSequence(Sequence* sequence, Point point) {
    Element* newPoint = (Element*)malloc(sizeof(Element));
    newPoint->point = point;
    newPoint->previous = sequence->last;
    newPoint->next = NULL;

    if (sequence->length == 0) {
        sequence->first = newPoint;
    } else {
        sequence->last->next = newPoint;
    }
    sequence->last = newPoint;

    sequence->length++;
}

// Delete the last element from a Sequence
void popSequence(Sequence* sequence) {
    Element* deletedPoint = sequence->last;
    free(deletedPoint);

    sequence->last = sequence->last->previous;
    if (sequence->last == NULL) {
        sequence->first = NULL;
    } else {
        sequence->last->next = NULL;
    }

    sequence->length--;
}

// Restore a Sequence to a given length
void restoreSequence(Sequence* sequence, int length) {
    while (sequence->length > length) {
        popSequence(sequence);
    }
}

// Prints each point coordinates from a SequenceList
void printSequence(Sequence* sequence) {
    printf("Sequence length: %d\n", sequence->length);
    if (sequence->length < 1) return;

    Element* actualPoint = sequence->first;
    while (actualPoint != NULL) {
        printf("|(%d,%d)", actualPoint->point.x, actualPoint->point.y);
        actualPoint = actualPoint->next;
    }
    printf("|\n");
}

// Copies point-by-point from the source Sequence to the PointsArray copy
void copySequenceToArray(Sequence* source, PointsArray* copy) {
    copy->data = realloc(copy->data, sizeof(Point) * source->length);

    int index = 0;
    Element* actualPoint = source->first;
    while (actualPoint != NULL) {
        copy->data[index] = actualPoint->point;

        actualPoint = actualPoint->next;
        index++;
    }

    copy->length = source->length;
}

// Recursive function to search for the longest path
void searchSequences(int iterationIndex, Point points[], Sequence* activeSequence, PointsArray* longestPath, Point a, Point b) {
    // Stores the initial state before the loop
    int previousLength = activeSequence->length;

    for (int i = iterationIndex; i >= 0; i--) {
        // Breaks loop if the longest sequence length is greater or equal to all the next possible sequences
        if (longestPath->length >= activeSequence->length + (i + 1)) {
            break;
        }

        // Adds a new point to the active sequence if it is empty or the point is valid
        if (activeSequence->length == 0 || validPoint(points[i], activeSequence->last->point, a, b)) {
            addSequence(activeSequence, points[i]);

            // The active sequence will be the longest sequence if its length is greater than the previous longest
            if (activeSequence->length > longestPath->length) {
                copySequenceToArray(activeSequence, longestPath);
            }

            // Searches for sequences in the i-1 remaining points
            searchSequences(i - 1, points, activeSequence, longestPath, a, b);

            // Restores activeSequence to the initial state before the iteration
            restoreSequence(activeSequence, previousLength);
        }
    }
}

// Call the function to search sequences and returns the one with the longest path
PointsArray getLongestPath(PointsArray* sequence, Point a, Point b) {
    // Creates an auxiliar sequence that is automatically deallocated
    Sequence auxSequence = createSequence();

    // The longest path will receive the auxiliar sequence data every time that sequence has a greater length
    PointsArray longestPath = createPointsArray(0);

    // Searches for the longest sequence
    searchSequences(sequence->length - 1, sequence->data, &auxSequence, &longestPath, a, b);

    return longestPath;
}
