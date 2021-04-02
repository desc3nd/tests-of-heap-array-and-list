
#ifndef NOWY_DYNAMICARRAY_H
#define NOWY_DYNAMICARRAY_H


#include <string>

class DynamicArray {
public:
    explicit DynamicArray();
    ~DynamicArray();
    void pushBack(int data);
    void arrayDisplay();
    void pushFront(int data);
    void pushByIdx(int idx, int data);
    void popByIdx(int idx);
    void popBack();
    void popFront();
    int printByIdx(int idx);
    void readFromFile(const std::string& filename);


private:
    int size;
    int *head;
    void test();
};


#endif //NOWY_DYNAMICARRAY_H
