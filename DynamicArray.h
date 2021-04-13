
#ifndef NOWY_DYNAMICARRAY_H
#define NOWY_DYNAMICARRAY_H
#include <string>

class dynamicArray {
public:
    explicit dynamicArray();

    ~dynamicArray();

    void pushBack(int data);

    void arrayDisplay() const;

    void pushFront(int data);

    void pushByIdx(int idx, int data);

    void popByIdx(int idx);

    void popBack();

    void popFront();

    int printByIdx(int idx) const;

    void readFromFile(const std::string &filename, const std::string &operation);

    int returnSize() const;

private:
    int size;
    int *head;

    void test() const;
};


#endif //NOWY_DYNAMICARRAY_H
