//
// Created by marcinek on 04.04.2021.
//

#include <iostream>
#include "menu.h"
#include "TimeTests.h"
#include "DataGenerator.h"

void menu::displayMenu() {
    int action = 0;
    TimeTests tests;
    while (action != -1) {
        std::cout << "This is your program to test structures: List, Dynamic Array and Heap." << std::endl
                  << "*note that all rights to this program are restricted and belong to Marcin Czerniawski"
                  << std::endl;
        std::cout << "Choose structure to test:" << std::endl;
        std::cout << "1.List" << std::endl;
        std::cout << "2.Array" << std::endl;
        std::cout << "3.Binary Heap" << std::endl;
        std::cout << "4.Create numbers to test" << std::endl;
        std::cout << "-1 Quit program" << std::endl;
        std::cin >> action;
        if (action == 1) {
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
        } else if (action == 4) {
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

        } else
            std::cerr << "Wrong action. Try Again!" << std::endl;
    }
}
