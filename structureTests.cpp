
#include "structureTests.h"
#include "DynamicArray.h"
#include "bin_heap.h"
#include <random>
#include<iostream>


structureTests::structureTests() {

}

void structureTests::propList() {
    List list;
    list.readFromFile("txtToCheck.txt","pushBack");
    for (int i = 0; i < 5; i++) {
        list.pushBack(rand() % 1000);
    }
    list.pop();
    //list.popBack();
    list.showIx(1);
    list.pushBack(2);
    list.pushIx(2,2);
    list.showList();
    std::cout<<"List is ok!"<<std::endl;
    }

void structureTests::propDynamicArray() {
    DynamicArray Array;
    Array.readFromFile("txtToCheck.txt", "push");
    for (int i = 0; i < 10; i++)
    {
        Array.pushBack(rand() % 1000);
    }

    Array.popBack();
    Array.printByIdx(3);
    Array.popByIdx(2);
    Array.pushFront(9);
    Array.popFront();
    Array.arrayDisplay();
    std::cout<<"dynamicArray is ok!"<<std::endl;
}

void structureTests::propBinHeap() {
    bin_heap heap;
    heap.readFromFile("txtToCheck.txt");
    for (int i = 0; i < 30; i++)
    {
        heap.push(rand() % 1000);
    }
    heap.pop();
    heap.displayHeap();
    std::cout<<"heap is ok!"<<std::endl;
}






