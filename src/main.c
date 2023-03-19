#include <stdlib.h>

#include "../include/args.h"
#include "../include/graph.h"
#include "../include/pointio.h"
#include "../include/pointlib.h"
#include "../include/sequence.h"

int main(int argc, char* argv[]) {
    // Receives the input and output paths from the command line
    char *inputPath, *outputPath;
    int graphSize = 0;
    getArgs(&inputPath, &outputPath, &graphSize, argc, argv);

    // Creates A, B and all other points from the input file
    Point a, b;
    PointsArray inputPoints = getPointsInput(inputPath, &a, &b);

    // Gets the longest path between all points
    PointsArray longestPath = getLongestPath(&inputPoints, a, b);
    printPointsArray(&longestPath);

    // Saves the longest path length to the output file
    saveLongestLengthOutput(outputPath, longestPath.length);

    // Plots graph if user entered graphSize
    if (graphSize != 0) {
        plotGraph(a, b, &inputPoints, &longestPath, graphSize);
    }

    // Deallocates inputPoints and longestPath pointers
    free(inputPoints.data);
    free(longestPath.data);

    return 0;
}