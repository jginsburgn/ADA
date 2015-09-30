//
//  BinarySearchTree.h
//  BinarySearchTree
//
//  Created by Jonathan Ginsburg on 9/7/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef BinarySearchTree_BinarySearchTree_h
#define BinarySearchTree_BinarySearchTree_h

#include <vector>
#include "BinaryNode.h"

namespace jgn {
    template <class T>
    class BinarySearchTree {
        
    protected:
        BinaryNode<T> * root = nullptr;
        void PreOrder(BinaryNode<T> *, void (*)(BinaryNode<T> *, std::vector<void *> *), std::vector<void *> *);
        void InOrder(BinaryNode<T> *, void (*)(BinaryNode<T> *, std::vector<void *> *), std::vector<void *> *);
        void ReversedInOrder(BinaryNode<T> *, void (*)(BinaryNode<T> *, std::vector<void *> *), std::vector<void *> *);
        void PostOrder(BinaryNode<T> *, void (*)(BinaryNode<T> *, std::vector<void *> *), std::vector<void *> *);
        
        void OrderlyInsert(T);
        void UpdateAncestorsHeight(BinaryNode<T> *);
        void UpdateAncestorsAndNodesHeight(BinaryNode<T> *);
        void UpdateNodesHeight(BinaryNode<T> *);
        void DecreaseSuccessorsAndNodesDepth(BinaryNode<T> *);
        void IncreaseSuccessorsAndNodesDepth(BinaryNode<T> *);
        BinaryNode<T> * RecursiveBinarySearch(BinaryNode<T> *, T);
        
    public:
        
        BinarySearchTree() {};
        ~BinarySearchTree() {this->Clear();}
        BinaryNode<T> * Search(T);
        virtual void Insert(T);
        virtual void Erase(T);
        void PrintAscending();
        void PrintDescending();
        int GetNodesHeight(T);
        int GetNodesDepth(T);
        int GetNodesLevel(T);
        void Clear();
        
    };
    
    template <class T>
    void BinarySearchTree<T>::PreOrder(BinaryNode<T> * currentNode, void (*action)(BinaryNode<T> *, std::vector<void *> *), std::vector<void *> * args){
        if (currentNode) {
            action(currentNode, args);
            PreOrder(currentNode->getLeft(), action, args);
            PreOrder(currentNode->getRight(), action, args);
        }
    }
    
    template <class T>
    void BinarySearchTree<T>::InOrder(BinaryNode<T> * currentNode, void (*action)(BinaryNode<T> *, std::vector<void *> *), std::vector<void *> * args){
        if (currentNode) {
            InOrder(currentNode->getLeft(), action, args);
            action(currentNode, args);
            InOrder(currentNode->getRight(), action, args);
        }
    }
    
    template <class T>
    void BinarySearchTree<T>::ReversedInOrder(BinaryNode<T> * currentNode, void (*action)(BinaryNode<T> *, std::vector<void *> *), std::vector<void *> * args){
        if (currentNode) {
            ReversedInOrder(currentNode->getRight(), action, args);
            action(currentNode, args);
            ReversedInOrder(currentNode->getLeft(), action, args);
        }
    }
    
    template <class T>
    void BinarySearchTree<T>::PostOrder(BinaryNode<T> * currentNode, void (*action)(BinaryNode<T> *, std::vector<void *> *), std::vector<void *> * args){
        if (currentNode) {
            PostOrder(currentNode->getLeft(), action, args);
            PostOrder(currentNode->getRight(), action, args);
            action(currentNode, args);
        }
    }
    
    template <class T>
    void BinarySearchTree<T>::OrderlyInsert(T newData){
        BinaryNode<T> * current = root;
        int depth = 0;
        while (true) {
            current->setHeight(current->getHeight() + 1);
            depth++;
            if (newData < current->getInfo()) {
                if (current->getLeft()) {
                    current = current->getLeft();
                    continue;
                }
                else {
                    BinaryNode<T> * newNode = new BinaryNode<T>(newData);
                    newNode->setParent(current);
                    newNode->setDepth(depth);
                    current->setLeft(newNode);
                    break;
                }
            }
            else {
                if (current->getRight()) {
                    current = current->getRight();
                    continue;
                }
                else {
                    BinaryNode<T> * newNode = new BinaryNode<T>(newData);
                    newNode->setParent(current);
                    newNode->setDepth(depth);
                    current->setRight(newNode);
                    break;
                }
            }
        }
    }
    
