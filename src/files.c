#include "files.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "point.h"

void errorAtArgs(char* programPath) {
    printf("ARGS ERROR - Correct usage: '%s -i {inputPath} -o {outputPath}'\n", programPath);
    exit(EXIT_FAILURE);
}

void getArgs(char** inputPath, char** outputPath, int argc, char* argv[]) {
    *inputPath = NULL;
    *outputPath = NULL;

    int option;
    while ((option = getopt(argc, argv, "i:o:")) != -1) {
        switch (option) {
            case 'i':
                *inputPath = optarg;
                break;
            case 'o':
                *outputPath = optarg;
                break;
            default:
                errorAtArgs(argv[0]);
        }
    }

    if (*inputPath == NULL || *outputPath == NULL) {
        errorAtArgs(argv[0]);
    }
}

void inputError(char* message) {
    printf("INPUT ERROR - %s\n", message);
    exit(EXIT_FAILURE);
}

Sequence getPointsFromInput(char* path, Coordinate* xa, Coordinate* xb) {
    FILE* file = fopen(path, "r");
    if (file == NULL) inputError("Cannot read file");

    int length;
    fscanf(file, "%d %d %d", &length, xa, xb);

    Sequence sequence = createSequence(length);

    for (int i = 0; i < sequence.length; i++) {
        Point newPoint;
        if (fscanf(file, "%d %d", &newPoint.x, &newPoint.y) != 2) {
            inputError("Too few points in file");
        }
        sequence.data[i] = newPoint;
    }

    return sequence;
}