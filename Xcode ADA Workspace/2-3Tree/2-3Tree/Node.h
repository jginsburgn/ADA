#ifndef __BinaryTree23_Node__
#define __BinaryTree23_Node__

#include <iostream>

using namespace std;

template <class T>
class Node{
    
    T infoA;
    T infoB;
	bool isEmpty;
    
    Node<T> *left;
    Node<T> *right;
    Node<T> *center;
    Node<T> *parent;
    
public:
    
    Node();
    Node(T value);
    
    bool isFull;
    bool isLeaf();
    
    void setInfoA(T value);
    T getInfoA();
    
    void setInfoB(T value);
    T getInfoB();
    
    T getInfoS();
    
    void setLeft(Node<T> *value);
    Node<T> *getLeft();
    
    void setRight(Node<T> *value);
    Node<T> *getRight();
    
    void setCenter(Node<T> *value);
    Node<T> *getCenter();
    
    void setParent(Node<T> *value);
    Node<T> *getParent();
    
    void setIsFull(bool value);
    bool getIsFull();

	void setIsEmpty(bool value);
    bool getIsEmpty();    
};

template <class T>
Node<T>::Node(){
    
    left = nullptr;
    right = nullptr;
    center = nullptr;
    parent = nullptr;
    
    isFull = false;
	isEmpty = false;
}

template <class T>
Node<T>::Node(T value){
    
    infoA = value;
    
    left = nullptr;
    right = nullptr;
    center = nullptr;
    parent = nullptr;
    
    isFull = false;
	isEmpty = false;
}

template <class T>
bool Node<T>::isLeaf(){
    return left == nullptr && right == nullptr && center ==nullptr;
}

template <class T>
void Node<T>::setInfoA(T value){
    infoA = value;
}

template <class T>
T Node<T>::getInfoA(){
    return infoA;
}

template <class T>
void Node<T>::setInfoB(T value){
    infoB = value;
}

template <class T>
T Node<T>::getInfoB(){
    return infoB;
}

template <class T>
T Node<T>::getInfoS(){
    return infoA && infoB;
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
void Node<T>::setCenter(Node<T> *value){
    center = value;
}

template <class T>
Node<T>* Node<T>::getCenter(){
    return center;
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
void Node<T>::setIsFull(bool value){
    isFull = value;
}

template <class T>
bool Node<T>::getIsFull(){
    return isFull;
}

template <class T>
void Node<T>::setIsEmpty(bool value){
    isEmpty = value;
}

template <class T>
bool Node<T>::getIsEmpty(){
    return isEmpty;
}

#endif
