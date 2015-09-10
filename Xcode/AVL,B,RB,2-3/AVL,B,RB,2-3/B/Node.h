#ifndef __BinaryTreeB_Node_
#define __BinaryTreeB_Node_

#include <iostream>
using namespace std;

template <class T, int V>
class Node {
    //Node<T> * parent = nullptr;
public:
    
    T infoArray[V-1];
    int count;
    
    Node<T, V> *link[V];
	Node();
    
    void print();
    
	bool isEmpty();
	bool isFull();

	//Node<T> * getParent() const { return parent; }
    //void setParent(Node<T> * value) { parent = value; }
    
};

template <class T, int V>
Node<T,V>::Node(){
    
	this->count = 0;
    
    for(int i=0;i < V;i++){
        this->link[i] = nullptr;
    }
}

template<class T, int V>
bool Node<T,V>::isFull(){
	return count == V-1;
}

template<class T, int V>
bool Node<T, V>::isEmpty(){
	return count < (V-1)/2;
}

template<class T, int V>
void Node< T,V>::print() {
	
    for(int i = 0; i  < this->count ;i++){
        std::cout <<"  "<< infoArray[i]<<", ";
    }
	
    std::cout << std::endl;
	
}

#endif