    template <class T>
    void BinarySearchTree<T>::UpdateAncestorsHeight(BinaryNode<T> * node){
        //Takes a modified node (in its height property) and updates all ancestors of it (in their height property) to root
        BinaryNode<T> * current = node;
        while (current->getParent()) {
            BinaryNode<T> * parent = current->getParent();
            if (parent->getLeft() && parent->getRight()) {
                //If parent has both children check which one is higher and update accordingly
                //Note that the parent must at least have one child
                if (parent->getLeft()->getHeight() < parent->getRight()->getHeight()) {
                    parent->setHeight(parent->getRight()->getHeight() + 1);
                }
                else parent->setHeight(parent->getLeft()->getHeight() + 1);
            }
            else {//When parent has one child update its height accordingly
                parent->setHeight(current->getHeight() + 1);
            }
            current = current->getParent();
        }
    }
    
    template <class T>
    void BinarySearchTree<T>::UpdateAncestorsAndNodesHeight(BinaryNode<T> * node){
        //Takes a node and updates its height and all of its ancestors' height to root
        if (node) {
            UpdateNodesHeight(node);
            UpdateAncestorsHeight(node);
        }
    }
    
    template <class T>
    void BinarySearchTree<T>::UpdateNodesHeight(BinaryNode<T> * node){
        //Takes a node and updates its height
        if (node) {
            if (node->getLeft() && node->getRight()) {
                if (node->getLeft()->getHeight() < node->getRight()->getHeight()) {
                    node->setHeight(node->getRight()->getHeight() + 1);
                }
                else node->setHeight(node->getLeft()->getHeight() + 1);
            }
            else if (node->getLeft()){
                node->setHeight(node->getLeft()->getHeight() + 1);
            }
            else if (node->getRight()){
                node->setHeight(node->getRight()->getHeight() + 1);
            }
            else node->setHeight(0);
        }
    }
    
    template <class T>
    void BinarySearchTree<T>::DecreaseSuccessorsAndNodesDepth(BinaryNode<T> * node){
        //Takes a node and decreases its depth and that of its descendants
        if (node) {
            node->setDepth(node->getDepth() - 1);
            DecreaseSuccessorsAndNodesDepth(node->getLeft());
            DecreaseSuccessorsAndNodesDepth(node->getRight());
        }
    }
    
    template <class T>
    void BinarySearchTree<T>::IncreaseSuccessorsAndNodesDepth(BinaryNode<T> * node){
        //Takes a node and increases its depth and that of its descendants
        if (node) {
            node->setDepth(node->getDepth() + 1);
            IncreaseSuccessorsAndNodesDepth(node->getLeft());
            IncreaseSuccessorsAndNodesDepth(node->getRight());
        }
    }
    
    template <class T>
    BinaryNode<T> * BinarySearchTree<T>::RecursiveBinarySearch(BinaryNode<T> * node, T value){
        if (node) {
            if (node->getInfo() == value) {
                return node;
            }
            else if (value < node->getInfo()){
                return BinarySearchTree<T>::RecursiveBinarySearch(node->getLeft(), value);
            }
            else return BinarySearchTree<T>::RecursiveBinarySearch(node->getRight(), value);
        }
        return nullptr;
    }
    
    template <class T>
    BinaryNode<T> * BinarySearchTree<T>::Search(T value){
        return BinarySearchTree<T>::RecursiveBinarySearch(root, value);
    }
    
    template <class T>
    void BinarySearchTree<T>::Insert(T newData){
        if (!BinarySearchTree::Search(newData)) {
            if (!root) {
                root = new BinaryNode<T>(newData);
                root->setHeight(0);
                root->setDepth(0);
            }
            else OrderlyInsert(newData);
        }
        else throw "Node to insert is already in the tree.";
    }
    
