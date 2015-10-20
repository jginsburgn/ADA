//Original code fetched from https://github.com/alberto911/arboles
//Corresponding credits go to Alberto Pickering 2015

#ifndef __TwoThreeNode__
#define __TwoThreeNode__

template <class T>
class TwoThreeNode{
    
    T valueS;
    T valueM;
    T valueB;
    
    Node<T> *leftChild;
    Node<T> *inLeft;
    Node<T> *inRight;
    Node<T> *rightChild;
    
public:
    
    TwoThreeNode();
    TwoThreeNode(Node<T> *nodeA23, T Llave, Node<T> *leftChildValue, Node<T> *rightChildValue);
    
    void  setValueS(T value);
    T  getValueS();
    
    void  setValueM(T value);
    T  getValueM();
    
    void  setValueB(T value);
    T  getValueB();
    
    void setLeftChild(Node<T> *value);
    Node<T> *getLeftChild();
    
    void setInLeft(Node<T> *value);
    Node<T> *getInLeft();
    
    void setInRight(Node<T> *value);
    Node<T> *getInRight();
    
    void setRightChild(Node<T> *value);
    Node<T> *getRightChild();
};

template <class T>
TwoThreeNode<T>::TwoThreeNode(){

}

template <class T>
TwoThreeNode<T>::TwoThreeNode(Node<T> *nodeA23, T Llave, Node<T> *leftChildValue, Node<T> *rightChildValue){
    if (Llave < nodeA23->getInfoA())
    {
        
        valueS = Llave;
        valueM = nodeA23->getInfoA();
        valueB = nodeA23->getInfoB();
        
        leftChild = leftChildValue;
        inLeft = rightChildValue;
        inRight = nodeA23->getCenter();
        rightChild = nodeA23->getRight();
        
    }
    else if (Llave > nodeA23->getInfoB())
    {
        
        valueS = nodeA23->getInfoA();
        valueM = nodeA23->getInfoB();
        valueB = Llave;
        
        leftChild = nodeA23->getLeft();
        inLeft = nodeA23->getCenter();
        inRight = leftChildValue;
        rightChild = rightChildValue;
        
    }
    else
    {
        valueS = nodeA23->getInfoA();
        valueM = Llave;
        valueB = nodeA23->getInfoB();
        
        leftChild = nodeA23->getLeft();
        inLeft = leftChildValue;
        inRight = rightChildValue;
        rightChild = nodeA23->getRight();
    }
}

template <class T>
void TwoThreeNode<T>::setValueS(T value){
    valueS = value;
}

template <class T>
T TwoThreeNode<T>::getValueS(){
    return valueS;
}

template <class T>
void TwoThreeNode<T>::setValueM(T value){
    valueM = value;
}

template <class T>
T TwoThreeNode<T>::getValueM(){
    return valueM;
}

template <class T>
void TwoThreeNode<T>::setValueB(T value){
    valueB = value;
}

template <class T>
T TwoThreeNode<T>::getValueB(){
    return valueB;
}

template <class T>
void TwoThreeNode<T>::setLeftChild(Node<T> *value){
    leftChild = value;
}

template <class T>
Node<T>* TwoThreeNode<T>::getLeftChild(){
    return leftChild;
}

template <class T>
void TwoThreeNode<T>::setInLeft(Node<T> *value){
    inLeft = value;
}

template <class T>
Node<T>* TwoThreeNode<T>::getInLeft(){
    return inLeft;
}

template <class T>
void TwoThreeNode<T>::setInRight(Node<T> *value){
    inRight = value;
}

template <class T>
Node<T>* TwoThreeNode<T>::getInRight(){
    return inRight;
}

template <class T>
void TwoThreeNode<T>::setRightChild(Node<T> *value){
    rightChild = value;
}

template <class T>
Node<T>* TwoThreeNode<T>::getRightChild(){
    return rightChild;
}

#endif
