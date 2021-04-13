
#include <winnt.h>
#include <afxres.h>
#include "stopWatch.h"

void stopWatch::startCountingTime() {
    QueryPerformanceFrequency((LARGE_INTEGER *) &frequency);
    start = read_QPC();
}

void stopWatch::stopCountingTime() {
    QueryPerformanceFrequency((LARGE_INTEGER *) &frequency);
    stop1 = read_QPC();
}

long long int stopWatch::elapsedTime() {
    elapsed = stop1 - start;
    return 1000000000.0 * elapsed / frequency;
}

long long int stopWatch::read_QPC() {
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return ((long long int) count.QuadPart);
}