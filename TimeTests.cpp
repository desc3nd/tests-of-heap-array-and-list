

#include <iostream>
#include "TimeTests.h"

void TimeTests::TestList() {
    int action = 0;
    stopWatch time{};
    //dopoki uzytkownik nie wpisze -1
    while (action != -1) {
        operationMenu();
        std::cin >> action;
        if (action == -1)
            return;
        else if (action == 1) {
            long long allTime = 0;
            //100 razy wykonuje odpowiedią operacje
            for (int i = 0; i < numberOfRepeat; i++) {
                List list;
                //ładuje dane z pliku
                list.readFromFile("txtToCheck.txt", "push");
                //włączam stoper
                time.startCountingTime();
                //wykonuje operacje
                list.push(1);
                //wyłączam stoper
                time.stopCountingTime();
                allTime += time.elapsedTime();
            }
            //wypisuje średni czas
            std::cout << "time : " << allTime / 100 << std::endl;
            std::cout << std::endl << "Success!" << std::endl;
        }
            //w kolejnych else ifach działam tak samo jak w pierwszym
        else if (action == 2) {

            long long allTime = 0;
            for (int i = 0; i < numberOfRepeat; i++) {
                List list;
                list.readFromFile("txtToCheck.txt", "pushBack");
                time.startCountingTime();
                list.pop();
                time.stopCountingTime();
                allTime += time.elapsedTime();
            }
            std::cout << "time : " << allTime / 100 << std::endl;
            std::cout << std::endl << "Success!" << std::endl;
        } else if (action == 3) {
            long long allTime = 0;
            for (int i = 0; i < numberOfRepeat; i++) {
                List list;
                time.startCountingTime();
                list.readFromFile("txtToCheck.txt", "pushBack");
                time.stopCountingTime();
                allTime += time.elapsedTime();
            }
            std::cout << "time : " << allTime / 100 << std::endl;
            std::cout << std::endl << "Success!" << std::endl;
        } else if (action == 4) {
            List list;
            list.readFromFile("txtToCheck.txt", "pushBack");
            while (list.returnSize() > 0) {
                time.startCountingTime();
                list.popBack();
                time.stopCountingTime();
                std::cout << "time : " << time.elapsedTime() << std::endl;
            }
            list.showList();
            std::cout << std::endl << "Success!" << std::endl;
        } else if (action == 5) {
            List list;
            int count = 0;
            list.readFromFile("txtToCheck.txt", "pushBack");
            int size = list.returnSize();
            while (count != size) {
                time.startCountingTime();
                list.pushIx(rand() % (list.returnSize()), rand() % 1000);
                time.stopCountingTime();
                std::cout << "time : " << time.elapsedTime() << std::endl;
                count++;
            }
            list.showList();
            std::cout << std::endl << "Success!" << std::endl;
        } else if (action == 6) {
            List list;
            list.readFromFile("txtToCheck.txt", "pushBack");
            while (list.returnSize() != 0) {
                int toDelete = rand() % list.returnSize();
                time.startCountingTime();
                list.popByIdx(toDelete);
                time.stopCountingTime();
                list.showList();
                std::cout << "time : " << time.elapsedTime() << std::endl;
            }
            std::cout << std::endl << "Success!" << std::endl;
        } else if (action == 7) {
            List list;
            list.readFromFile("txtToCheck.txt", "pushBack");
            time.startCountingTime();
            list.showList();
            time.stopCountingTime();
            std::cout << "time : " << time.elapsedTime() << std::endl;
            std::cout << std::endl << "Success!" << std::endl;
        } else if (action == 8) {
            List list;
            list.readFromFile("txtToCheck.txt", "pushBack");
            time.startCountingTime();
            list.showIx(rand() % list.returnSize());
            time.stopCountingTime();
            std::cout << "time : " << time.elapsedTime() << std::endl;
            std::cout << std::endl << "Success!" << std::endl;
        } else
            std::cout << std::endl << "Wrong action! Type again!" << std::endl;
    }

}

//funkcja drukująca
void TimeTests::operationMenu() const {
    std::cout << "Choose what operation you want to test: " << std::endl;
    std::cout << "1.Push" << std::endl;
    std::cout << "2.Pop" << std::endl;
    std::cout << "3.Push Back:" << std::endl;
    std::cout << "4.Pop Back:" << std::endl;
    std::cout << "5.Insert:" << std::endl;
    std::cout << "6.Delete:" << std::endl;
    std::cout << "7.Print element:" << std::endl;
    std::cout << "8.Print Structure:" << std::endl;
    std::cout << "-1.Return to main menu" << std::endl;

}

