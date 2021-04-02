#include<chrono>
#include "stopWatch.h"

stopWatch::stopWatch() {

}

void stopWatch::startCountingTime() {
    begin=std::chrono::high_resolution_clock::now();
}

void stopWatch::stopCountingTime() {
    stop=std::chrono::high_resolution_clock::now();
}

long long stopWatch::elapsedTime() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>  (stop - begin  ).count();
}
