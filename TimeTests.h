
#ifndef NOWY_TIMETESTS_H
#define NOWY_TIMETESTS_H
#include "List.h"
#include "stopWatch.h"
#include "DynamicArray.h"
#include "bin_heap.h"
class TimeTests {
public:
   explicit TimeTests();
   void TestList();
   void TestDynamicArray();
   void TestBinHeap();


private:
   void operationMenu();
};


#endif //NOWY_TIMETESTS_H
