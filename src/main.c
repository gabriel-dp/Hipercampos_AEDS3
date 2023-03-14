#include <stdio.h>

#include "../include/args.h"
#include "../include/graph.h"
#include "../include/pointio.h"
#include "../include/sequence.h"

int main(int argc, char* argv[]) {
    char *inputPath, *outputPath;
    int graphSize = 0;
    getArgs(&inputPath, &outputPath, &graphSize, argc, argv);

    Point a, b;
    Sequence inputPoints = getPointsInput(inputPath, &a, &b);

    Sequence longestPath = getLongestPath(inputPoints, a, b);
    printSequence(longestPath);

    saveLongestLengthOutput(outputPath, longestPath.length);

    // Plot Graph is optional with -p flag
    if (graphSize != 0) {
        plotGraph(inputPoints, a, b, longestPath, graphSize);
    }

    return 0;
}