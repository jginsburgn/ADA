#ifndef __BinaryTree23_BN__
#define __BinaryTree23_BN__

#include <iostream>
#include "Node34.h"

template <class T>
class BinaryTree23{
private:
    Node<T> *root;
    
public:
    
    BinaryTree23();
    BinaryTree23(Node<T> *r);
    
    ~BinaryTree23();
    
    Node<T>* getRoot();
    
    void insert(T e);
    bool search(T e);
    void remove(T e);
    void remove(Node<T> *node);
    
    void splitNode(T e, Node<T> *node, Node<T> *pCLKey = 0, Node<T> *pCRKey = 0);
    
    void inOrder();
    void inOrder(Node<T> *node);
    
    void postOrder();
    void postOrder(Node<T> *node);

	int height(Node<T>* node);
    int depth(Node<T>* node);
	int level(Node<T>* node);    
};

template <class T>
BinaryTree23<T>::BinaryTree23(){
    root = nullptr;
}

template <class T>
BinaryTree23<T>::BinaryTree23(Node<T> *r){
    root = r;
}


template <class T>
BinaryTree23<T>::~BinaryTree23(){
    
    remove(root);
    root = nullptr;
    
}

template <class T>
void BinaryTree23<T>::remove(T e){
    
    Node<T>* node = new Node<T>(e);
    BinaryTree23<T>::remove(node);
}

template <class T>
void BinaryTree23<T>::remove(Node<T> *node){
    
    if (node == nullptr){
        return;
    }else{
        
        this->remove(node->getLeft());
        this->remove(node->getCenter());
        this->remove(node->getRight());
    
        
    }
}

template <class T>
Node<T>* BinaryTree23<T>::getRoot(){
    return root;
}

template <class T>
void BinaryTree23<T>::inOrder(){
    return inOrder(root);
}

template <class T>
void BinaryTree23<T>::inOrder(Node<T> *node){
    if (node ==nullptr){
        return;
    }
    
    if (node->getIsFull()){
        
        this->inOrder(node->getLeft());
        cout << node->getInfoA() << " ";
        
        this->inOrder(node->getCenter());
        cout << node->getInfoB() << " ";
        
        this->inOrder(node->getRight());
        
    }else{
        
        this->inOrder(node->getLeft());
        cout << node->getInfoA() << " ";
        
        this->inOrder(node->getRight());
        
    }
}

template <class T>
void BinaryTree23<T>::postOrder(){
    return postOrder(root);
}

template <class T>
void BinaryTree23<T>::postOrder(Node<T> *node){
    if (node ==nullptr){
        return;
    }
    
    if (node->getIsFull()){
        
        this->postOrder(node->getRight());
        cout << node->getInfoB() << " ";
        
        this->postOrder(node->getCenter());
        cout << node->getInfoA() << " ";
        
        this->postOrder(node->getLeft());
        
    }else{
        
        this->postOrder(node->getRight());
        cout << node->getInfoA() << " ";
        
        this->postOrder(node->getLeft());
        
    }
}

template <class T>
void BinaryTree23<T>::insert(T e){
    
    if (root == nullptr){
        Node<T> *n = new Node<T>(e);
        root = n;
    }else{
        Node<T> *location = root;
        while (!location->isLeaf())
        {
            if (e < location->getInfoA()){
                
                location = location->getLeft();
                
            }else{
                if (!location->getIsFull()){
                    
                    location = location->getRight();
                    
                }else{
                    if (e <= location->getInfoB()){
                        
                        location = location->getCenter();
                        
                    }else{
                        
                        location = location->getRight();
                        
                    }
                }
            }
        }
        
        if (!location->getIsFull())
        {
            if (e > location->getInfoA()){
                
                location->setInfoB(e);
                
            }else{
                
                T temp = location->getInfoA();
                location->setInfoA(e);
                location->setInfoB(temp);
                
            }
            location->setIsFull(true);
        }else{
            this->splitNode(e, location);
        }
    }
}

template <class T>
void BinaryTree23<T>::splitNode(T e, Node<T> *node, Node<T> *pCLKey, Node<T> *pCRKey){
    
    Node<T> *p;
    
    bool aux = false;
    bool isLeaf = node->isLeaf();
    
    if (root == node){
        
        p = new Node<T>();
        aux = true;
        
    }else{
        
        p = node->getParent();
        
    }
    
    Node23<T> *nodeAux = new Node23<T>(node, e, pCLKey, pCRKey);
    Node<T> *pS = new Node<T>(nodeAux->getValueS());
    
    pS->setParent(p);
    pS->setLeft(nodeAux->getLeftChild());
    pS->setRight(nodeAux->getInLeft());
    node->setInfoA(nodeAux->getValueB());
    node->setLeft(nodeAux->getInRight());
    node->setRight(nodeAux->getRightChild());
    node->setIsFull(false);
    node->setParent(p);
    
    Node<T> *pB = node;
    
    
    if (!isLeaf){
        
        nodeAux->getLeftChild()->setParent(pS);
        nodeAux->getInLeft()->setParent(pS);
        nodeAux->getInRight()->setParent(pB);
        nodeAux->getRightChild()->setParent(pB);
        
    }
    
    T medio = nodeAux->getValueM();
    
    if (aux){
        
        p->setInfoA(medio);
        p->setLeft(pS);
        p->setRight(pB);
        root = p;
        
    }
    
    else if (p->getIsFull()){
        
        this->splitNode(medio, p, pS, pB);
        
    }
    
    else{
        if (medio > p->getInfoA()){
            
            p->setInfoB(medio);
            p->setCenter(pS);
            p->setIsFull(true);
            
        }else{
            
            p->setInfoB(p->getInfoA());
            p->setInfoA(medio);
            p->setLeft(pS);
            p->setCenter(pB);
            p->setIsFull(true);
            
        }
    }
    
}

template <class T>
bool BinaryTree23<T>::search(T e){
    
    Node<T> *location = root;
    int nivel = 0;
    while (location!= nullptr){
        
        if (location->getInfoA() == e || location->getInfoB() == e){
            std::cout << "nivel " << nivel << std::endl;
            std::cout << "altura " << nivel-1 << std::endl;
            return true;
        }else{
            if (location->getIsFull()){
                if (e < location->getInfoA()){
                    nivel++;
                    location = location->getLeft();
                }else if (e > location->getInfoB()){
                    nivel++;
                    location = location->getRight();
                }else{
                    nivel++;
                    location = location->getCenter();
                }
            }else{
                if ( e < location->getInfoA()){
                    nivel++;
                    location = location->getLeft();
                }
                else{
                    nivel++;
                    location = location->getRight();
                }
            }
        }
    }
    return false;
    
}

template <class T>
int BinaryTreeRB<T>::height(Node<T>* node) {
	if (!node)
		return -1;
	else
		return std::max(height(node->getLeft()), height(node->getRight())) + 1;
}

int BinaryTreeRB<T>::depth(Node<T>* node) {
	if (!node->getParent())
		return 0;
	return depth(node->getParent()) + 1;
}

int BinaryTreeRB<T>::level(Node<T>* node) {
	return depth(node) + 1;
}

#endif