    template <class T>
    void BinarySearchTree<T>::Erase(T info){
        BinaryNode<T> * node = BinarySearchTree<T>::Search(info); //Look for node with info
        if (node) { //If node exists in tree
            if (!node->getLeft() && !node->getRight()) { //If node has no children
                BinaryNode<T> * parent = node->getParent();
                if (parent) { //If node has parent
                    if (parent->getLeft() == node) { //if node is left child
                        //Update parent's height to match that of his right son plus one or zero if there is no right son
                        if (parent->getRight()) {
                            parent->setHeight(parent->getRight()->getHeight() + 1);
                        }
                        else parent->setHeight(0);
                        //Also update all other ancestors' height
                        UpdateAncestorsHeight(parent);
                        //Disconnect parent from node
                        parent->setLeft(nullptr);
                    }
                    else {
                        //Update parent's height to match that of his left son plus one or zero if there is no left son
                        if (parent->getLeft()) {
                            parent->setHeight(parent->getLeft()->getHeight() + 1);
                        }
                        else parent->setHeight(0);
                        //Also update all other ancestors' height
                        UpdateAncestorsHeight(parent);
                        //Disconnect parent from node
                        parent->setRight(nullptr);
                    }
                }
                //if node has no parent and no children
                else root = nullptr;
                delete node;
            }
            else if (!node->getLeft() && node->getRight()){ //If node only has right child
                BinaryNode<T> * right = node->getRight();
                //Update right child's depth
                DecreaseSuccessorsAndNodesDepth(right);
                BinaryNode<T> * parent = node->getParent();
                if (parent) { //If node has parent
                    if (parent->getLeft() == node) { //If node is left child
                        //Update parent's height
                        if (parent->getRight()) { //Check for the existance of parent's right child
                            //Check if new parent's left child is higher than his right child and update parent's height accordingly
                            if (parent->getRight()->getHeight() < right->getHeight()) {
                                parent->setHeight(right->getHeight() + 1);
                            }
                            else parent->setHeight(parent->getRight()->getHeight() + 1);
                        }
                        //In case of no parent's right child update parent's height with new parent's left child
                        else parent->setHeight(right->getHeight() + 1);
                        //Also update all other ancestors
                        UpdateAncestorsHeight(parent);
                        //Connect parent to new left child
                        parent->setLeft(right);
                    }
                    else { //If node is right child
                        //Update parent's height
                        if (parent->getLeft()) { //Check for the existance of parent's left child
                            //Check if new parent's right child is higher than his left child and update parent's height accordingly
                            if (parent->getLeft()->getHeight() < right->getHeight()) {
                                parent->setHeight(right->getHeight() + 1);
                            }
                            else parent->setHeight(parent->getLeft()->getHeight() + 1);
                        }
                        //In case of no parent's left child update parent's height with new parent's right child
                        else parent->setHeight(right->getHeight() + 1);
                        //Also update all other ancestors
                        UpdateAncestorsHeight(parent);
                        //Connect parent to new right child
                        parent->setRight(right);
                    }
                    //Connect right to new parent
                    right->setParent(parent);
                    //Disconnect node from parent
                    node->setParent(nullptr);
                }
                //Disconnect node from right child
                node->setRight(nullptr);
                delete node;
            }
            else if (node->getLeft() && !node->getRight()){ //If node has only left child
                BinaryNode<T> * left = node->getLeft();
                //Update left child's depth
                DecreaseSuccessorsAndNodesDepth(left);
                BinaryNode<T> * parent = node->getParent();
                if (parent) { //If node has parent
                    if (parent->getLeft() == node) { //If node is left child
                        //Update parent's height
                        if (parent->getRight()) { //Check for the existance of parent's right child
                            //Check if new parent's left child is higher than his right child and update parent's height accordingly
                            if (parent->getRight()->getHeight() < left->getHeight()) {
                                parent->setHeight(left->getHeight() + 1);
                            }
                            else parent->setHeight(parent->getRight()->getHeight() + 1);
                        }
                        //In case of no parent's right child update parent's height with new parent's left child
                        else parent->setHeight(left->getHeight() + 1);
                        //Also update all other ancestors
                        UpdateAncestorsHeight(parent);
                        //Connect parent to new left child
                        parent->setLeft(left);
                    }
                    else { //If node is right child
                        //Update parent's height
                        if (parent->getLeft()) { //Check for the existance of parent's left child
                            //Check if new parent's right child is higher than his left child and update parent's height accordingly
                            if (parent->getLeft()->getHeight() < left->getHeight()) {
                                parent->setHeight(left->getHeight() + 1);
                            }
                            else parent->setHeight(parent->getLeft()->getHeight() + 1);
                        }
                        //In case of no parent's left child update parent's height with new parent's right child
                        else parent->setHeight(left->getHeight() + 1);
                        //Also update all other ancestors
                        UpdateAncestorsHeight(parent);
                        //Connect parent to new right child
                        parent->setRight(left);
                    }
                    //Connect left to new parent
                    left->setParent(parent);
                    //Disconnect node from parent
                    node->setParent(nullptr);
                }
                //Disconnect node from right child
                node->setRight(nullptr);
                delete node;
            }
            else { //If node has both children

                BinaryNode<T> * parent = node->getParent();
                if (parent) { //If node has parent
                    if (parent->getLeft() == node) { //If node is left child
                        
                        //Update right children's depth
                        DecreaseSuccessorsAndNodesDepth(node->getRight());
                        
                        BinaryNode<T> * parentPredecessor = node->getRight(); //Get parent's predecessor
                        while (parentPredecessor->getLeft()) {
                            parentPredecessor = parentPredecessor->getLeft();
                        }
                        
                        //Update parentPredecessor's parent's height
                        //If parentPredecessor's parent has both children
                        //Note that if parentPredecessor's parent has left child then it has both children
                        if (parentPredecessor->getParent()->getLeft()) {
                            //Check if parentPredecessor's parent's left child is lower than parentPredecessor and update heights
                            if (parentPredecessor->getParent()->getLeft()->getHeight() < parentPredecessor->getHeight()) {
                                parentPredecessor->getParent()->setHeight(parentPredecessor->getHeight() + 1);
                            }
                            else parentPredecessor->getParent()->setHeight(parentPredecessor->getParent()->getLeft()->getHeight() + 1);
                        }
                        //Note that parentPredecessor must have at least one child
                        else {//If parentPredecessor's parent only has one child
                            parentPredecessor->getParent()->setHeight(parentPredecessor->getHeight() + 1);
                        }
                        //Also update all other ancestors' height
                        UpdateAncestorsHeight(parentPredecessor->getParent());
                        
                        //Substitute current node's info with parent's predecessor and erase predecessor
                        node->setInfo(parentPredecessor->getInfo());
                        if (parentPredecessor->getParent()->getLeft() == parentPredecessor) {
                            parentPredecessor->getParent()->setLeft(parentPredecessor->getLeft());
                        }
                        else parentPredecessor->getParent()->setRight(parentPredecessor->getRight());
                        parentPredecessor->setParent(nullptr);
                        delete parentPredecessor;
                    }
                    else {
                        //Update left children's depth
                        DecreaseSuccessorsAndNodesDepth(node->getLeft());
                        
                        BinaryNode<T> * parentSuccessor = node->getLeft();
                        while (parentSuccessor->getRight()) { //Get parent sucessor
                            parentSuccessor = parentSuccessor->getRight();
                        }
                        
                        //Update parentSuccessor's parent's height
                        //If parentSuccessor's parent has both children
                        //Note that if parentSuccessor's parent has left child then it has both children
                        if (parentSuccessor->getParent()->getLeft()) {
                            //Check if parentSuccessor's parent's left child is lower than parentSuccessor and update heights
                            if (parentSuccessor->getParent()->getLeft()->getHeight() < parentSuccessor->getHeight()) {
                                parentSuccessor->getParent()->setHeight(parentSuccessor->getHeight() + 1);
                            }
                            else parentSuccessor->getParent()->setHeight(parentSuccessor->getParent()->getLeft()->getHeight() + 1);
                        }
                        //Note that parentSuccessor must have at least one child
                        else {//If parentSuccessor parent only has one child
                            parentSuccessor->getParent()->setHeight(parentSuccessor->getHeight() + 1);
                        }
                        //Also update all other ancestors' height
                        UpdateAncestorsHeight(parentSuccessor->getParent());
                        
                        //Substitute current node's info with parents successor and erase successor
                        node->setInfo(parentSuccessor->getInfo());
                        if (parentSuccessor->getParent()->getLeft() == parentSuccessor) {
                            parentSuccessor->getParent()->setLeft(parentSuccessor->getLeft());
                        }
                        else parentSuccessor->getParent()->setRight(parentSuccessor->getRight());
                        parentSuccessor->setParent(nullptr);
                        delete parentSuccessor;
                    }
                }
                else { //If node has no parent
                    //Update right children's depth
                    DecreaseSuccessorsAndNodesDepth(node->getLeft());
                    
                    BinaryNode<T> * nodesPredecessor = node->getLeft(); //Get node's predecessor
                    while (nodesPredecessor->getRight()) {
                        nodesPredecessor = nodesPredecessor->getRight();
                    }
                    
                    //Update nodesPredecessor's parent's height
                    //If nodesPredecessor's parent has both children
                    //Note that if nodesPredecessor's parent has left child then it has both children
                    if (nodesPredecessor->getParent()->getLeft()) {
                        //Check if nodesPredecessor's parent's left child is lower than nodesPredecessor and update heights
                        if (nodesPredecessor->getParent()->getLeft()->getHeight() < nodesPredecessor->getHeight()) {
                            nodesPredecessor->getParent()->setHeight(nodesPredecessor->getHeight() + 1);
                        }
                        else nodesPredecessor->getParent()->setHeight(nodesPredecessor->getParent()->getLeft()->getHeight() + 1);
                    }
                    //Note that nodesPredecessor must have at least one child
                    else {//If nodesPredecessor's parent only has one child
                        nodesPredecessor->getParent()->setHeight(nodesPredecessor->getHeight() + 1);
                    }
                    //Also update all other ancestors' height
                    UpdateAncestorsHeight(nodesPredecessor->getParent());
                    
                    //Substitute nodes info with nodes predecessor and erase predecessor
                    node->setInfo(nodesPredecessor->getInfo());
                    if (nodesPredecessor->getParent()->getLeft() == nodesPredecessor) {
                        nodesPredecessor->getParent()->setLeft(nullptr);
                    }
                    else nodesPredecessor->getParent()->setRight(nullptr);
                    nodesPredecessor->setParent(nullptr);
                    delete nodesPredecessor;
                }
            }
        }
        else throw "Node to delete is not in the tree.";
    }
    
