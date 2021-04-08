

#include <iostream>
#include "TimeTests.h"

void TimeTests::TestList() {
    int action=0;
    stopWatch time;

    while(action!=-1)
    {
        operationMenu();
        std::cin>>action;

        if(action  == -1 )
            return;
        else if (action == 1)
        {
            List list;
           time.startCountingTime();
           list.readFromFile("txtToCheck.txt","push");
           time.stopCountingTime();
           std::cout<<"time : "<< time.elapsedTime()<<std::endl;
            list.showList();
            std::cout<<std::endl<<"Success!"<<std::endl;
        }
        else if (action == 2)
        {
            List list;
            list.readFromFile("txtToCheck.txt","pushBack");
            while(list.returnSize()  > 0)
            {
                time.startCountingTime();
                list.pop();
                time.stopCountingTime();
                std::cout<<"time : "<< time.elapsedTime()<<std::endl;
            }
            list.showList();
            std::cout<<std::endl<<"Success!"<<std::endl;
        }
        else if (action == 3)
        {
            List list;
            time.startCountingTime();
            list.readFromFile("txtToCheck.txt","pushBack");
            time.stopCountingTime();
            std::cout<<"time : "<< time.elapsedTime()<<std::endl;
            list.showList();
            std::cout<<std::endl<<"Success!"<<std::endl;
        }
        else if (action == 4)
        {
            List list;
            list.readFromFile("txtToCheck.txt","pushBack");
            while(list.returnSize() > 0)
            {
                time.startCountingTime();
                list.popBack();
                time.stopCountingTime();
                std::cout<<"time : "<< time.elapsedTime()<<std::endl;
            }
            list.showList();
            std::cout<<std::endl<<"Success!"<<std::endl;
        }
        else if (action == 5)
        {
            List list;
            int count=0;
            list.readFromFile("txtToCheck.txt","pushBack");
            int size=list.returnSize();
            while(count != size)
            {
                time.startCountingTime();
                list.pushIx(rand()%(list.returnSize()),rand()%1000);
                time.stopCountingTime();
                std::cout<<"time : "<< time.elapsedTime()<<std::endl;
                count++;
            }
            list.showList();
            std::cout<<std::endl<<"Success!"<<std::endl;
        }
        else if (action == 6)
        {
            List list;
            list.readFromFile("txtToCheck.txt","pushBack");
            while(list.returnSize() != 0 )
            {
                int toDelete=rand()%list.returnSize();
                std::cout<<toDelete<<std::endl;
                std::cout<<"to "<<list.returnSize()<<std::endl;
                time.startCountingTime();
                list.popByIdx(toDelete);
                time.stopCountingTime();
                list.showList();
                std::cout<<"time : "<< time.elapsedTime()<<std::endl;
            }
            std::cout<<std::endl<<"Success!"<<std::endl;
        }
        else if (action == 7)
        {
            List list;
            list.readFromFile("txtToCheck.txt","pushBack");
            time.startCountingTime();
            list.showList();
            time.stopCountingTime();
            std::cout<<"time : "<< time.elapsedTime()<<std::endl;
            std::cout<<std::endl<<"Success!"<<std::endl;
        }
        else if (action == 8)
        {
            List list;
            list.readFromFile("txtToCheck.txt","pushBack");
            time.startCountingTime();
            list.showIx(rand()%list.returnSize());
            time.stopCountingTime();
            std::cout<<"time : "<< time.elapsedTime()<<std::endl;
            std::cout<<std::endl<<"Success!"<<std::endl;
        }
        else
            std::cout<<std::endl<<"Wrong action! Type again!"<<std::endl;
    }

}

TimeTests::TimeTests() {

}

void TimeTests::operationMenu() {
    std::cout << "Choose what operation you want to test: " << std::endl;
    std::cout << "1.Push" << std::endl;
    std::cout << "2.Pop" << std::endl;
    std::cout << "3.Push Back:" << std::endl;
    std::cout << "4.Pop Back:" << std::endl;
    std::cout << "5.Insert:" << std::endl;
    std::cout << "6.Delete:" << std::endl;
    std::cout << "7.Print element:" << std::endl;
    std::cout << "8.Print Structure:" << std::endl;
    std::cout << "-1.Return to main menu" << std::endl;

}

