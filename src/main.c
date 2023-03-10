#include <stdio.h>

#include "args.h"
#include "point.h"

int main(int argc, char* argv[]) {
    char *inputPath, *outputPath;
    getArgs(&inputPath, &outputPath, argc, argv);

    int totalPoints, xa, xb;
    Point* points = NULL;
    getPointsFromInput(inputPath, &points, &totalPoints, &xa, &xb);
    sortPointsByY(points, totalPoints);

    printf("|%d|%d|%d|\n", totalPoints, xa, xb);
    for (int i = 0; i < totalPoints; i++) {
        printf("|%d|%d|\n", points[i].x, points[i].y);
    }

    return 0;
}