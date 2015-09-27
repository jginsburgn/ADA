//
//  main.cpp
//  BTreeMemoryAttempt
//
//  Created by Jonathan Ginsburg on 9/11/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "BTree.h"

template <class T>
std::ostream & operator << (std::ostream & os, std::vector<T> values){
    for (int i = 0; i < values.size(); ++i) {
        os << values[i] << ", ";
    }
    return os;
}

int main(int argc, const char * argv[]) {
    std::vector<int> originalValues;
    std::vector<int> deletedValues;
    int bar [30] = {94, 8, 78, 60, 49, 64, 80, 93, 72, 34, 40, 18, 33, 68, 28, 12, 55, 65, 14, 19, 23, 6, 93, 79, 11, 41, 70, 66, 96, 14};
    int bar2 [18] = {55, 94, 72, 34, 23, 68, 6, 78, 96, 11, 8, 70, 14, 19, 93, 65, 49, 33};
    BTree<int> tree(8);
    srand ((unsigned int)time(NULL));
    for (int i = 0; i < 500; ++i) {
        int value = (rand() % 100000) + 1;
        //int value = bar[i];
        tree.Insert(value);
        originalValues.push_back(value);
    }
    std::cout << originalValues << std::endl;
    std::cout << std::endl;
    int i = 0;
    while (!tree.IsEmpty()) {
        int index = (rand() % originalValues.size());
        int valueToErase = originalValues[index];
        //int valueToErase = bar2[i++];
        if (valueToErase == 33) {
            int a;
            a = a;
        }
        std::cout << std::endl;
        deletedValues.push_back(valueToErase);
        std::cout << std::endl;
        tree.PrintAscending();
        std::cout << "Val to erase: " << valueToErase << ".";
        std::cout << std::endl << "Deleted Values: " << deletedValues;
        std::cout.flush();
        tree.Erase(valueToErase);
        originalValues.erase(originalValues.begin() + index);
    }
    std::cout.flush();
    return 0;
}
