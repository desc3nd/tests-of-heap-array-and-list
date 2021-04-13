
#include <iostream>
#include <fstream>
#include "bin_heap.h"

bin_heap::bin_heap() {
    this->root = nullptr;
    size = 0;

}

void bin_heap::push(int data) {
    //deklaruje tablice o 1 wiekszą od poprzedniej
    int *newRoot = new int[size + 1];
    for (int i = 0; i < size; i++) {
        //przepisuje starą tablice do nowej
        newRoot[i] = root[i];
    }
    //zapisuje nowe dane usuwam starą tablice i zapisuje w jej miejsce nową do root
    newRoot[size] = data;
    delete[] root;
    root = newRoot;
    //sprawdzam warunki kopca i zwiekszam size
    fixHeap();
    size++;

}

void bin_heap::displayHeap() const {
    std::cout << "This is your heap: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << root[i] << " ";
    }
    std::cout << std::endl;

}

void bin_heap::test() const {
    std::cout << "This is your heap: " << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << &root[i] << " ";
    }
    std::cout << std::endl;

}

void bin_heap::fixHeap() { //naprawiam kopiec po pushu sprawdzajac warunki kopca
    int son = size;
    int parent = (son - 1) / 2;
    int temp = 0;
    while (son > 0 && root[parent] < root[son]) {
        temp = root[parent];
        root[parent] = root[son];
        root[son] = temp;
        son = parent;
        parent = (son - 1) / 2;
    }

}


void bin_heap::pop() { // podobnie jak w push tylko deklaruje tablice o 1 mniejsza
    if (size <= 0) {
        std::cerr << "heap is empty - pop";
        return;
    }
    int last = root[size - 1];
    int *newRoot = new int[size - 1];
    for (int i = 0; i < size - 1; i++) {
        newRoot[i] = root[i];
    }
    delete[] root;
    root = newRoot;
    size--;
    fixAfterPop(last);
}

void bin_heap::fixAfterPop(int last) { //naprawiam kopiec po popie sprawdzajac warunki kopca
    int parent = 0;
    int son = 2 * parent + 1;
    root[parent] = last;
    while (son < size) {
        if (son + 1 < size && root[son] < root[son + 1]) {
            son++;
        }
        if (root[parent] >= root[son]) {
            root[parent] = last;
            break;
        }
        int tmp = root[parent];
        root[parent] = root[son];
        root[son] = tmp;
        parent=son;
        son= 2 * parent + 1;
    }
}

bin_heap::~bin_heap() {
    if (size != 0)
        delete[] root;

}

void bin_heap::readFromFile(const std::string &filename) //funkcja taka sama jak dla tablicy i listy
{
    std::ifstream read;
    read.open(filename);
    if (!read.good()) {
        std::cerr << "cannot open file " << filename << "heap - read from file " << std::endl;
        return;
    }
    int var;
    while (read >> var) {
        if (!isblank(var)) {
            push(var);
        }
    }
    read.close();


}

int bin_heap::returnSize() const {
    return size;
}

int bin_heap::showByIx(int ix) const {
    //sprawdzam warunki indeksu
    if (ix > size - 1 or ix < 0) {
        std::cerr << "wrong ix -bean_heap::showByIx";
        return -1;
    }
    return root[ix];
}

