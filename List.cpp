
#include "List.h"
#include <cstdlib>
#include<iostream>
#include <string>
#include <fstream>
#include <cctype>
//inicjalizuje zmienne klasy
List::List() {
    head = nullptr;
    tail = nullptr;
    iter = 0;
    size = 0;
}

//usuwam tak by nie było przecieku
List::~List() {
    Element *current;
    for (int i = 0; i < size; i++) {
        current = head->nextElement;
        free(head);
        head = current;
    }
}

void List::push(int data) {
    //zwiekszam rozmiar i tworze nowy element
    size++;
    Element *current;
    current = (Element *) malloc(sizeof(Element));
    iter++;
    //sprawdzam czy istnieje głowa listy
    if (head == nullptr) {
        //jezeli nie istnieje glowa to glowa jest aktualnie nowym utworzonym elementem podobnie jak ogon
        head = current;
        head->elementData = data;
        head->previousElement = nullptr;
        head->nextElement = nullptr;
        tail = head;
    } else {
        //jeżeli głowa istnieje to zastępuje pierwszy element nowym
        current->elementData = data;
        current->nextElement = head;
        current->previousElement = nullptr;
        head->previousElement = current;
        head = current;
        if (iter == 3) {
            tail->previousElement = head;
        }
    }
}

void List::pushBack(int data) {
//postępuje bardzo podobnie jak w funkcji push
    if (size == 0) {
        Element *current;
        current = (Element *) malloc(sizeof(Element));
        head = current;
        tail = current;
        head->elementData = data;
        head->previousElement = nullptr;
        head->nextElement = nullptr;
    } else {
        Element *current;
        current = (Element *) malloc(sizeof(Element));
        //nowy element staje się elementem ostatnim
        current->elementData = data;
        current->previousElement = tail;
        current->nextElement = nullptr;
        tail->nextElement = current;
        tail = current;
    }
    size++;
}

void List::display(Element *curr) const {
    std::cout << "head: " << head;
    std::cout << " head.next: " << head->nextElement;
    std::cout << " head.priv: " << head->previousElement;
    std::cout << "tail : " << tail;
    std::cout << " tail.next: " << tail->nextElement;
    std::cout << " tail.priv: " << tail->previousElement;
    std::cout << " cur: " << curr;
    std::cout << std::endl;
}

void List::showList() const {
    Element *current;
    current = head;
    if (size == 0) {
        std::cout << "There is nothing to show. The list is empty." << std::endl;
    } else {
        std::cout << "This is your list: ";
        while (current != nullptr) {
            std::cout << current->elementData << " ";
            if (current == tail)
                break;
            current = current->nextElement;
        }
    }
}

void List::pop() { //postępuje podobnie jak w funkcji popBack tylko że tym razem dla head'a
    if (size == 0) {
        std::cerr << "The list is empty.There is nothing to pop!" << std::endl;
    } else {
        size--;
        if (head->nextElement == nullptr) {
            free(head);
        } else {
            Element *ptr;
            ptr = head->nextElement;
            free(head);
            head = ptr;
        }
    }
}

void List::popBack() {
    //sprawdzam czy lista nie jest pusta
    if (size == 0) {
        std::cerr << "The list is empty.There is nothing to popBack!" << std::endl;
        return;
    }
        //usuwam ostatni element czyli ogon
    else {
        size--;
        //jezeli ogon jest pierwszym elementem to uwalniam ogon
        if (tail->previousElement == nullptr) {
            free(tail);
        } else {
            //jezeli nie to zapisuje w zmiennej pomocniczej poprzedni element od ogona, usuwam ogon a nastepnie przypisuje do ogona zmienną pomocniczą
            Element *ptr;
            ptr = tail->previousElement;
            free(tail);
            tail = ptr;
            tail->nextElement = nullptr;
        }
    }
}



