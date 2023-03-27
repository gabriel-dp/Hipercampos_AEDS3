#include "../include/args.h"
#include "../include/pointio.h"
#include "../include/pointlib.h"
#include "../include/sequence.h"

int main(int argc, char* argv[]) {
    // Receives the input and output paths from the command line
    char *inputPath, *outputPath;
    getArgs(&inputPath, &outputPath, argc, argv);

    // Gets A, B and all other points from the input file
    Point a, b;
    Sequence inputPoints = getPointsInput(inputPath, &a, &b);

    // Gets the longest path between all points
    Sequence longestPath = getLongestPath(&inputPoints, a, b);

    // Saves the longest path length to the output file
    saveLongestPathLengthOutput(outputPath, longestPath.length);
    printSequence(&longestPath);

    // Deallocates inputPoints and longestPath data pointers
    freeSequence(&inputPoints);
    freeSequence(&longestPath);

    return 0;
}