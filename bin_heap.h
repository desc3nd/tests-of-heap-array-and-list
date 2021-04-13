
#ifndef NOWY_BIN_HEAP_H
#define NOWY_BIN_HEAP_H


#include "DynamicArray.h"

class bin_heap {
public:
    explicit bin_heap();

    ~bin_heap();

    void push(int data);

    void displayHeap() const;

    int showByIx(int ix) const;

    void pop();

    void readFromFile(const std::string &filename);

    int returnSize() const;

private:
    void fixHeap();

    int *root;
    int size;

    void test() const;

    void fixAfterPop(int last);

};


#endif //NOWY_BIN_HEAP_H
