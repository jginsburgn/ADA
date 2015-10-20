//
//  main.cpp
//  AVLTree
//
//  Created by Jonathan Ginsburg on 9/8/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "AVLTree.h"
#include "../../Helper.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main(int argc, const char * argv[]) {
//    srand ((unsigned int)time(NULL));
//    jgn::AVLTree<int> tree;
//    for (int i = 0; i < 40; ++i) {
//        try {
//            tree.Insert(rand() % 100 + 1);
//        } catch (const char * e) {
//            std::cout << e << std::endl;
//        }
//    }
//    tree.PrintAscending();
    using namespace jgn;
    AVLTree<int> tree;
    Helper::print("Welcome to the int AVL Tree tester. Jonathan Ginsburg (C) September 2015.");
    while (true) {
        Helper::print("\t1 for inserting in tree.");
        Helper::print("\t2 for deleting from tree.");
        Helper::print("\t3 for searching in tree.");
        Helper::print("\t4 for printing tree in ascending order.");
        Helper::print("\t5 for printing tree in descending order.");
        Helper::print("\t6 for getting a height of a node in tree.");
        Helper::print("\t7 for getting a depth of a node in tree.");
        Helper::print("\t8 for getting a level of a node in tree.");
        Helper::print("\t9 for verifying legality of tree according to AVL rules.");
        Helper::print("\t0 for terminating program.");
        int input = Helper::read<int>(">> Enter your choice: ");
        int dummyHolder;
        switch (input) {
            case 0:
                return 0;
                break;
                
            case 1:
                try {
                    tree.Insert(Helper::read<int>(">> Enter value to insert: "));
                } catch (const char * e) {
                    Helper::print(e);
                }
                break;
                
            case 2:
                try {
                    tree.Erase(Helper::read<int>(">> Enter value to erase: "));
                } catch (const char * e) {
                    Helper::print(e);
                }
                break;
                
            case 3:
                try {
                    std::string wasFound = tree.Search(Helper::read<int>("Enter value to search for: ")) ? " " : " not ";
                    std::cout << ">> Value is" << wasFound << "in the tree." << std::endl;
                } catch (const char * e) {
                    Helper::print(e);
                }
                break;
                
            case 4:
                tree.PrintAscending();
                break;
                
            case 5:
                tree.PrintDescending();
                break;
                
            case 6:
                dummyHolder = tree.GetNodesHeight(Helper::read<int>(">> Enter the value of the node you want to know the height of: "));
                std::cout << "Node's height: " << dummyHolder << std::endl;
                break;
                
            case 7:
                dummyHolder = tree.GetNodesDepth(Helper::read<int>(">> Enter the value of the node you want to know the depth of: "));
                std::cout << "Node's depth: " << dummyHolder << std::endl;
                break;
            
            case 8:
                dummyHolder = tree.GetNodesLevel(Helper::read<int>(">> Enter the value of the node you want to know the level of: "));
                std::cout << "Node's level: " << dummyHolder << std::endl;
                break;
                
            case 9:
                std::string isLegal = tree.IsLegal() ? "Tree is legal." : "Tree is not legal.";
                Helper::print(isLegal);
                break;
        }
    }
}
