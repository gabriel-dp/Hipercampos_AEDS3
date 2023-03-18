#include "../include/sequence.h"

#include <stdio.h>
#include <stdlib.h>

// Creates a new empty SequenceList
SequenceList createSequenceList() {
    SequenceList newSequence;
    newSequence.first = NULL;
    newSequence.last = NULL;
    newSequence.length = 0;

    return newSequence;
}

// Creates a new empty SequenceArray
SequenceArray createSequenceArray(int length) {
    SequenceArray newSequence;
    newSequence.data = (Point*)malloc(sizeof(Point) * length);
    newSequence.length = length;

    return newSequence;
}

// Add a new point to a SequenceList
void addSequenceList(SequenceList* sequence, Point point) {
    Element* newPoint = (Element*)malloc(sizeof(Element));
    newPoint->point = point;
    newPoint->previous = sequence->last;
    newPoint->next = NULL;

    if (sequence->length < 1) {
        sequence->first = newPoint;
    } else {
        sequence->last->next = newPoint;
    }
    sequence->last = newPoint;
    sequence->length++;
}

// Delete the last element from a SequenceList
void popSequenceList(SequenceList* sequence) {
    if (sequence->length < 1) return;

    Element* deletedPoint = sequence->last;
    free(deletedPoint);

    sequence->last = sequence->last->previous;
    if (sequence->last != NULL) {
        sequence->last->next = NULL;
    } else {
        sequence->first = NULL;
    }
    sequence->length--;
}

// Restore a SequenceList to a given length
void restoreSequenceList(SequenceList* sequence, int length) {
    while (sequence->length > length) {
        popSequenceList(sequence);
    }
}

// Prints each point coordinates from a SequenceList
void printSequenceList(SequenceList* sequence) {
    printf("Sequence length: %d\n", sequence->length);
    if (sequence->length < 1) return;

    Element* actualPoint = sequence->first;
    while (actualPoint != NULL) {
        printf("|(%d,%d)", actualPoint->point.x, actualPoint->point.y);
        actualPoint = actualPoint->next;
    }
    printf("|\n");
}

// Prints each point coordinates from a SequenceArray
void printSequenceArray(SequenceArray* sequence) {
    printf("Sequence length: %d\n", sequence->length);
    if (sequence->length < 1) return;

    for (int i = 0; i < sequence->length; i++) {
        printf("|(%d,%d)", sequence->data[i].x, sequence->data[i].y);
    }
    printf("|\n");
}

// Creates a new Sequence of the same length and copies point-by-point from the original to the new Sequence data
void copySequence(SequenceList* source, SequenceArray* copy) {
    copy->data = realloc(copy->data, sizeof(Point) * source->length);

    Element* actualPoint = source->first;
    int index = 0;
    while (actualPoint != NULL) {
        copy->data[index] = actualPoint->point;

        actualPoint = actualPoint->next;
        index++;
    }

    copy->length = source->length;
}

// Recursive function to search for the longest path
void searchSequences(int iterationIndex, Point points[], SequenceList* activeSequence, SequenceArray* longestPath, Point a, Point b) {
    // Stores the initial state before the loop
    int previousLength = activeSequence->length;

    for (int i = iterationIndex; i >= 0; i--) {
        // Breaks loop if the longest sequence length is greater or equal to all the next possible sequences
        if (longestPath->length >= activeSequence->length + (i + 1)) {
            break;
        }

        // Adds a new point to the active sequence if it is empty or the point is valid
        if (activeSequence->length == 0 || validPoint(points[i], activeSequence->last->point, a, b)) {
            addSequenceList(activeSequence, points[i]);

            // The active sequence will be the longest sequence if its length is greater than the previous longest
            if (activeSequence->length > longestPath->length) {
                copySequence(activeSequence, longestPath);
            }

            // Searches for sequences in the i-1 remaining points
            searchSequences(i - 1, points, activeSequence, longestPath, a, b);

            // Restores activeSequence to the initial state before the iteration
            restoreSequenceList(activeSequence, previousLength);
        }
    }
}

// Call the function to search sequences and returns the one with the longest path
SequenceArray getLongestPath(SequenceArray* sequence, Point a, Point b) {
    // Creates an auxiliar sequence that is automatically deallocated
    SequenceList auxSequence = createSequenceList();

    // The longest path will receive the auxiliar sequence data every time that sequence has a greater length
    SequenceArray longestPath = createSequenceArray(0);

    // Searches for the longest sequence
    searchSequences(sequence->length - 1, sequence->data, &auxSequence, &longestPath, a, b);

    return longestPath;
}