    template <class T>
    void BinarySearchTree<T>::PrintAscending(){
        InOrder(root, [](BinaryNode<T> * currentNode, std::vector<void *> *){
            std::cout << *currentNode << std::endl;
        }, nullptr);
    }
    
    template <class T>
    void BinarySearchTree<T>::PrintDescending(){
        ReversedInOrder(root, [](BinaryNode<T> * currentNode, std::vector<void *> *){
            std::cout << *currentNode << std::endl;
        }, nullptr);
    }
    
    template <class T>
    int BinarySearchTree<T>::GetNodesHeight(T value){
        try {
            BinaryNode<T> * node = BinarySearchTree<T>::Search(value);
            if (node) return node->getHeight();
            else throw "Node not found.";
        } catch (const char * exception) {
            std::string newException;
            newException = "Node to get height from caused an exception: ";
            newException.append(exception);
            throw newException.c_str();
        }
    }
    
    template <class T>
    int BinarySearchTree<T>::GetNodesDepth(T value){
        try {
            BinaryNode<T> * node = BinarySearchTree<T>::Search(value);
            if (node) return node->getDepth();
            else throw "Node not found.";
        } catch (const char * exception) {
            std::string newException;
            newException = "Node to get depth from caused an exception: ";
            newException.append(exception);
            throw newException.c_str();
        }
    }
    
    template <class T>
    int BinarySearchTree<T>::GetNodesLevel(T value){
        try {
            BinaryNode<T> * node = BinarySearchTree<T>::Search(value);
            if (node) return node->getDepth() + 1;
            else throw "Node not found.";
        } catch (const char * exception) {
            std::string newException;
            newException = "Node to get level from caused an exception: ";
            newException.append(exception);
            throw newException.c_str();
        }
    }
    
    template <class T>
    void BinarySearchTree<T>::Clear(){
        if (root) {
            PostOrder(root, [](BinaryNode<T> * currentNode, std::vector<void *> *){
                delete currentNode;
            }, nullptr);
            root = nullptr;
        }
    }
}

#endif
