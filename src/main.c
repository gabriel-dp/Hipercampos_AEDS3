#include <stdio.h>

#include "../include/args.h"
#include "../include/pointio.h"
#include "../include/sequence.h"

int main(int argc, char* argv[]) {
    char *inputPath, *outputPath;
    getArgs(&inputPath, &outputPath, argc, argv);

    Point a, b;
    Sequence inputPoints = getPointsInput(inputPath, &a, &b);

    Sequence longestPath = getLongestPath(inputPoints, a, b);
    printSequence(longestPath);

    saveLongestLengthOutput(outputPath, longestPath.length);

    return 0;
}