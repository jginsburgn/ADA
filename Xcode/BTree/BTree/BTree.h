//
//  BTree.h
//  BTree
//
//  Created by Jonathan Ginsburg on 9/9/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
// Code fetched from: http://www.geeksforgeeks.org/b-tree-set-1-introduction-2/

#ifndef BTree_BTree_h
#define BTree_BTree_h

#include "BTreeNode.h"

// A BTree

template <class T>
class BTree {
    
private:
    
    BTreeNode<T> * root; // Pointer to root node
    int t;  // Minimum degree
    
public:
    
    // Constructor (Initializes tree as empty)
    BTree<T>(int _t) {
        root = nullptr;  t = _t;
    }
    
    // function to traverse the tree
    void traverse() {
        if (root) root->traverse();
    }
    
    // function to search a key in this tree
    BTreeNode<T> * search(T k) {
        return (!root) ? nullptr : root->search(k);
    }
    
    // The main function that inserts a new key in this B-Tree
    void insert(T k);
    
};


template <class T>
// The main function that inserts a new key in this B-Tree
void BTree<T>::insert(T k) {
    // If tree is empty
    if (!root) {
        // Allocate memory for root
        root = new BTreeNode<T>(t, true);
        root->keys[0] = k;  // Insert key
        root->n = 1;  // Update number of keys in root
    }
    // If tree is not empty
    else {
        // If root is full, then tree grows in height
        if (root->n == 2*t-1) {
            
            // Allocate memory for new root
            BTreeNode<T> * s = new BTreeNode<T>(t, false);
            
            // Make old root as child of new root
            s->C[0] = root;
            
            // Split the old root and move 1 key to the new root
            s->splitChild(0, root);
            
            // New root has two children now.  Decide which of the
            // two children is going to have new key
            int i = 0;
            
            if (s->keys[0] < k) i++;
            s->C[i]->insertNonFull(k);
            
            // Change root
            root = s;
        }
        // If root is not full, call insertNonFull for root
        else root->insertNonFull(k);
    }
}


#endif
