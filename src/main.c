#include <stdio.h>
#include <stdlib.h>

#include "args.h"
#include "point.h"

int main(int argc, char* argv[]) {
    Point* points = createPointsArray(100);

    char *inputPath, *outputPath;
    getArgs(&inputPath, &outputPath, argc, argv);

    return 0;
}