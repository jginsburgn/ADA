//
//  main.cpp
//  TimingOfSearchingTreeAlgorithms
//
//  Created by Jonathan Ginsburg on 9/9/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <vector>
#include "../../BTreeInDisk/BTreeInDisk/BTreeInDisk.h"
#include "../../AVLTree/AVLTree/AVLTree.h"
#include "../../TwoThreeTree/TwoThreeTree/TwoThreeTree.h"
#include "../../RBTree/RBTree/RBTree.h"

//Fills vector with random numbers in range [1, 10000]
void FillIntVector(std::vector<int> & vector, const int size) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < size; ++i) vector.push_back((rand() % 1000000000) + 1);
}

int WhereIs(const char * array[], const int size, const char * string){
    for (int i = 0; i < size; ++i) {
        if (strcmp(array[i], string) == 0) {
            return i;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    using namespace std;
    using namespace chrono;
    
    int numberOfElements;
    int numberOfElementsToLookFor;
    int numberOfRepetitions;
    int order = 0;
    
    cout << endl << "Searching In Trees Time Meter 1.0 by Jonathan Ginsburg and Enrique Gonzales. (c) September 30, 2015. All rights reserved." << endl;
    
    if (argc == 1) {
        cout << "Type <<TimingOFSearchingTreeAlgorithms help>>" << endl;
        cout << endl;
        return 0;
    }
    else {
        if (WhereIs(argv, argc, "help") != -1) {
            cout << "This is a tool for timing searching algorithms in AVL, B, Red-Black and 2-3 trees written in C++. Use any of the following commands:" << endl;
            cout << "\t1. TimingOFSearchingTreeAlgorithms <arg1> <arg2> <arg3> <arg4>, where <arg1> is the population of elements in each tree, <arg2> is the number of elements to search for in each tree, <arg3> is the number of repetitions to make all measurements with different populations, and <arg4> is the order of the B Tree." << endl;
            
            cout << endl;
            return 0;
        }
        else if (argc == 5){
            numberOfElements = atoi(argv[1]);
            numberOfElementsToLookFor = atoi(argv[2]);
            numberOfRepetitions = atoi(argv[3]);
            order = atoi(argv[4]);
            if (numberOfElements > 0 && numberOfElementsToLookFor > 0 && numberOfRepetitions > 0 && order > 0) {
                if (numberOfElements > numberOfElementsToLookFor) {
                }
                else return 0;
            }
            else return 0;
        }
    }
    
    cout << endl;
    
    cout << "Number of elements in each tree = " << numberOfElements << ". Number of measurements to make = " << numberOfRepetitions << ". Number of elements to search for = " << numberOfElementsToLookFor << ":" << endl << endl;
    
    for (int i = 0; i < numberOfRepetitions; ++i) {
        
        vector<int> data;
        FillIntVector(data, numberOfElements);
        
        vector<int> dataToLookFor;
        for (int i = 0; i < numberOfElementsToLookFor; ++i) {
            dataToLookFor.push_back(data[i]);
        }
        
        cout << "\tFilling BTree of order " << order << ": ";
        std::cout.flush();
        BTreeInDisk<int> btree(".", "BTreeSpace", order);
        high_resolution_clock::time_point begin = high_resolution_clock::now();
        for (int i = 0; i < data.size(); ++i) {
            btree.Insert(data[i]);
        }
        high_resolution_clock::time_point end = high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << "\t" << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        cout << "\tSearching elements in BTree" << ": ";
        std::cout.flush();
        begin = high_resolution_clock::now();
        for (int i = 0; i < dataToLookFor.size(); ++i) {
            btree.Search(dataToLookFor[i]);
        }
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << "\t" << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        cout << "\tFilling AVLTree:";
        std::cout.flush();
        jgn::AVLTree<int> avltree;
        begin = high_resolution_clock::now();
        for (int i = 0; i < data.size(); ++i) {
            try {
                avltree.Insert(data[i]);
            }
            catch (const char * exception){
                
            }
        }
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << "\t" << "\t" << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        cout << "\tSearching elements in AVLTree" << ": ";
        std::cout.flush();
        begin = high_resolution_clock::now();
        for (int i = 0; i < dataToLookFor.size(); ++i) {
            try {
                avltree.Search(dataToLookFor[i]);
            } catch (const char * exception) {
            
            }
        }
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << "\t" << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        cout << "\tFilling 2-3Tree:";
        std::cout.flush();
        TwoThreeTree<int> _23tree;
        begin = high_resolution_clock::now();
        for (int i = 0; i < data.size(); ++i) {
            _23tree.insert(data[i]);
        }
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << "\t" << "\t" << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        cout << "\tSearching elements in 2-3Tree" << ": ";
        std::cout.flush();
        begin = high_resolution_clock::now();
        for (int i = 0; i < dataToLookFor.size(); ++i) {
            _23tree.search(dataToLookFor[i]);
        }
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << "\t" << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        cout << "\tFilling RBTree:";
        std::cout.flush();
        RBTree<int> rbtree;
        begin = high_resolution_clock::now();
        for (int i = 0; i < data.size(); ++i) {
            rbtree.Insert(data[i]);
        }
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << "\t" << "\t" << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        cout << "\tSearching elements in RBTree" << ": ";
        std::cout.flush();
        begin = high_resolution_clock::now();
        for (int i = 0; i < dataToLookFor.size(); ++i) {
            rbtree.Search(dataToLookFor[i]);
        }
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << "\t" << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        cout << endl;
    }
    
    cout << endl;
    return 0;
}