void List::pushIx(int index, int value) {
    //kiedy element jest na pierwszym miejscu to wykonuje zwykły push
    Element *current;
    if (index == 0) {
        push(value);
        return;
    }
        //wyjatek kiedy index > size -1 i < 0 i kiedy value is not int
    else if ((index > size - 1 and size > 0) || index < 0) {
        std::cerr << " pushIx: It's not a proper index.";
        return;
    }
        //kiedy indeks jest ostatnim elementem to wykonuje pushback
//    else if (index == size - 1 and size != 0) {
//        pushBack(value);
//        return;
        //  }
        //jezeli indeks jest mniejszy równy połowie rozmiaru wtedy operuje na głowie listy
    else if (index <= size / 2) {
        //tworze nowy element
        Element *newOne;
        newOne = (Element *) malloc(sizeof(Element));
        size++;
        current = head;
        int counter = 0;
        //dopóki nie znajdę indeksu przechodzę się po liście
        while (counter < index - 1) {
            current = current->nextElement;
            counter++;
        }
        //zapisuje element o zadanym indeksie do zmiennej tymczasowej
        Element *ptr;
        ptr = current->nextElement;
        //przypisuje odpowiednie waartości nowemu elementowi oraz elementom obok
        current->nextElement = newOne;
        current->nextElement->previousElement = current;
        current->nextElement->elementData = value;
        ptr->previousElement = current->nextElement;
        current->nextElement->nextElement = ptr;

    }
        //działam podobnie jak powyżej tylko zaczynam od ogona
    else if (index > size / 2 && index < size) {
        Element *newOne;
        newOne = (Element *) malloc(sizeof(Element));
        size++;
        current = tail;
        int counter = size - 1;
        while (counter > index + 1) {
            current = current->previousElement;
            counter--;
        }
        Element *ptr;
        ptr = current->previousElement;
        current->previousElement = newOne;
        current->previousElement->nextElement = current;
        current->previousElement->elementData = value;
        ptr->nextElement = current->previousElement;
        current->previousElement->previousElement = ptr;
    }

}

int List::showIx(int index) const {
    //sprawdzam warunek indeksu
    if (index > size - 1 || index < 0) {
        std::cerr << " showIx: It's not a proper index.";
        exit(-1);
    }
    Element *current;
    //sprawdzam czy indeks nie jest pierwszy lub ostatni
    if (index == 0)
        return head->elementData;
    else if (index == size - 1 and size != 0)
        return tail->elementData;
        //sprawdzam w której połowie listy jest indeks
    else if (index <= size / 2) {
        //jezeli w tej powłowie to zaczynam poszukiwania od head a jeżeli nie to zaczynam od tail
        current = head;
        int counter = 0;
        while (counter < index - 1) {
            current = current->nextElement;
            counter++;
        }
        return current->nextElement->elementData;
    } else if (index > size / 2 && index < size) {
        current = tail;
        int counter = size - 1;
        while (counter > index) {
            current = current->previousElement;
            counter--;
        }
        return current->previousElement->elementData;
    }
    return -1;

}

void List::readFromFile(const std::string &filename, const std::string &operation) {
    //funkcja działa tak samo jak dla dynamic array
    std::ifstream read;
    read.open(filename);
    if (!read.good()) {
        std::cerr << "cannot open file " << filename << "List - read from file " << std::endl;
        return;
    }
    int var;
    while (read >> var) {
        if (!isblank(var)) {
            if (operation == "pushBack" or operation == "fill")
                pushBack(var);
            else if (operation == "push")
                push(var);
        }
    }
    read.close();

}

int List::returnSize() const {
    return this->size;
}

void List::popByIdx(int index) { // funkcja bardzo podobna do pushByIdx
    if (index > size - 1 || index < 0) {
        std::cerr << " popByIx: It's not a proper index.";
        return;
    }
    Element *current;
    if (size == 0) {
        std::cerr << " popByIx: the list is empty.";
        return;
    }
    if (index == 0) {
        pop();
        return;
    } else if (index == size - 1 and size != 0)
        popBack();
    else if (index <= size / 2) {

        current = head;
        int counter = 0;
        while (counter < index - 1) {
            current = current->nextElement;
            counter++;
        }
        Element *ptr;
        ptr = current->nextElement;
        current->nextElement = ptr->nextElement;
        current->nextElement->previousElement = current;
        free(ptr);
        size--;
    } else if (index > size / 2 && index < size) {
        current = tail;
        int counter = size - 1;
        while (counter > index - 1) {
            current = current->previousElement;
            counter--;
        }
        Element *ptr;
        ptr = current->nextElement;
        current->nextElement = ptr->nextElement;
        current->nextElement->previousElement = current;
        free(ptr);
        size--;
    }
}