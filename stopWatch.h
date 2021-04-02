
#ifndef NOWY_STOPWATCH_H
#define NOWY_STOPWATCH_H
#include<chrono>

class stopWatch {
private:
    std::chrono::high_resolution_clock::time_point begin;
    std::chrono::high_resolution_clock::time_point stop;
public:
    explicit stopWatch();
    void startCountingTime();
    void stopCountingTime();
    long long elapsedTime();
};


#endif //NOWY_STOPWATCH_H
