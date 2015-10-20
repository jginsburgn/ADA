
#ifndef __BinaryTreeRB_RBNode
#define __BinaryTreeRB_RBNode

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class RBNode{
    
    T info;
    RBNode *parent;
    RBNode *left;
    RBNode *right;
    string color;
    
public:
    
    RBNode();
    
    RBNode(T e, RBNode *p, RBNode *dir);
    
    RBNode<T>* grandparent();
    
    RBNode<T>* uncle();
    
    void setInfo(T value);
    T getInfo();
    
    void setLeft(RBNode<T> *value);
    RBNode<T> *getLeft();
    
    void setRight(RBNode<T> *value);
    RBNode<T> *getRight();
    
    void setParent(RBNode<T> *value);
    RBNode<T> *getParent();
    
    void setColor(string c);
    string getColor();
    
};

template <class T>
RBNode<T>::RBNode(){
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

template <class T>
RBNode<T>::RBNode(T e, RBNode *p, RBNode *dir){
    info = e;
    parent = p;
    left = dir;
    right = dir;
    color = "rojo";
}

template <class T>
RBNode<T>* RBNode<T>::grandparent(){
    if ((this != nullptr) && (this->parent != nullptr)){
        return this->getParent()->getParent();
    }else{
        return nullptr;
    }
}

template <class T>
RBNode<T>* RBNode<T>::uncle(){
    if ((this != nullptr) && (this->parent != nullptr)){
        return this->getParent()->getParent();
    }else{
        return nullptr;
    }
}

template <class T>
void RBNode<T>::setInfo(T value){
    info = value;
}

template <class T>
T RBNode<T>::getInfo(){
    return info;
}

template <class T>
void RBNode<T>::setParent(RBNode<T> *value){
    parent = value;
}

template <class T>
RBNode<T>* RBNode<T>::getParent(){
    return parent;
}

template <class T>
void RBNode<T>::setLeft(RBNode<T> *value){
    left = value;
}

template <class T>
RBNode<T>* RBNode<T>::getLeft(){
    return left;
}

template <class T>
void RBNode<T>::setRight(RBNode<T> *value){
    right = value;
}

template <class T>
RBNode<T>* RBNode<T>::getRight(){
    return right;
}

template <class T>
void RBNode<T>::setColor(string c){
    color = c;
}

template <class T>
string RBNode<T>::getColor(){
    return color;
}



#endif
