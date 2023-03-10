#include <stdio.h>

#include "args.h"
#include "point.h"

int main(int argc, char* argv[]) {
    char *inputPath, *outputPath;
    getArgs(&inputPath, &outputPath, argc, argv);

    int totalPoints, xa, xb;
    Point* points = getPointsFromInput(inputPath, &totalPoints, &xa, &xb);

    printf("|%d|%d|%d|\n", totalPoints, xa, xb);
    for (int i = 0; i < totalPoints; i++) {
        printf("|%d|%d|\n", points[i].x, points[i].y);
    }

    return 0;
}