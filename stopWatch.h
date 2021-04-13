
#ifndef NOWY_STOPWATCH_H
#define NOWY_STOPWATCH_H
#include<chrono>

class stopWatch {
private:
    long long int frequency, start, elapsed, stop1;
public:
    void startCountingTime();

    void stopCountingTime();

    long long int elapsedTime();

    long long int read_QPC();
};


#endif //NOWY_STOPWATCH_H
