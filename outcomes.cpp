#include <iostream>
#include "List.h"
#include "DynamicArray.h"
#include "bin_heap.h"
#include "BstTree.h"
#include"structureTests.h"
#include "TimeTests.h"
#include "DataGenerator.h"
#include "menu.h"
#include "outcomes.h"
void outcomes::createOutcome() {


}

void outcomes::testArray() {
    stopWatch time;
    DataGenerator gen;
    int oper=1;
    long long allTime[7];
    for (long long & i : allTime) {
        i = 0;
    }
    for (int j = 5000; j < 50000; j = j + 5000)
    {

        for(int i=0;i<100;i++)
        {
            gen.genrateToFile(1,1000,j,"txtToCheck.txt");
            DynamicArray array;
            array.readFromFile("txtToCheck.txt","push");
            time.startCountingTime();
            array.pushFront(1);
            time.stopCountingTime();
            allTime[0]+=time.elapsedTime();
            time.startCountingTime();
            array.popBack();
            time.stopCountingTime();
            allTime[1]+=time.elapsedTime();
            time.startCountingTime();
            array.pushBack(1);
            time.stopCountingTime();
            allTime[2]+=time.elapsedTime();
            time.startCountingTime();
            array.popBack();
            time.stopCountingTime();
            allTime[3]+=time.elapsedTime();
            time.startCountingTime();
            array.pushByIdx(array.returnSize()/2,1);
            time.stopCountingTime();
            allTime[4]+=time.elapsedTime();
            time.startCountingTime();
            array.popByIdx(array.returnSize()/2);
            time.stopCountingTime();
            allTime[5]+=time.elapsedTime();
            time.startCountingTime();
            array.printByIdx(array.returnSize()/2);
            time.stopCountingTime();
            allTime[6]+=time.elapsedTime();
        }
        std::cout<<oper<<std::endl;
        oper++;
        for (long long i : allTime)
        {
            std::cout<<i/100<<std::endl;
        }
    }


}

void outcomes::testList() {
    stopWatch time;
    DataGenerator gen;
    int oper=1;
    long long allTime[7];
    for (long long & i : allTime) {
        i = 0;
    }
    for (int j = 5000; j < 50000; j = j + 5000)
    {

        for(int i=0;i<100;i++)
        {
            gen.genrateToFile(1,1000,j,"txtToCheck.txt");
            List list;
            list.readFromFile("txtToCheck.txt","push");
            time.startCountingTime();
            list.push(1);
            time.stopCountingTime();
            allTime[0]+=time.elapsedTime();
            time.startCountingTime();
            list.pop();
            time.stopCountingTime();
            allTime[1]+=time.elapsedTime();
            time.startCountingTime();
            list.pushBack(1);
            time.stopCountingTime();
            allTime[2]+=time.elapsedTime();
            time.startCountingTime();
            list.popBack();
            time.stopCountingTime();
            allTime[3]+=time.elapsedTime();
            time.startCountingTime();
            list.pushIx(list.returnSize()/2,1);
            time.stopCountingTime();
            allTime[4]+=time.elapsedTime();
            time.startCountingTime();
            list.popByIdx(list.returnSize()/2);
            time.stopCountingTime();
            allTime[5]+=time.elapsedTime();
            time.startCountingTime();
            list.showIx(list.returnSize()/2);
            time.stopCountingTime();
            allTime[6]+=time.elapsedTime();
        }
        std::cout<<oper<<std::endl;
        oper++;
        for (long long i : allTime)
        {
            std::cout<<i/100<<std::endl;
        }
    }
}

void outcomes::testHeap() {
    stopWatch time;
    DataGenerator gen;
    int oper=1;
    long long allTime[3];
    for (long long & i : allTime) {
        i = 0;
    }
    for (int j = 5000; j < 50000; j = j + 5000)
    {

        for(int i=0;i<100;i++)
        {
            gen.genrateToFile(1,100,j,"txtToCheck.txt");
            bin_heap heap;
            heap.readFromFile("txtToCheck.txt");
            time.startCountingTime();
            heap.push(1);
            time.stopCountingTime();
            allTime[0]+=time.elapsedTime();
            time.startCountingTime();
            heap.pop();
            time.stopCountingTime();
            allTime[1]+=time.elapsedTime();
            time.startCountingTime();
            heap.showByIx(heap.returnSize()/2);
            time.stopCountingTime();
            allTime[2]+=time.elapsedTime();

        }
        std::cout<<oper<<std::endl;
        oper++;
        for (long long i : allTime)
        {
            std::cout<<i/100<<std::endl;
        }
    }
}
