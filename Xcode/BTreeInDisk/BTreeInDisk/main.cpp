//
//  main.cpp
//  BTreeInDisk
//
//  Created by Jonathan Ginsburg on 9/28/15.
//  Copyright © 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "BTreeInDisk.h"

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
    
    BTreeInDisk<std::string> tree(Helper::readLine("Provide a directory:"), Helper::readLine("Provide a name:"), Helper::read<int>("Provide an order:"));
    
    while (true) {
        Helper::print("1 for inserting in tree.");
        Helper::print("2 for deleting from tree.");
        Helper::print("3 for searching in tree.");
        Helper::print("4 for printing tree in ascending order.");
        Helper::print("5 for printing tree in descending order.");
        Helper::print("0 for terminating program.");
        int input = Helper::read<int>("Enter your choice:");
        switch (input) {
            case 0:
                return 0;
                break;
            case 1:
                tree.Insert(Helper::readLine("Enter value to insert:"));
                break;
            case 2:
                tree.Erase(Helper::readLine("Enter value to delete:"));
                break;
            case 4:
                tree.PrintAscending();
                break;
            case 5:
                tree.PrintDescending();
                break;
            case 3:
                std::string wasFound = tree.Search(Helper::readLine("Enter value to search:")) ? " " : " not ";
                std::cout << "Value was" << wasFound << "found" << std::endl;
                break;
        }
    }
    
//    std::vector<std::string> originalValues;
//    std::vector<std::string> deletedValues;
//    BTreeInDisk<std::string> tree(".", "firsttry", 2);
//    srand ((unsigned int)time(NULL));
//    for (int i = 0; i < 10; ++i) {
//        std::string value = Helper::readLine("Give me some string to insert:");
//        tree.Insert(value);
//        originalValues.push_back(value);
//    }
//    std::cout << originalValues << std::endl;
//    std::string isLegal = tree.IsLegal() ? "Tree follows B Tree rules." : "Tree does not follow B Tree rules.";
//    std::cout << isLegal << std::endl;
//    std::string input = "";
//    do {
//        input = Helper::readLine("Give me a string to search or no for continuing:");
//        if (tree.Search(input)) {
//            std::cout << "Value was found in tree." << std::endl;
//        }
//        else std::cout << "Value was not found in tree." << std::endl;
//    } while (input != "no");
//    //    int i = 0;
//    while (!tree.IsEmpty()) {
//        int index = (rand() % originalValues.size());
//        std::string valueToErase = originalValues[index];
//        std::cout << std::endl;
//        deletedValues.push_back(valueToErase);
//        tree.PrintAscending();
//        tree.PrintDescending();
//        std::cout << "Val to erase: " << valueToErase << ".";
//        std::cout << std::endl << "Deleted Values: " << deletedValues;
//        std::cout.flush();
//        tree.Erase(valueToErase);
//        originalValues.erase(originalValues.begin() + index);
//    }
//    std::cout << std::endl;
}
