#include <iostream>
#include "List.h"
#include "DynamicArray.h"
#include "bin_heap.h"
#include "BstTree.h"
#include"structureTests.h"
#include "TimeTests.h"
int main() {
    structureTests tests;

    tests.propDynamicArray();
    tests.propList();
    tests.propBinHeap();
    TimeTests testy;
    testy.TestList("List");

}
