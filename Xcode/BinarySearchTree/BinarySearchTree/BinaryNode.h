//
//  BinaryNode.h
//  BinaryTree
//
//  Created by Vicente Cubells Nonell on 26/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef BinaryTree_BinaryNode_h
#define BinaryTree_BinaryNode_h

#pragma GCC diagnostic ignored "-Wtautological-undefined-compare"

#include <iostream>

namespace jgn {
    
    template <class T>
    class BinaryNode {
        
    protected:
        BinaryNode<T> * parent = nullptr;
        BinaryNode<T> * left = nullptr;
        BinaryNode<T> * right = nullptr;
        
        int height = 0;
        int depth = 0;
        
        T info;
        
    public:
        
        /* Constructores */
        BinaryNode() { }
        BinaryNode(const T & _info) : info (_info) { }
        BinaryNode(const BinaryNode<T> & );
        
        /* Destructor */
        virtual ~BinaryNode();
        
        T getInfo() const { return info; }
        void setInfo(const T & value) { info = value; }
        
        BinaryNode<T> * getLeft() const { return left; }
        void setLeft(BinaryNode<T> * value) { left = value; }
        
        BinaryNode<T> * getRight() const { return right; }
        void setRight(BinaryNode<T> * value) { right = value; }
        
        BinaryNode<T> * getParent() const { return parent; }
        void setParent(BinaryNode<T> * value) { parent = value; }
        
        int getHeight() const {return height;};
        void setHeight(int newHeight) {height = newHeight;};
        
        int getDepth() const {return depth;};
        void setDepth(int newDepth) {depth = newDepth;};
        
        int getBalanceFactor() const;
        
        template <typename Tn>
        friend std::ostream & operator << (std::ostream & os, const BinaryNode<Tn>  & node);
    };
    
    template <class T>
    BinaryNode<T>::BinaryNode(const BinaryNode<T> & other)
    {
        if (!this) throw "Node is uninitialized.";
        info = other.info;
        left = other.left;
        right = other.right;
        parent = other.parent;
    }
    
    template <class T>
    BinaryNode<T>::~BinaryNode()
    {
        info.~T();
        left = right = parent = nullptr;
    }
    
    template <class T>
    int BinaryNode<T>::getBalanceFactor() const{
        if (left && right) {
            return right->getHeight() - left->getHeight();
        }
        else if (left && !right){
            return - left->getHeight() - 1;
        }
        else if (!left && right){
            return right->getHeight() + 1
            ;
        }
        else{
            return 0;
        }
    }
    
    template <class T>
    std::ostream & operator << (std::ostream & os, const BinaryNode<T>  & node)
    {
        os << node.info;
        return os;
    }
    
}



#endif
