//
// Created by marcinek on 04.04.2021.
//

#include <iostream>
#include "menu.h"
#include "TimeTests.h"
void menu::displayMenu() {
    int action=0;
    TimeTests tests;
while(action!=-1)
    {
        std::cout<<"This is your program to test structures: List, Dynamic Array and Heap."<<std::endl<<"*note that all rights to this program are restricted and belong to Marcin Czerniawski"<<std::endl;
        std::cout<<"Choose structure to test:"<<std::endl;
        std::cout<<"1.List"<<std::endl;
        std::cout<<"2.Array"<<std::endl;
        std::cout<<"3.Binary Heap"<<std::endl;
        std::cout<<"-1 Quit program"<<std::endl;
        std::cin>>action;
        if(action==1)
            tests.TestList();
        if(action == 2)
            tests.TestDynamicArray();
        if(action == 3)
            tests.TestBinHeap();
        if(action == -1)
            exit(0);

    }
}
