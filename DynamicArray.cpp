

#include "DynamicArray.h"
#include <memory>
#include <iostream>
#include <fstream>

DynamicArray::DynamicArray() {
    size = 0;
    head = nullptr;
}

void DynamicArray::pushBack(int data) {

    int *newHead= new int [size + 1];
    newHead[size]=data;
    for(int i = 0; i < size; i++)
    {
        newHead[i]=head[i];
    }
    delete [] head;
    size++;
    head = newHead;
}

void DynamicArray::arrayDisplay() {
    std::cout<<std::endl<<"this is your Dynamic Array: ";
    for (int i=0;i<size;i++)
    {
        std::cout<<head[i]<<" ";
    }
std::cout<<std::endl;
}

void DynamicArray::test() {
    std::cout<<std::endl<<"this is your test Array: ";
    for (int i=0;i<size;i++)
    {
        std::cout<<&head[i]<<" ";
    }
    std::cout<<std::endl;
}

void DynamicArray::pushFront(int data) {
    int *newHead = new int [size + 1];

    for(int i = 0; i < size; i++)
    {
        newHead[i+1]=head[i];
    }
    newHead[0]=data;
    size++;
    delete [] head;
    head=newHead;

}

void DynamicArray::pushByIdx(int idx, int data) {
    if (idx>size || idx<0)
    {
        std::cerr<<"idx out off range - pushByIdx";
    } else
    {
        int *newHead = new int[size + 1];
        newHead[idx]=data;
        for (int i = 0; i < size; i++)
        {
            if(i < idx)
            newHead[i] = head[i];

            else
                newHead[i+1]=head[i];
        }
        size++;
        delete [] head;
        head = newHead;
    }
}

void DynamicArray::popByIdx(int idx) {

    if(idx < 0 || idx >= size )
    {
        std::cerr<<"index out off range  - popbyidx";
        return;
    }
    if( size == 0 )
    {
        std::cerr<<"size is equal 0 - popbyidx";
        return;
    }
    int *newHead = new int [size - 1];
    for (int i = 0; i < size - 1; i++)
    {
        if(i < idx)
            newHead[i] = head[i];
        else
            newHead[i] = head[i + 1];
    }
    size--;
    delete []  head;
    head = newHead;

}

void DynamicArray::popBack() {
    popByIdx(size - 1);

}

void DynamicArray::popFront() {
    popByIdx(0);

}

DynamicArray::~DynamicArray() {
    if (head != nullptr) {
        delete[] head;
    }

}

int DynamicArray::printByIdx(int idx) {
    if (idx < 0 || idx >= size) {
        std::cerr << "index out off range  - printByIdx";
        return -1;
    }
    return head[idx];


}

void DynamicArray::readFromFile(const std::string &filename, const std::string &operation) {
    std::ifstream read;
    read.open(filename);
    if (!read.good()) {
        std::cerr << "cannot open file " << filename << "DynamicArray - read from file " << std::endl;
        return;
    }
    int var;
    while (read >> var) {
        if (!isblank(var)) {
            if (operation == "pushBack" or operation == "fill")
                pushBack(var);
            else if (operation == "push")
                pushFront(var);
        }
    }
    read.close();

}

int DynamicArray::returnSize() {
    return size;
}

