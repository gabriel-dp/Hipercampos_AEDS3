#include "sequence.h"

#include <stdio.h>
#include <stdlib.h>

#include "point.h"

Sequence initializeSequence() {
    Sequence newSequence;
    newSequence.length = 0;
    newSequence.top = NULL;

    return newSequence;
}

void addPointToSequence(Sequence* sequence, Point point) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->point = point;
    newNode->next = sequence->top;

    sequence->top = newNode;
    sequence->length++;
}

void restoreSequence(Sequence* sequence, int originalLength) {
    while (sequence->length > originalLength) {
        Node* oldNode = sequence->top;
        sequence->top = oldNode->next;
        free(oldNode);

        sequence->length--;
    }
}

void generateArrayFromSequence(PointArray* points, Sequence sequence) {
    *points = createPointArray(sequence.length);

    Node* topNode = sequence.top;
    for (int i = 0; topNode != NULL; i++) {
        points->data[i] = topNode->point;
        topNode = topNode->next;
    }
}

void searchSequences(int index, Point points[], Sequence auxSequence, PointArray* longestPath, Coordinate xa, Coordinate xb) {
    int originalLength = auxSequence.length;

    for (int i = index; i >= 0; i--) {
        if (auxSequence.length == 0 || validPoint(points[i], auxSequence.top->point, xa, xb)) {
            addPointToSequence(&auxSequence, points[i]);
            if (auxSequence.length > longestPath->length) {
                generateArrayFromSequence(longestPath, auxSequence);
            }
            searchSequences(i - 1, points, auxSequence, longestPath, xa, xb);
        }
        restoreSequence(&auxSequence, originalLength);
    }
}

PointArray getLongestPath(PointArray points, Coordinate xa, Coordinate xb) {
    PointArray longestPath = createPointArray(0);
    Sequence auxSequence = initializeSequence();
    searchSequences(points.length - 1, points.data, auxSequence, &longestPath, xa, xb);
    return longestPath;
}