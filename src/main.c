#include <stdio.h>

#include "files.h"
#include "point.h"

int main(int argc, char* argv[]) {
    char *inputPath, *outputPath;
    getArgs(&inputPath, &outputPath, argc, argv);

    Coordinate xa, xb;
    Sequence inputPoints = getPointsFromInput(inputPath, &xa, &xb);

    sortSequenceByY(inputPoints);
    Sequence longestPath = getLongestPath(inputPoints, xa, xb);

    printSequence(longestPath);

    return 0;
}