
#ifndef NOWY_BIN_HEAP_H
#define NOWY_BIN_HEAP_H


#include "DynamicArray.h"

class bin_heap {
public:
    explicit bin_heap();

    ~bin_heap();

    void push(int data);

    void displayHeap();

    void pop();

    void readFromFile(const std::string &filename);

    int returnSize();

private:
    void fixHeap();

    int *root;
    int size;

    void test();

    void fixAfterPop(int last);

};


#endif //NOWY_BIN_HEAP_H
