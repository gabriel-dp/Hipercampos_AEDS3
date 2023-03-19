#include "../include/pointlib.h"

#include <stdio.h>
#include <stdlib.h>

// Creates a new empty PointsArray
PointsArray createPointsArray(int length) {
    PointsArray newArray;
    newArray.data = (Point*)malloc(sizeof(Point) * length);
    newArray.length = length;

    return newArray;
}

// Prints each point coordinates from a PointsArray
void printPointsArray(PointsArray* Array) {
    printf("Array length: %d\n", Array->length);
    if (Array->length < 1) return;

    for (int i = 0; i < Array->length; i++) {
        printf("|(%d,%d)", Array->data[i].x, Array->data[i].y);
    }
    printf("|\n");
}

// Compares a point to an vector, returns a positive value if on the left or negative if on the right
int relativePosition(Point p, Point c, Point anchor) {
    // Creates the vectors starting from the anchor to points P and C
    Vector edge, aux;
    edge.i = c.x - anchor.x;
    edge.j = c.y - anchor.y;
    aux.i = p.x - anchor.x;
    aux.j = p.y - anchor.y;

    // Simplified version of cross product with only i and j
    int crossProduct = (edge.i * aux.j) - (edge.j * aux.i);

    return crossProduct;
}

// Checks if the point P is inside the triangle created from the points (A, B, C)
int validPoint(Point p, Point c, Point a, Point b) {
    // Point must be on the right of the left edge and on the left of the right edge
    int leftPosition = relativePosition(p, c, a);
    int rightPosition = relativePosition(p, c, b);
    int isInsideTriangle = (leftPosition < 0 && rightPosition > 0);

    return isInsideTriangle;
}