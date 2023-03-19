#include "../include/args.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

// Function to stop the program in case of errors in the command line
void errorAtArgs(char* programPath) {
    printf("ARGS ERROR - Correct usage: '%s -i {inputPath} -o {outputPath} -r {optional_resultsPath}'\n", programPath);
    exit(EXIT_FAILURE);
}

// User must enter the input and output paths in the command line
void getArgs(char** inputPath, char** outputPath, char** resultsPath, int argc, char* argv[]) {
    // Initializes both paths with NULL value
    *inputPath = NULL;
    *outputPath = NULL;
    *resultsPath = NULL;

    // Reads all data coming from command line
    int option;
    while ((option = getopt(argc, argv, "i:o:r:")) != -1) {
        switch (option) {
            case 'i':
                *inputPath = optarg;
                break;
            case 'o':
                *outputPath = optarg;
                break;
            case 'r':
                *resultsPath = optarg;
                break;
            default:
                errorAtArgs(argv[0]);
        }
    }

    // Checks required flags
    if (*inputPath == NULL || *outputPath == NULL) {
        errorAtArgs(argv[0]);
    }
}