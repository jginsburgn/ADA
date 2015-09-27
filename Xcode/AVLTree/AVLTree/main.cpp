//
//  main.cpp
//  AVLTree
//
//  Created by Jonathan Ginsburg on 9/8/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "AVLTree.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main(int argc, const char * argv[]) {
    srand ((unsigned int)time(NULL));
    jgn::AVLTree<int> tree;
    for (int i = 0; i < 40; ++i) {
        try {
            tree.Insert(rand() % 100 + 1);
        } catch (const char * e) {
            std::cout << e << std::endl;
        }
    }
    tree.PrintAscending();
    return 0;
}
