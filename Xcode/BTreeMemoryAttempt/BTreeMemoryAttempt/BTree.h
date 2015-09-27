//
//  BTree.h
//  BTreeMemoryAttempt
//
//  Created by Jonathan Ginsburg on 9/11/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef BTreeMemoryAttempt_BTree_h
#define BTreeMemoryAttempt_BTree_h

#include "BNode.h"

template <class T>
class BTree {

private:
    int order;
    BNode<T> * root = nullptr;

public:
    BTree<T>(int newOrder){ order = newOrder; }

    void Insert(T newValue);
    void Erase(T value);
    void PrintAscending();
    bool IsEmpty();
};

template <class T>
void BTree<T>::Insert(T newValue){
    if (root) {
        std::vector<void *> * obtainedResults = new std::vector<void *>();
        root->Insert(newValue, obtainedResults);
        if ((*obtainedResults).size() == 0) {
            return;
        }
        int * childSplitted = (int *)(*obtainedResults)[0];
        if (*childSplitted) { //Child splitted
            BNode<T> * newRoot = new BNode<T>(order);
            int * returnedMedian = (int *)(*obtainedResults)[2];
            std::vector<void *> * dummyHolder = new std::vector<void *>();
            newRoot->Insert(*returnedMedian, dummyHolder);
            newRoot->children[0] = root;
            newRoot->children[1] = (BNode<T> *)(*obtainedResults)[1];
            root = newRoot;
        }
    }
    else {
        root = new BNode<T>(order);
        std::vector<void *> * dummyHolder = new std::vector<void *>();
        root->Insert(newValue, dummyHolder);
    }
}

template <class T>
void BTree<T>::Erase(T value){
    if (root) {
        bool underflowOcurred = false;
        root->Erase(value, underflowOcurred);
        if (underflowOcurred) {
            if (root->values.size() == 0) {
                BNode<T> * tmp = root->children[0];
                root->children[0] = nullptr;
                root = tmp;
            }
        }
    }
}

template <class T>
void BTree<T>::PrintAscending() {
    if (root) {
        root->Print();
    }
}

template <class T>
bool BTree<T>::IsEmpty() {
    return root == nullptr;
}

#endif
