

#ifndef NOWY_LIST_H
#define NOWY_LIST_H
#include<string>
struct Element {
    struct Element *nextElement;
    struct Element *previousElement;
    int elementData;
};

class List {
private:
    Element *head;
    Element *tail;

    void display(Element *curr) const;

    int iter;
    int size;
public:
    explicit List();

    ~List();

    void push(int data);

    void pushBack(int data);

    void showList() const;

    void pop();

    void popBack();

    int returnSize() const;

    void pushIx(int index, int value);

    int showIx(int index) const;

    void popByIdx(int index);

    void readFromFile(const std::string &filename, const std::string &operation);

};


#endif //NOWY_LIST_H
