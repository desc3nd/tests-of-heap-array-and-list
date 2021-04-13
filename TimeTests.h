
#ifndef NOWY_TIMETESTS_H
#define NOWY_TIMETESTS_H

#include "List.h"
#include "stopWatch.h"
#include "dynamicArray.h"
#include "bin_heap.h"

//klasa która tworzy testy czasowe
class TimeTests {
public:
    void TestList();

    void TestDynamicArray();

    void TestBinHeap();

    explicit TimeTests();


private:
    void operationMenu() const;

    int numberOfRepeat;
};


#endif //NOWY_TIMETESTS_H
