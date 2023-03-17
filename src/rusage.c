#include <stdio.h>
#include <sys/resource.h>

// Returns CPU time used by the program
long double getTimeCPU() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    struct timeval time = usage.ru_utime;
    long double totalTime = time.tv_sec + ((long double)time.tv_usec / 1000000.0L);

    return totalTime;
}

// Prints the difference between start to end
void printElapsedTime(long double startTime, long double endTime) {
    long double elapsedTime = endTime - startTime;
    printf("Elapsed time: %Lf\n", elapsedTime);
}