//wykonuje te same czynności co dla listy
void TimeTests::TestDynamicArray() {
    int action = 0;
    stopWatch time{};
    while (action != -1) {
        operationMenu();
        std::cin >> action;
        if (!std::cin) {
            break;
        } else if (action == -1)
            return;
        else if (action == 1) {
            long long allTime = 0;
            for (int i = 0; i < numberOfRepeat; i++) {
                dynamicArray array;
                array.readFromFile("txtToCheck.txt", "push");
                time.startCountingTime();
                array.pushFront(1);
                time.stopCountingTime();
                allTime += time.elapsedTime();
            }
            std::cout << "time : " << allTime / 100 << std::endl;
            std::cout << std::endl << "Success!" << std::endl;

        } else if (action == 2) {
            long long allTime = 0;
            for (int i = 0; i < numberOfRepeat; i++) {
                dynamicArray array;
                array.readFromFile("txtToCheck.txt", "pushBack");
                time.startCountingTime();
                array.popBack();
                time.stopCountingTime();
                allTime += time.elapsedTime();
            }
            std::cout << "time : " << allTime / 100 << std::endl;
            std::cout << std::endl << "Success!" << std::endl;
        } else if (action == 3) {
            long long allTime = 0;
            for (int i = 0; i < numberOfRepeat; i++) {
                dynamicArray array;
                array.readFromFile("txtToCheck.txt", "pushBack");
                time.startCountingTime();
                array.pushBack(1);
                time.stopCountingTime();
                allTime += time.elapsedTime();
            }
            std::cout << "time : " << allTime / 100 << std::endl;
            std::cout << std::endl << "Success!" << std::endl;
        } else if (action == 4) {
            long long allTime = 0;
            for (int i = 0; i < numberOfRepeat; i++) {
                dynamicArray array;
                array.readFromFile("txtToCheck.txt", "pushBack");
                time.startCountingTime();
                array.popBack();
                time.stopCountingTime();
                allTime += time.elapsedTime();

            }
            std::cout << "time : " << allTime / 100 << std::endl;
            std::cout << std::endl << "Success!" << std::endl;
        } else if (action == 5) {
            long long allTime = 0;
            for (int i = 0; i < 101; i++) {
                dynamicArray array;
                array.readFromFile("txtToCheck.txt", "pushBack");
                time.startCountingTime();
                array.pushByIdx(array.returnSize() / 2, 1);
                time.stopCountingTime();
                allTime += time.elapsedTime();
            }
            std::cout << "time : " << allTime / 100 << std::endl;
            std::cout << std::endl << "Success!" << std::endl;
        } else if (action == 6) {
            long long allTime = 0;
            for (int i = 0; i < numberOfRepeat; i++) {
                dynamicArray array;
                array.readFromFile("txtToCheck.txt", "pushBack");
                int toDelete = array.returnSize() / 2;
                time.startCountingTime();
                array.popByIdx(toDelete);
                time.stopCountingTime();
                allTime += time.elapsedTime();
            }
            std::cout << "time : " << allTime / 100 << std::endl;
            std::cout << std::endl << "Success!" << std::endl;
        } else if (action == 8) {
            dynamicArray array;
            array.readFromFile("txtToCheck.txt", "pushBack");
            time.startCountingTime();
            array.arrayDisplay();
            time.stopCountingTime();
            std::cout << "time : " << time.elapsedTime() << std::endl;
            std::cout << std::endl << "Success!" << std::endl;
        } else if (action == 7) {
            long long allTime = 0;
            for (int i = 0; i < numberOfRepeat; i++) {
                dynamicArray array;
                array.readFromFile("txtToCheck.txt", "pushBack");
                time.startCountingTime();
                array.printByIdx(rand() % array.returnSize());
                time.stopCountingTime();
                allTime += time.elapsedTime();
            }
            std::cout << "time : " << allTime / 100 << std::endl;
            std::cout << std::endl << "Success!" << std::endl;
        } else
            std::cout << std::endl << "Wrong action! Type again!" << std::endl;
    }


}

//wykonuje te same czynności co dla listy i tablicy dynamicznej
void TimeTests::TestBinHeap() {
    int action = 0;
    stopWatch time{};
    while (action != -1) {
        std::cout << "Choose what operation you want to test: " << std::endl;
        std::cout << "1.Push" << std::endl;
        std::cout << "2.Pop" << std::endl;
        std::cout << "3.Print Structure:" << std::endl;
        std::cout << "-1.Return to main menu" << std::endl;
        std::cin >> std::oct >> action;
        if (action == -1) {
            return;
        } else if (action == 1) {
            bin_heap heap;
            time.startCountingTime();
            heap.readFromFile("txtToCheck.txt");
            time.stopCountingTime();
            std::cout << "time : " << time.elapsedTime() << std::endl;
            heap.displayHeap();
            std::cout << std::endl << "Success!" << std::endl;
        } else if (action == 2) {
            bin_heap heap;
            heap.readFromFile("txtToCheck.txt");
            heap.displayHeap();
            while (heap.returnSize() != 0) {
                time.startCountingTime();
                heap.pop();
                time.stopCountingTime();
                std::cout << "time : " << time.elapsedTime() << std::endl;
            }
            heap.displayHeap();
            std::cout << std::endl << "Success!" << std::endl;
        } else if (action == 3) {
            bin_heap heap;
            heap.readFromFile("txtToCheck.txt");
            time.startCountingTime();
            heap.displayHeap();
            time.stopCountingTime();
            std::cout << "time : " << time.elapsedTime() << std::endl;
            std::cout << std::endl << "Success!" << std::endl;
        } else
            std::cout << std::endl << "Wrong action! Type again!" << std::endl;
    }
}

TimeTests::TimeTests() {
    numberOfRepeat = 101;
}
