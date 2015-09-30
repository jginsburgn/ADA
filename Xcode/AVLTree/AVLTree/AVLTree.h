//
//  AVLTree.h
//  AVLTree
//
//  Created by Jonathan Ginsburg on 9/8/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef AVLTree_AVLTree_h
#define AVLTree_AVLTree_h

#include <vector>
#include "../../BinarySearchTree/BinarySearchTree/BinarySearchTree.h"

namespace jgn {
    template <class T>
    class AVLTree : public BinarySearchTree<T> {
    private:
        void RightRightCase(BinaryNode<T> * x, BinaryNode<T> * y, BinaryNode<T> * z);
        void RightLeftCase(BinaryNode<T> * x, BinaryNode<T> * y, BinaryNode<T> * z);
        void LeftLeftCase(BinaryNode<T> * x, BinaryNode<T> * y, BinaryNode<T> * z);
        void LeftRightCase(BinaryNode<T> * x, BinaryNode<T> * y, BinaryNode<T> * z);
        
    protected:
        void Rebalance(BinaryNode<T> * fromNode);
        
    public:
        AVLTree() {};
        ~AVLTree() {this->Clear();}
        void Insert(T);
        void Erase(T);
        bool Search(T);
        //void PrintAscending(); inherited
        //void PrintDescending(); inherited
        //int GetNodesHeight(T); inherited
        //int GetNodesDepth(T); inherited
        //int GetNodesLevel(T); inherited
        bool IsLegal() const;
        //void Clear(); inherited
    };
    
    template <class T>
    void AVLTree<T>::RightRightCase(BinaryNode<T> * x, BinaryNode<T> * y, BinaryNode<T> * z){
        //Rotate: see rightright.png
        
        if (!(x && y && z)) {
            return;
        }
        
        BinaryNode<T> * tmpLeftOfY = y->getLeft();
        
        //Update y
        y->setLeft(z);
        y->setParent(z->getParent());
        if (!z->getParent()) {
            this->root = y;
        }
        else {
            if (z->getParent()->getRight() == z) {
                z->getParent()->setRight(y);
            }
            else z->getParent()->setLeft(y);
        }
        
        //Update z
        z->setRight(tmpLeftOfY);
        if (tmpLeftOfY) tmpLeftOfY->setParent(z);
        z->setParent(y);
        
        
        //Update x
        
        //Update depths and heights
        y->setDepth(y->getDepth()-1);
        z->setDepth(z->getDepth()+1);
        BinarySearchTree<T>::IncreaseSuccessorsAndNodesDepth(z->getLeft());
        BinarySearchTree<T>::DecreaseSuccessorsAndNodesDepth(x);
        
        BinarySearchTree<T>::UpdateNodesHeight(z);
        BinarySearchTree<T>::UpdateAncestorsAndNodesHeight(x);
    }
    
    template <class T>
    void AVLTree<T>::RightLeftCase(BinaryNode<T> * x, BinaryNode<T> * y, BinaryNode<T> * z){
        //Rotate: see rightleft.png
        
        if (!(x && y && z)) {
            return;
        }
        
        BinaryNode<T> * tmpRightOfX = x->getRight();
        
        //Update x
        x->setRight(y);
        x->setParent(z);
        
        //Update y
        y->setLeft(tmpRightOfX);
        if (tmpRightOfX) tmpRightOfX->setParent(y);
        y->setParent(x);
        
        //Update z
        z->setRight(x);
        
        //Update depths and heights
        x->setDepth(x->getDepth()-1);
        y->setDepth(y->getDepth()+1);
        BinarySearchTree<T>::DecreaseSuccessorsAndNodesDepth(x->getLeft());
        BinarySearchTree<T>::IncreaseSuccessorsAndNodesDepth(y->getRight());
        
        BinarySearchTree<T>::UpdateAncestorsAndNodesHeight(y);
        
        //Reduce to LeftLeftCase
        RightRightCase(y, x, z);
    }
    
    template <class T>
    void AVLTree<T>::LeftLeftCase(BinaryNode<T> * x, BinaryNode<T> * y, BinaryNode<T> * z){
        //Rotate: see leftleft.png
        
        if (!(x && y && z)) {
            return;
        }
        
        BinaryNode<T> * tmpRightOfY = y->getRight();
        
        //Update y
        y->setRight(z);
        y->setParent(z->getParent());
        if (!z->getParent()) {
            this->root = y;
        }
        else {
            if (z->getParent()->getLeft() == z) {
                z->getParent()->setLeft(y);
            }
            else z->getParent()->setRight(y);
        }
        
        
        //Update z
        z->setLeft(tmpRightOfY);
        if (tmpRightOfY) tmpRightOfY->setParent(z);
        z->setParent(y);
        
        
        //Update x
        
        
        //Update depths and heights
        y->setDepth(y->getDepth()-1);
        z->setDepth(z->getDepth()+1);
        BinarySearchTree<T>::IncreaseSuccessorsAndNodesDepth(z->getRight());
        BinarySearchTree<T>::DecreaseSuccessorsAndNodesDepth(x);
        
        BinarySearchTree<T>::UpdateNodesHeight(x);
        BinarySearchTree<T>::UpdateAncestorsAndNodesHeight(z);
    }
    
