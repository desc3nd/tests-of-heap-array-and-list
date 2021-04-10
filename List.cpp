
#include "List.h"
#include <cstdlib>
#include<iostream>
#include <string>
#include <fstream>
#include <cctype>
List::List() {
head= nullptr;
tail= nullptr;
iter=0;
size=0;
}
List::~List()
{
    Element *current;

    for (int i=0; i<size; i++) {
        current = head->nextElement;
        free(head);
        head=current;
    }


}
void List::push(int data) {
    size++;
    Element *current;
    current=(Element *)malloc(sizeof(Element));
    iter++;
    if(head==nullptr)
    {
        head=current;
        tail=head;
        head->elementData=data;
        head->previousElement=nullptr;
        head->nextElement=nullptr;

    }
    else
    {
        current->elementData=data;
        current->nextElement=head;
        current->previousElement=nullptr;
        head->previousElement=current;
        head=current;
        if (iter==3)
        {
            tail->previousElement=head;
        }

    }

}

void List::pushBack(int data) {

    if (size == 0)
    {   Element *current;
        current=(Element *)malloc(sizeof(Element));
        head=current;
        tail=current;
        head->elementData=data;
        head->previousElement=nullptr;
        head->nextElement=nullptr;

    }
    else
    {
        Element *current;
        current=(Element *)malloc(sizeof(Element));
        current->elementData=data;
        current->previousElement=tail;
        current->nextElement=nullptr;
        tail->nextElement=current;
        tail=current;
    }
    size++;
}

void List::display(Element *curr) {
    std::cout<<"head: "<<head;
    std::cout<<" head.next: "<<head->nextElement;
    std::cout<<" head.priv: "<<head->previousElement;
    std::cout<<"tail : "<<tail;
    std::cout<<" tail.next: "<<tail->nextElement;
    std::cout<<" tail.priv: "<<tail->previousElement;
    std::cout<<" cur: "<<curr;
    std::cout<<std::endl;
}

void List::showList() {
    Element *current;
    current=head;
    if(size==0)
    {
        std::cout<<"There is nothing to show. The list is empty."<<std::endl;
    }
    else
    {
        std::cout<<"This is your list: ";
        while(current!=nullptr)
        {
            std::cout<<current->elementData<<" ";
            if(current == tail)
                break;
            current=current->nextElement;
           // head=head->nextElement;
        }

    }

}

void List::pop() {
    if(size == 0)
    {
        std::cerr<<"The list is empty.There is nothing to pop!"<<std::endl;
    }
    else
    {
        size--;
        if(head->nextElement == nullptr)
        {
            free(head);
        }
        else
        {
            Element *ptr;
            ptr=head->nextElement;
            free(head);
            head=ptr;
        }
    }
}

void List::popBack() {
    if(size == 0)
    {
        std::cerr<<"The list is empty.There is nothing to popBack!"<<std::endl;
        return;
    }
    else
    {
        size--;
        if(tail->previousElement == nullptr)
        {
            //tail = nullptr;
            free(tail);
           // free(head);
        }
        else
        {
         Element *ptr;
         ptr = tail->previousElement;
         free(tail);
         tail = ptr;
         tail->nextElement=nullptr;
        }
    }
}



void List::pushIx(int index, int value) {
    Element *current;
    if (index == 0)
    {
        push(value);
        return;
    }
    //wyjatek kiedy index > size -1 i < 0 i kiedy value is not int
   else if((index > size - 1 and size>0) || index < 0)
    {
        std::cerr<<" pushIx: It's not a proper index.";
        return;
    }

    else if(index == size - 1 and size != 0)
    {
        pushBack(value);
        return;
    }

    else if(index <= size/2)
    {
        Element *newOne;
        newOne=(Element *)malloc(sizeof(Element));
        size++;
        current=head;
        int counter = 0;
        while(counter<index-1)
        {
            current=current->nextElement;
            counter++;
        }
        Element *ptr;
        ptr=current->nextElement;
        current->nextElement=newOne;
        current->nextElement->previousElement=current;
        current->nextElement->elementData=value;
        ptr->previousElement=current->nextElement;
        current->nextElement->nextElement=ptr;

    }
    else if (index >size/2 && index < size)
    {
        Element *newOne;
        newOne=(Element *)malloc(sizeof(Element));
        size++;
        current=tail;
        int counter = size-1;
        while(counter>index+1)
        {
            current=current->previousElement;
            counter--;
        }
        Element *ptr;
        ptr=current->previousElement;
        current->previousElement=newOne;
        current->previousElement->nextElement=current;
        current->previousElement->elementData=value;
        ptr->nextElement=current->previousElement;
        current->previousElement->previousElement=ptr;
    }

}

int List::showIx(int index) {
    if(index > size - 1 || index < 0)
    {
        std::cerr<<" showIx: It's not a proper index.";
        exit(-1);
    }
    Element *current;
    if (index == 0)
        return head->elementData;
    else if(index == size-1 and size != 0)
        return tail->elementData;
    else if(index <= size/2)
    {
        current=head;
        int counter = 0;
        while(counter<index-1)
        {
            current=current->nextElement;
            counter++;
        }
            return current->nextElement->elementData;
    }
    else if (index >size/2 && index < size)
    {
        current=tail;
        int counter = size-1;
        while(counter>index)
        {
            current=current->previousElement;
            counter--;
        }
            return current->previousElement->elementData;
    }
    return -1;

}

void List::readFromFile(const std::string& filename,const std::string& operation) {
    std::ifstream read;
    read.open(filename);
    if (!read.good())
    {
        std::cerr<<"cannot open file "<<filename<<"List - read from file " <<std::endl;
        return;
    }
    int var;
    while (read>>var)
    {
        if(!isblank(var))
        {
            if(operation=="pushBack" or operation=="fill")
            pushBack(var);
            else if (operation=="push")
                push(var);
        }
    }
    read.close();

}

int List::returnSize() {
    return this->size;
}

void List::popByIdx(int index) {
    if(index > size - 1 || index < 0)
    {
        std::cerr<<" popByIx: It's not a proper index.";
        return;
    }
    Element *current;
    if (size == 0)
    {
        std::cerr<<" popByIx: the list is empty.";
        return;
    }
    if(index == 0)
    {
        pop();
        return;
    }
    else if(index == size-1 and size != 0)
        popBack();
    else if(index <= size/2)
    {

        current=head;
        int counter = 0;
        while(counter<index-1)
        {
            current=current->nextElement;
            counter++;
        }
        Element *ptr;
        ptr=current->nextElement;
        current->nextElement = ptr->nextElement;
        current->nextElement->previousElement=current;
        free(ptr);
        size--;
    }
    else if (index >size/2 && index < size)
    {
        current=tail;
        int counter = size-1;
        while(counter>index-1)
        {
            current=current->previousElement;
            counter--;
        }
        Element *ptr;
        ptr=current->nextElement;
        current->nextElement = ptr->nextElement;
        current->nextElement->previousElement=current;
        free(ptr);
        size--;
    }
}

