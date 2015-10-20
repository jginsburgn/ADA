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
    if (values.size() == 0) {
        return os;
    }
    for (int i = 0; i < values.size() - 1; ++i) {
        os << values[i] << ", ";
    }
    os << values[values.size() - 1] << ".";
    return os;
}

int main(int argc, const char * argv[]) {
    std::vector<int> originalValues;
    std::vector<int> deletedValues;
    BTree<int> tree(8);
    srand ((unsigned int)time(NULL));
    for (int i = 0; i < 10; ++i) {
        int value = (rand() % 100000) + 1;
        tree.Insert(value);
        originalValues.push_back(value);
    }
    std::cout << ">> The following values were pushed in the BTree: " << originalValues << std::endl;
    std::string isLegal = tree.IsLegal() ? "Tree follows B Tree rules." : "Tree does not follow B Tree rules.";
    std::cout << ">> Testing legality of tree following BTree rules: " << isLegal << std::endl;
    int input = 0;
    do {
        std::cout << "Enter a value to search for in the BTree (-1 for stopping search): ";
        std::cin >> input;
        if (tree.Search(input)) {
            std::cout << ">> Value was found in tree." << std::endl;
        }
        else std::cout << ">> Value was not found in tree." << std::endl;
    } while (input != -1);
    std::cout << ">> Printing tree in ascending order: " << std::endl;
    tree.PrintAscending();
    std::cout << ">> Printing tree in descending order: " << std::endl;
    tree.PrintDescending();
    std::cout << ">> Proceeding to erase values in tree in random order: ";
    while (!tree.IsEmpty()) {
        int index = (rand() % originalValues.size());
        int valueToErase = originalValues[index];
        if (valueToErase == 33) {
            int a;
            a = a;
        }
        std::cout << std::endl;
        deletedValues.push_back(valueToErase);
        std::cout << ">> Val to erase: " << valueToErase << ".";
        std::cout << std::endl << ">> Deleted Values: " << deletedValues;
        std::cout.flush();
        tree.Erase(valueToErase);
        originalValues.erase(originalValues.begin() + index);
    }
    std::cout << std::endl;
    return 0;
}