    template <class T>
    void AVLTree<T>::LeftRightCase(BinaryNode<T> * x, BinaryNode<T> * y, BinaryNode<T> * z){
        //Rotate: see leftright.png
        
        if (!(x && y && z)) {
            return;
        }
        
        BinaryNode<T> * tmpLeftOfX = x->getLeft();
        
        //Update x
        x->setLeft(y);
        x->setParent(z);
        
        //Update y
        y->setRight(tmpLeftOfX);
        if (tmpLeftOfX) tmpLeftOfX->setParent(y);
        y->setParent(x);
        
        //Update z
        z->setLeft(x);
        
        //Update depths and heights
        x->setDepth(x->getDepth()-1);
        y->setDepth(y->getDepth()+1);
        BinarySearchTree<T>::DecreaseSuccessorsAndNodesDepth(x->getRight());
        BinarySearchTree<T>::IncreaseSuccessorsAndNodesDepth(y->getLeft());
        
        BinarySearchTree<T>::UpdateAncestorsAndNodesHeight(y);
        
        //Reduce to LeftLeftCase
        LeftLeftCase(y, x, z);
    }
    
    template <class T>
    void AVLTree<T>::Rebalance(BinaryNode<T> * fromNode){//fromNode will be called w
        if (fromNode) {
            BinaryNode<T> * parentOfZ = nullptr;
            BinaryNode<T> * unbalancedAncestor = fromNode;//Will be called z
            BinaryNode<T> * zsChild = nullptr; //Z's child in the path between z and fromNode, will be called y
            BinaryNode<T> * zsGrandChild = nullptr; //Z's grandchild the path between z and fromNode, will be called x
            //Find the first unbalanced ancestor
            int unbalancedAncestorsBalanceFactor = unbalancedAncestor->getBalanceFactor();
            bool isBalanceFactorInRange = (-1 <= unbalancedAncestorsBalanceFactor && unbalancedAncestorsBalanceFactor <= 1);
            while (isBalanceFactorInRange && unbalancedAncestor) {
                unbalancedAncestor = unbalancedAncestor->getParent();
                if (!unbalancedAncestor) break;
                unbalancedAncestorsBalanceFactor = unbalancedAncestor->getBalanceFactor();
                isBalanceFactorInRange = (-1 <= unbalancedAncestorsBalanceFactor && unbalancedAncestorsBalanceFactor <= 1);
            }
            if (unbalancedAncestor) { //Check if there is indeed an unbalanced ancestor
                parentOfZ = unbalancedAncestor->getParent();
                //Find y
                if (unbalancedAncestor->getBalanceFactor() < -1) { //Unbalanced ancestor leans to the left
                    zsChild = unbalancedAncestor->getLeft();
                }
                else {//Unbalanced ancestor leans to the right
                    zsChild = unbalancedAncestor->getRight();
                }
                //Find x
                BinaryNode<T> * leftOfY = zsChild->getLeft();
                //Check if y has left child
                if (leftOfY) {
                    BinaryNode<T> * tmp = fromNode; //Temporary pointer
                    bool isLeftOfYInPathFromWToY = false;
                    //We will walk the tree from W to Y and see if there is a node in the path such that it is equal to the left child of y
                    //If there is then x is leftOfY
                    while (tmp != zsChild && tmp) {
                        if (tmp == leftOfY) {//There is a node in the path from W to Y that matches the left son of Y
                            isLeftOfYInPathFromWToY = true; //Note the result
                            break; //Exit loop
                        }
                        else tmp = tmp->getParent(); //Move up in the path
                    }
                    if (isLeftOfYInPathFromWToY) { //Assign X accordingly
                        zsGrandChild = leftOfY;
                    }
                    else zsGrandChild = zsChild->getRight();
                    
                }
                //If there is no left child then X must be the right child
                else zsGrandChild = zsChild->getRight();
                
                //Make rotations as necessary
                //y is left child of z and x is left child of y (Left Left Case)
                if (unbalancedAncestor->getLeft() == zsChild && zsGrandChild == zsChild->getLeft()) {
                    LeftLeftCase(zsGrandChild, zsChild, unbalancedAncestor);
                }
                //y is left child of z and x is right child of y (Left Right Case)
                else if (unbalancedAncestor->getLeft() == zsChild && zsGrandChild == zsChild->getRight()){
                    LeftRightCase(zsGrandChild, zsChild, unbalancedAncestor);
                }
                //y is right child of z and x is right child of y (Right Right Case)
                else if (unbalancedAncestor->getRight() == zsChild && zsGrandChild == zsChild->getRight()){
                    RightRightCase(zsGrandChild, zsChild, unbalancedAncestor);
                }
                //y is right child of z and x is left child of y (Right Left Case)
                else{
                    RightLeftCase(zsGrandChild, zsChild, unbalancedAncestor);
                }
                //Keep tracing back for needed rebalance
                Rebalance(parentOfZ);
            }
            else return; //If there are no unbalanced ancestors
        }
    }
    
    template <class T>
    void AVLTree<T>::Insert(T newData){
        try {
            BinarySearchTree<T>::Insert(newData);
            Rebalance(BinarySearchTree<T>::Search(newData));
        } catch (const char * exception) {
            throw exception;
        }
    }
    
    template <class T>
    void AVLTree<T>::Erase(T info){
        try {
            if (!(this->root)) {
                throw "Tree is empty.";
            }
            BinarySearchTree<T>::Erase(info);
            Rebalance(BinarySearchTree<T>::Search(info));
        } catch (const char * exception) {
            throw exception;
        }
    }

    template <class T>
    bool AVLTree<T>::Search(T value){
        return BinarySearchTree<T>::Search(value);
    }
    
    template <class T>
    bool AVLTree<T>::IsLegal() const {
        bool retVal = true;
        return retVal;
    }
}

#endif
