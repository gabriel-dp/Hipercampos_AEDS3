#include <stdio.h>
#include <sys/resource.h>

#include "../include/args.h"
#include "../include/pointio.h"
#include "../include/sequence.h"


int main(int argc, char* argv[]) {

    struct rusage usage;
    struct timeval start, end;
    int who = RUSAGE_SELF;

    int ret  = getrusage(who, &usage);
    printf("\n\n|| %d ||\n\n", ret);
    
    start = usage.ru_utime;

    char *inputPath, *outputPath;
    getArgs(&inputPath, &outputPath, argc, argv);

    Point a, b;
    Sequence inputPoints = getPointsInput(inputPath, &a, &b);

    Sequence longestPath = getLongestPath(inputPoints, a, b);
    printSequence(longestPath);

    saveLongestLengthOutput(outputPath, longestPath.length);

    getrusage(who, &usage);
    end = usage.ru_utime;

    printf("\nStarted at: %lu.%lus\n", start.tv_sec, start.tv_usec);
    printf("Ended at: %lu.%lus\n", end.tv_sec, end.tv_usec);

    long int totalSec = end.tv_sec - start.tv_sec;
    long int totalUsec = end.tv_usec - start.tv_usec;

    printf("\n%ld.%ldµs\n\n", totalSec * 1000000, totalUsec);

    return 0;
}