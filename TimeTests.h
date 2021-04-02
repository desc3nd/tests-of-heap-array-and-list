//
// Created by Marcinek on 02.04.2021.
//

#ifndef NOWY_TIMETESTS_H
#define NOWY_TIMETESTS_H
#include "List.h"
#include "stopWatch.h"
#include "DynamicArray.h"
#include "bin_heap.h"
class TimeTests {
public:
   explicit TimeTests();
   void TestList(std::string structure);

private:
   void operationMenu();
};


#endif //NOWY_TIMETESTS_H
