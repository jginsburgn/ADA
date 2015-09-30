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
    Helper::print("Welcome to the mini tester of BTrees. Jonathan Ginsburg (C) September 2015.");
    BTreeInDisk<std::string> tree(Helper::readLine("Provide a directory: "), Helper::readLine("Provide a name: "), Helper::read<int>("Provide an order: "));
    Helper::print("Disclaimer: Application will not work unless there is a directory in the provided directory address and a folder in it with the name of the name provided. In case these already existed and the tree was built previously, the current tree will represent that last saved version. Also please remember that this tree is for strings therefore \"36\" < \"8\".");
    while (true) {
        Helper::print("\t1 for inserting in tree.");
        Helper::print("\t2 for deleting from tree.");
        Helper::print("\t3 for searching in tree.");
        Helper::print("\t4 for printing tree in ascending order.");
        Helper::print("\t5 for printing tree in descending order.");
        Helper::print("\t0 for terminating program.");
        int input = Helper::read<int>("Enter your choice: ");
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
}
