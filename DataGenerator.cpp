#include<string>
#include <fstream>
#include <iostream>
#include "DataGenerator.h"

void DataGenerator::genrateToFile(int range1, int range2, int quantity,const std::string &filename) {
    srand(time(NULL));
    std::ofstream write;
    write.open(filename);
    for(int i=0;i<=quantity;i++)
    {
        int number = rand()% range2 + range1;
        write << number;
        write << " ";
    }

    write.close();

}
