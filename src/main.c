#include <stdio.h>

#include "args.h"
#include "point.h"
#include "sequence.h"

int main(int argc, char* argv[]) {
    char *inputPath, *outputPath;
    getArgs(&inputPath, &outputPath, argc, argv);

    PointArray points;
    Coordinate xa, xb;
    getPointsFromInput(&points, &xa, &xb, inputPath);

    PointArray longestPath = getLongestPath(points, xa, xb);

    printf("|MAIOR TAMANHO: %d|\n", longestPath.length);

    return 0;
}

/*
printf("|%d|%d|%d|\n", points.length, xa, xb);
for (int i = 0; i < points.length; i++) {
    printf("|%d|%d|\n", points.data[i].x, points.data[i].y);
}
*/