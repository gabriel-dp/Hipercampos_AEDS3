#include "../include/args.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

void errorAtArgs(char* programPath) {
    printf("ARGS ERROR - Correct usage: '%s -i {inputPath} -o {outputPath} -p {optinal graphSize}'\n", programPath);
    exit(EXIT_FAILURE);
}

void getArgs(char** inputPath, char** outputPath, int* graphSize, int argc, char* argv[]) {
    *inputPath = NULL;
    *outputPath = NULL;

    int option;
    while ((option = getopt(argc, argv, "i:o:p:")) != -1) {
        switch (option) {
            case 'i':
                *inputPath = optarg;
                break;
            case 'o':
                *outputPath = optarg;
                break;
            case 'p':
                *graphSize = atoi(optarg);
                break;
            default:
                errorAtArgs(argv[0]);
        }
    }

    // Required flags
    if (*inputPath == NULL || *outputPath == NULL) {
        errorAtArgs(argv[0]);
    }
}