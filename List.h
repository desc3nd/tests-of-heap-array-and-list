

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
    void display(Element *curr);
    int iter;
     int size;
public:
    explicit List();
    ~List();
    void push(int data);
    void pushBack(int data);
    void showList();
    void pop();
    void popBack();
    int  returnSize();
    void pushIx(int index, int value);
    int showIx(int index);
    void popByIdx(int index);
    void readFromFile(const std::string& filename,const std::string& operation);

};


#endif //NOWY_LIST_H
