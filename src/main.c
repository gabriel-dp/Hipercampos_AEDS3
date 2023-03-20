#include <stdlib.h>

#include "../include/args.h"
#include "../include/pointio.h"
#include "../include/pointlib.h"
#include "../include/sequence.h"

int main(int argc, char* argv[]) {
    // Receives the input and output paths from the command line
    char *inputPath, *outputPath;
    getArgs(&inputPath, &outputPath, argc, argv);

    // Creates A, B and all other points from the input file
    Point a, b;
    Sequence inputPoints = getPointsInput(inputPath, &a, &b);

    // Gets the greatest path between all points
    int greatestPathLength = getGreatestPathLength(&inputPoints, a, b);

    // Saves the greatest path length to the output file
    saveGreatestPathLengthOutput(outputPath, greatestPathLength);

    // Deallocates inputPoints and longestPath pointers
    free(inputPoints.data);

    return 0;
}