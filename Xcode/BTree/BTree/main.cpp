//
//  main.cpp
//  BTree
//
//  Created by Jonathan Ginsburg on 9/9/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
// Code fetched from: http://www.geeksforgeeks.org/b-tree-set-1-introduction-2/

#include <iostream>
#include <vector>
#include "BTree.h"

// Driver program to test above functions
int main(int argc, const char * argv[]) {

    BTree<int> t(3); // A B-Tree with minium degree 3
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);
    
    cout << "Traversal of the constucted tree is ";
    t.traverse();
    
    int k = 6;
    (t.search(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present";
    
    k = 15;
    (t.search(k) != NULL)? cout << "\nPresent" : cout << "\nNot Present";
    
    return 0;
}