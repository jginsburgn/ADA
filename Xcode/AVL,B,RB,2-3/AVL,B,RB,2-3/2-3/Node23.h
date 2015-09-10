#ifndef BinaryTree23Prueba_Node23_h
#define BinaryTree23Prueba_Node23_h

template <class T>
class Node23{
    
    T valueS;
    T valueM;
    T valueB;
    
    Node<T> *leftChild;
    Node<T> *inLeft;
    Node<T> *inRight;
    Node<T> *rightChild;
    
public:
    
    Node23();
    Node23(Node<T> *nodeA23, T Llave, Node<T> *leftChildValue, Node<T> *rightChildValue);
    
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
Node23<T>::Node23(){

}

template <class T>
Node23<T>::Node23(Node<T> *nodeA23, T Llave, Node<T> *leftChildValue, Node<T> *rightChildValue){
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
void Node23<T>::setValueS(T value){
    valueS = value;
}

template <class T>
T Node23<T>::getValueS(){
    return valueS;
}

template <class T>
void Node23<T>::setValueM(T value){
    valueM = value;
}

template <class T>
T Node23<T>::getValueM(){
    return valueM;
}

template <class T>
void Node23<T>::setValueB(T value){
    valueB = value;
}

template <class T>
T Node23<T>::getValueB(){
    return valueB;
}

template <class T>
void Node23<T>::setLeftChild(Node<T> *value){
    leftChild = value;
}

template <class T>
Node<T>* Node23<T>::getLeftChild(){
    return leftChild;
}

template <class T>
void Node23<T>::setInLeft(Node<T> *value){
    inLeft = value;
}

template <class T>
Node<T>* Node23<T>::getInLeft(){
    return inLeft;
}

template <class T>
void Node23<T>::setInRight(Node<T> *value){
    inRight = value;
}

template <class T>
Node<T>* Node23<T>::getInRight(){
    return inRight;
}

template <class T>
void Node23<T>::setRightChild(Node<T> *value){
    rightChild = value;
}

template <class T>
Node<T>* Node23<T>::getRightChild(){
    return rightChild;
}

#endif
