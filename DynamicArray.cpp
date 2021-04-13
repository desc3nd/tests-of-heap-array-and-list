

#include "dynamicArray.h"
#include <memory>
#include <iostream>
#include <fstream>

dynamicArray::dynamicArray() {
    size = 0;
    head = nullptr;
}

void dynamicArray::pushBack(int data) {
//tworze nową tablice o jeden większą od poprzedniej
    int *newHead = new int[size + 1];
    //zapisuje nowy element
    newHead[size] = data;
    //przepisuje starą tablice do nowej
    for (int i = 0; i < size; i++) {
        newHead[i] = head[i];
    }
    //usuwam starą tablice i zapisuje w jej miejce nową
    delete[] head;
    size++;
    head = newHead;
}

void dynamicArray::arrayDisplay() const {
    std::cout << std::endl << "this is your Dynamic Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << head[i] << " ";
    }
    std::cout << std::endl;
}

void dynamicArray::test() const {
    std::cout << std::endl << "this is your test Array: ";
    for (int i = 0; i < size; i++) {
        std::cout << &head[i] << " ";
    }
    std::cout << std::endl;
}

void dynamicArray::pushFront(int data) {
    //podobnie jak w pushBack
    int *newHead = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newHead[i + 1] = head[i];
    }
    //zapisuje w pierwszym elemencie nowe dane
    newHead[0] = data;
    size++;
    delete[] head;
    head = newHead;
}

void dynamicArray::pushByIdx(int idx, int data) {
//sprawdzam czy wprowadzone dane są ok
    if (idx > size || idx < 0) {
        std::cerr << "idx out off range - pushByIdx";
    } else {
        //tworze nową tablice i w miejsce przekazanego indeksu zapamietuje przekazane dane
        int *newHead = new int[size + 1];
        newHead[idx] = data;
        for (int i = 0; i < size; i++) {
            //tworze warunki by nie nadpisać wartości w miejscu przekazanym
            if (i < idx)
                newHead[i] = head[i];
            else
                newHead[i + 1] = head[i];
        }
        size++;
        //usuwam starą tablice i zapisuje nową do head
        delete[] head;
        head = newHead;
    }
}

void dynamicArray::popByIdx(int idx) {
//sprawdzam wszystkie warunki by nie wystąpił błąd indeksu
    if (idx < 0 || idx >= size) {
        std::cerr << "index out off range  - popbyidx";
        return;
    }
    if (size == 0) {
        std::cerr << "size is equal 0 - popbyidx";
        return;
    }
    //tworze tablice o jeden mniejsza i postępuje podobnie jak w przypadku dodawania elementu w dowolnym miejscu
    int *newHead = new int[size - 1];
    for (int i = 0; i < size - 1; i++) {
        if (i < idx)
            newHead[i] = head[i];
        else
            newHead[i] = head[i + 1];
    }
    size--;
    delete[]  head;
    head = newHead;
}

void dynamicArray::popBack() {
    popByIdx(size - 1);

}

void dynamicArray::popFront() {
    popByIdx(0);

}

//czyszcze zaalokowana pamięć
dynamicArray::~dynamicArray() {
    if (size != 0) {
        delete[] head;
    }

}

int dynamicArray::printByIdx(int idx) const {
    //sprawdzam warunki indeksu
    if (idx < 0 || idx >= size) {
        std::cerr << "index out off range  - printByIdx";
        return -1;
    }
    return head[idx];


}

void dynamicArray::readFromFile(const std::string &filename, const std::string &operation) {
    //otwieram plik do czytania z niego
    std::ifstream read;
    read.open(filename);
    //sprawdzam czy otwary poprawnie
    if (!read.good()) {
        std::cerr << "cannot open file " << filename << "dynamicArray - read from file " << std::endl;
        return;
    }
    //czytam każdą liczbę z pliku tekstowego omijając znaki białe
    int var;
    while (read >> var) {
        if (!isblank(var)) {
            //wypełniam tablice odpowiednimi danymi, odpowiednio wybranym działaniem
            if (operation == "pushBack" or operation == "fill")
                pushBack(var);
            else if (operation == "push")
                pushFront(var);
        }
    }
    read.close();

}

int dynamicArray::returnSize() const {
    return size;
}