void TimeTests::TestDynamicArray() {
    int action=0;
    stopWatch time;
    while(action!=-1)
    {
        operationMenu();
        std::cin>>action;

        if(action  == -1 )
            return;
        else if (action == 1)
        {
            DynamicArray array;
            time.startCountingTime();
            array.readFromFile("txtToCheck.txt","push");
            time.stopCountingTime();
            std::cout<<"time : "<< time.elapsedTime()<<std::endl;
            array.arrayDisplay();
            std::cout<<std::endl<<"Success!"<<std::endl;

        }
        else if (action == 2)
        {
            DynamicArray array;
            array.readFromFile("txtToCheck.txt","pushBack");
            while(array.returnSize() != 0)
            {
                time.startCountingTime();
                array.popBack();
                time.stopCountingTime();
                std::cout<<"time : "<< time.elapsedTime()<<std::endl;
            }
            array.arrayDisplay();
            std::cout<<std::endl<<"Success!"<<std::endl;
        }
        else if (action == 3)
        {
            DynamicArray array;
            time.startCountingTime();
            array.readFromFile("txtToCheck.txt","pushBack");
            time.stopCountingTime();
            std::cout<<"time : "<< time.elapsedTime()<<std::endl;
            array.arrayDisplay();
            std::cout<<std::endl<<"Success!"<<std::endl;
        }
        else if (action == 4)
        {
            DynamicArray array;
            array.readFromFile("txtToCheck.txt","pushBack");
            while(array.returnSize() > 0)
            {
                time.startCountingTime();
                array.popBack();
                time.stopCountingTime();
                std::cout<<"time : "<< time.elapsedTime()<<std::endl;
            }
            array.arrayDisplay();
            std::cout<<std::endl<<"Success!"<<std::endl;
        }
        else if (action == 5)
        {
            DynamicArray array;
            int count=0;
            array.readFromFile("txtToCheck.txt","pushBack");
            int size=array.returnSize();
            while(count != size)
            {
                time.startCountingTime();
                array.pushByIdx(rand()%(array.returnSize()),rand()%1000);
                time.stopCountingTime();
                std::cout<<"time : "<< time.elapsedTime()<<std::endl;
                count++;
            }
            array.arrayDisplay();
            std::cout<<std::endl<<"Success!"<<std::endl;
        }
        else if (action == 6)
        {
            DynamicArray array;
            array.readFromFile("txtToCheck.txt","pushBack");
            while(array.returnSize() != 0 )
            {
                int toDelete=rand()%array.returnSize();
                time.startCountingTime();
                array.popByIdx(toDelete);
                time.stopCountingTime();
                std::cout<<"time : "<< time.elapsedTime()<<std::endl;
            }
            array.arrayDisplay();
            std::cout<<std::endl<<"Success!"<<std::endl;
        }
        else if (action == 8)
        {
            DynamicArray array;
            array.readFromFile("txtToCheck.txt","pushBack");
            time.startCountingTime();
            array.arrayDisplay();
            time.stopCountingTime();
            std::cout<<"time : "<< time.elapsedTime()<<std::endl;
            std::cout<<"Success!"<<std::endl;
        }
        else if (action == 7)
        {
            DynamicArray array;
            array.readFromFile("txtToCheck.txt","pushBack");
            time.startCountingTime();
            array.printByIdx(rand()%array.returnSize());
            time.stopCountingTime();
            std::cout<<"time : "<< time.elapsedTime()<<std::endl;
            std::cout<<std::endl<<"Success!"<<std::endl;
        }
        else
            std::cout<<std::endl<<"Wrong action! Type again!"<<std::endl;
    }




}

void TimeTests::TestBinHeap() {

    int action = 0;
    stopWatch time;
    while (action != -1) {
        std::cout << "Choose what operation you want to test: " << std::endl;
        std::cout << "1.Push" << std::endl;
        std::cout << "2.Pop" << std::endl;
        std::cout << "3.Print Structure:" << std::endl;
        std::cout << "-1.Return to main menu" << std::endl;
        std::cin >> action;
        if (action == -1)
        {
            return;
        }
        else if (action == 1)
        {
            bin_heap heap;
            time.startCountingTime();
            heap.readFromFile("txtToCheck.txt");
            time.stopCountingTime();
            std::cout << "time : " << time.elapsedTime() << std::endl;
            heap.displayHeap();
            std::cout<<std::endl<<"Success!"<<std::endl;
        }
        else if (action == 2) {
            bin_heap heap;
            heap.readFromFile("txtToCheck.txt");
            heap.displayHeap();
            while (heap.returnSize() != 0) {
                time.startCountingTime();
                heap.pop();
                time.stopCountingTime();
                std::cout << "time : " << time.elapsedTime() << std::endl;
            }
            heap.displayHeap();
            std::cout<<std::endl<<"Success!"<<std::endl;
        }
        else if (action == 3) {
            bin_heap heap;
            heap.readFromFile("txtToCheck.txt");
            time.startCountingTime();
            heap.displayHeap();
            time.stopCountingTime();
            std::cout << "time : " << time.elapsedTime() << std::endl;
            std::cout<<std::endl<<"Success!"<<std::endl;
        }
        else
            std::cout<<std::endl<<"Wrong action! Type again!"<<std::endl;
    }
}