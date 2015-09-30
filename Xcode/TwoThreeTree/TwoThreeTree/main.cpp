//
//  main.cpp
//  TwoThreeTree
//
//  Created by Jonathan Ginsburg on 9/30/15.
//  Copyright © 2015 Jonathan Ginsburg. All rights reserved.
//  2-3 Tree codes from Alberto Pickering

#include <iostream>
#include "TwoThreeTree.h"
#include "../../Helper.h"

int main(int argc, const char * argv[]) {
    TwoThreeTree<int> tree;
    Helper::print("Welcome to the int 2-3 Tree tester. Jonathan Ginsburg (C) September 2015.");
    while (true) {
        Helper::print("\t1 for inserting in tree.");
        Helper::print("\t2 for deleting from tree.");
        Helper::print("\t3 for searching in tree.");
        Helper::print("\t4 for printing tree in ascending order.");
        Helper::print("\t5 for printing tree in descending order.");
        //        Helper::print("\t6 for verifying legality of tree according to AVL rules.");
        Helper::print("\t0 for terminating program.");
        int input = Helper::read<int>(">> Enter your choice: ");
        switch (input) {
            case 0:
                return 0;
                break;
                
            case 1:
                try {
                    tree.insert(Helper::read<int>(">> Enter value to insert: "));
                } catch (const char * e) {
                    Helper::print(e);
                }
                break;
                
            case 2:
                try {
                    tree.remove(Helper::read<int>(">> Enter value to erase: "));
                } catch (const char * e) {
                    Helper::print(e);
                }
                break;
                
            case 3:
                try {
                    std::string wasFound = tree.search(Helper::read<int>("Enter value to search for: ")) ? " " : " not ";
                    std::cout << ">> Value is" << wasFound << "in the tree." << std::endl;
                } catch (const char * e) {
                    Helper::print(e);
                }
                break;
                
            case 4:
                tree.inOrder();
                break;
                
            case 5:
                tree.postOrder();
                break;
                
                //            case 6:
                //                std::string isLegal = tree.IsLegal() ? "Tree is legal." : "Tree is not legal.";
                //                Helper::print(isLegal);
                //                break;
        }
    }
}
