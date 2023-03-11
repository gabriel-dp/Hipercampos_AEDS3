#include "args.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

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