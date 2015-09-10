
#ifndef __BinaryTreeRB_Node
#define __BinaryTreeRB_Node

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node{
    
    T info;
    Node *parent;
    Node *left;
    Node *right;
    string color;
    
public:
    
    Node();
    
    Node(T e, Node *p, Node *dir);
    
    Node<T>* grandparent();
    
    Node<T>* uncle();
    
    void setInfo(T value);
    T getInfo();
    
    void setLeft(Node<T> *value);
    Node<T> *getLeft();
    
    void setRight(Node<T> *value);
    Node<T> *getRight();
    
    void setParent(Node<T> *value);
    Node<T> *getParent();
    
    void setColor(string c);
    string getColor();
    
};

template <class T>
Node<T>::Node(){
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

template <class T>
Node<T>::Node(T e, Node *p, Node *dir){
    info = e;
    parent = p;
    left = dir;
    right = dir;
    color = "rojo";
}

template <class T>
Node<T>* Node<T>::grandparent(){
    if ((this != nullptr) && (this->parent != nullptr)){
        return this->getParent()->getParent();
    }else{
        return nullptr;
    }
}

template <class T>
Node<T>* Node<T>::uncle(){
    if ((this != nullptr) && (this->parent != nullptr)){
        return this->getParent()->getParent();
    }else{
        return nullptr;
    }
}

template <class T>
void Node<T>::setInfo(T value){
    info = value;
}

template <class T>
T Node<T>::getInfo(){
    return info;
}

template <class T>
void Node<T>::setParent(Node<T> *value){
    parent = value;
}

template <class T>
Node<T>* Node<T>::getParent(){
    return parent;
}

template <class T>
void Node<T>::setLeft(Node<T> *value){
    left = value;
}

template <class T>
Node<T>* Node<T>::getLeft(){
    return left;
}

template <class T>
void Node<T>::setRight(Node<T> *value){
    right = value;
}

template <class T>
Node<T>* Node<T>::getRight(){
    return right;
}

template <class T>
void Node<T>::setColor(string c){
    color = c;
}

template <class T>
string Node<T>::getColor(){
    return color;
}



#endif
