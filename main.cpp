#include <iostream>
#include "List.h"
#include "DynamicArray.h"
#include "bin_heap.h"
#include "BstTree.h"
#include"structureTests.h"
#include "TimeTests.h"
int main() {
    structureTests tests;

    List list;
   list.pushBack(3);
   list.readFromFile("txtToCheck.txt","push");
    list.showList();
    tests.propDynamicArray();
    tests.propList();
    tests.propBinHeap();
  TimeTests testy;
    testy.TestList("List");

}
