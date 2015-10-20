#include "Node.h"
#include "Node23.h"

template <class T>
class Node34{
    
public:
    
    T smallValue;
    T middleValue;
    T largeValue;
    
    Node<T> *leftChild;
    Node<T> *leftMiddleChild;
    
    Node<T> *rightMiddleChild;
    Node<T> *rightChild;
    
    Node34(Node<T> *threeNode, T new_value, Node<T> *leftChildNV= 0, Node<T> *rightChildNV= 0);
    
    T  getSmallValue();
    T  getMiddleValue();
    T  getLargeValue();
    Node<T> *getLeftChild();
    Node<T> *getLeftMiddleChild();
    Node<T> *getRightMiddleChild();
    Node<T> *getRightChild();
    
};


template<class T>
Node34<T>::Node34(Node<T> *threeNode, T auxKey, Node<T> *leftChildNV, Node<T> *rightChildNV) {
    if (auxKey > threeNode->infoOne) {
        
        smallValue = threeNode->infoOne;
        middleValue = threeNode->infoTwo;
        largeValue = auxKey;
        
        leftChild = threeNode->left;
        leftMiddleChild = threeNode->center;
        rightMiddleChild = leftChildNV;
        rightChild = rightChildNV;
        
    } else if (auxKey < threeNode->infoTwo) {
        
        smallValue = auxKey;
        middleValue = threeNode->infoOne;
        largeValue = threeNode->infoTwo;
        
        leftChild = leftChildNV;
        leftMiddleChild = rightChildNV;
        rightMiddleChild = threeNode->center;
        rightChild = threeNode->right;
        
        
    } else { // auxKey is the middle value
        
        smallValue = threeNode->infoOne;
        middleValue = auxKey;
        largeValue = threeNode->infoTwo;
        
        leftChild = threeNode->left;
        leftMiddleChild = leftChildNV;
        rightMiddleChild = rightChildNV;
        rightChild = threeNode->right;
    }
}

template<class T>
T Node34<T>::getSmallValue(){
    return smallValue;
}

template<class T>
T Node34<T>::getMiddleValue(){
    return middleValue;
}

template<class T>
T Node34<T>::getLargeValue(){
    return largeValue;
}

template<class T>
Node<T>* Node34<T>::getLeftChild(){
    return leftChild;
}

template<class T>
Node<T>* Node34<T>::getLeftMiddleChild(){
    return leftMiddleChild;
}

template<class T>
Node<T>* Node34<T>::getRightMiddleChild(){
    return rightMiddleChild;
}

template<class T>
Node<T>* Node34<T>::getRightChild(){
    return rightChild;
}
