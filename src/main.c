#include <stdlib.h>

#include "../include/args.h"
#include "../include/pointio.h"
#include "../include/pointlib.h"
#include "../include/rusage.h"
#include "../include/sequence.h"

int main(int argc, char* argv[]) {
    // Receives the input and output paths from the command line
    char *inputPath, *outputPath, *resultsPath;
    getArgs(&inputPath, &outputPath, &resultsPath, argc, argv);

    // Gets A, B and all other points from the input file
    Point a, b;
    Sequence inputPoints = getPointsInput(inputPath, &a, &b);

    // Starts the CPU time monitoring
    long double startTime = getTimeCPU();

    // Gets the longest path between all points
    Sequence longestPath = getLongestPath(&inputPoints, a, b);

    // Ends the CPU time monitoring
    long double endTime = getTimeCPU();
    printElapsedTime(startTime, endTime);

    // Saves the longest path length to the output file
    saveLongestPathLengthOutput(outputPath, longestPath.length);
    printSequence(&longestPath);

    // Saves results from each execution
    if (resultsPath != NULL) {
        saveResultsData(resultsPath, inputPoints.length, longestPath.length, endTime - startTime);
    }

    // Deallocates inputPoints and longestPath data pointers
    freeSequence(&inputPoints);
    freeSequence(&longestPath);

    return 0;
}