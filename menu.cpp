
#include <iostream>
#include "menu.h"
#include "TimeTests.h"
#include "DataGenerator.h"
#include "outcomes.h"

//inicjalizuje dane
void menu::displayMenu() const {
    int action = 0;
    TimeTests tests;
    //dopoki uzytkownik nie bedzie chcial wyjsc
    while (action != -1) {
        std::cout << "This is your program to test structures: List, Dynamic Array and Heap." << std::endl
                  << "*note that all rights to this program are restricted and belong to Marcin Czerniawski"
                  << std::endl;
        std::cout << "Choose structure to test:" << std::endl;
        std::cout << "1.List" << std::endl;
        std::cout << "2.Array" << std::endl;
        std::cout << "3.Binary Heap" << std::endl;
        std::cout << "4.Create numbers to test" << std::endl;
        std::cout << "5.Create test (average time of 100 of operations times with different values any time) "
                  << std::endl;
        std::cout << "6.Simple operations on structures " << std::endl;
        std::cout << "-1 Quit program" << std::endl;
        std::cin >> action;
        //jezeli wpisano cos innego niz inta to wyłącza program
        if (!std::cin) {
            action = 0;
            break;
        }
            //testuje odpowiednio operacje dzieki klasie Timetests
        else if (action == 1) {
            tests.TestList();
            std::cout << "Success!" << std::endl;
        } else if (action == 2) {
            tests.TestDynamicArray();
            std::cout << "Success!" << std::endl;
        } else if (action == 3) {
            tests.TestBinHeap();
            std::cout << "Success!" << std::endl;
        } else if (action == -1) {
            std::cout << "Hope to see you soon.Bay!" << std::endl;
            exit(0);
        }
            //mogę wpisać zakres danych do struktury oraz ilość startową tych struktur
        else if (action == 4) {
            int number = 0, range1 = 0, range2 = 0;
            DataGenerator generator;
            std::cout << "how many numbers do you want to test? NOTE THAT THE NUMBERS MUST BE INTEGERS" << std::endl;
            std::cin >> number;
            std::cout << "write range from" << std::endl;
            std::cin >> range1;
            std::cout << "write range to" << std::endl;
            std::cin >> range2;
            if (number < 0 or range2 < 0 or range1 < 0) {
                std::cerr << "wrong one or more of the numbers: number, range1 range2." << std::endl;
            } else
                generator.genrateToFile(range1, range2, number, "txtToCheck.txt");

        }
            //testuje klasą outcome testami szybkimi
        else if (action == 5) {
            logicOfChoosingStructure();
        }
            //testuje pojedyńczo operacje
        else if (action == 6) {
            logicOfChoosingOperation();
        } else
            std::cerr << "Wrong action. Try Again!" << std::endl;
    }
}

void menu::chooseStructurePrint() const {
    std::cout << "Choose structure:" << std::endl;
    std::cout << "1.List" << std::endl;
    std::cout << "2.Array" << std::endl;
    std::cout << "3.Binary Heap" << std::endl;
    std::cout << "-1 Return" << std::endl;
}


void menu::chooseOperationPrint() const {
    std::cout << "Choose operation:" << std::endl;
    std::cout << "1.Push" << std::endl;
    std::cout << "2.Pop" << std::endl;
    std::cout << "3.Push Back" << std::endl;
    std::cout << "4.Pop Back" << std::endl;
    std::cout << "5.Push By index" << std::endl;
    std::cout << "6.Print By index" << std::endl;
    std::cout << "7.Print strucutre" << std::endl;
    std::cout << "-1 Return" << std::endl;
}

void menu::logicOfChoosingStructure() const {//testuje za pomocą outcomes
    int numberOfStructure = 0;
    outcomes test;
    while (numberOfStructure != -1) {
        chooseStructurePrint();
        std::cin >> numberOfStructure;
        if (!std::cin) {
            break;
        } else if (numberOfStructure == 1) {
            test.testList();
        } else if (numberOfStructure == 2) {
            test.testArray();
        } else if (numberOfStructure == 3) {
            test.testHeap();
        } else if (numberOfStructure == -1) {
            return;
        } else {
            std::cerr << "Wrong number. Try again!";
        }
    }


}

void menu::logicOfChoosingOperation() const {
    int action = 0;
    dynamicArray array;
    bin_heap heap;
    List list;
    int data;
    while (action != -1) {
        chooseOperationPrint();
        std::cin >> action;
        if (!std::cin) {
            break;
        } else if (action == 1) {
            std::cout << "input data to push: ";
            std::cin >> data;
            list.push(data);
            list.showList();
            array.pushFront(data);
            array.arrayDisplay();
            heap.push(data);
            heap.displayHeap();
        } else if (action == 2) {
            list.pop();
            list.showList();
            array.popFront();
            array.arrayDisplay();
            heap.pop();
            heap.displayHeap();
        } else if (action == 3) {
            std::cout << "input data to push back: ";
            std::cin >> data;
            list.pushBack(data);
            list.showList();
            array.pushBack(data);
            array.arrayDisplay();
        } else if (action == 4) {
            list.popBack();
            list.showList();
            array.popBack();
            array.arrayDisplay();
        } else if (action == 5) {
            int index;
            std::cout << "input data to push by index: ";
            std::cin >> data;
            std::cout << "input index: ";
            std::cin >> index;
            list.pushIx(index, data);
            list.showList();
            array.pushByIdx(index, data);
            array.arrayDisplay();
        } else if (action == 6) {
            int index;
            std::cout << "input index: ";
            std::cin >> index;
            list.showIx(index);
            list.showList();
            array.printByIdx(index);
            array.arrayDisplay();
        } else if (action == 7) {
            list.showList();
            array.arrayDisplay();
        } else if (action == -1) {
            return;
        } else
            std::cout << std::endl << "Wrong action! Type again!" << std::endl;
    }

}

