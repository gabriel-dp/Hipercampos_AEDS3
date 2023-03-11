#include <stdio.h>

#include "../include/args.h"
#include "../include/pointio.h"
#include "../include/sequence.h"

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