//
//  main.cpp
//  BinarySearchTree
//
//  Created by Jonathan Ginsburg on 9/5/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "BinarySearchTree.h"

int main(int argc, const char * argv[]) {
    int numArray[] = {10, 5, 3, 2, 1, 4, 7, 6, 8, 9, 15, 13, 11, 12, 17, 16, 20, 19, 18, 14};
    try {
        jgn::BinarySearchTree<int> tree;
        for (int i = 0; i < 20; ++i) {
            tree.Insert(numArray[i]);
        }
        tree.Erase(10);
        tree.Insert(10);
        tree.PrintDescending();
        tree.Clear();
        std::cout << tree.GetNodesDepth(10) << std::endl;
        std::cout << tree.GetNodesDepth(9) << std::endl;
        std::cout << tree.GetNodesLevel(3) << std::endl;
        std::cout << tree.GetNodesLevel(9) << std::endl;
    } catch (const char * exception) {
        std::cout << exception << std::endl; //No esta imprimiendo las excepciones
    }
    int a;
    std::cin >> a;
    return 0;
}
