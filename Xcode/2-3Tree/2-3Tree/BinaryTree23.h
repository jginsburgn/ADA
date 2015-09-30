#ifndef __BinaryTree23_BN__
#define __BinaryTree23_BN__

#include <iostream>
#include "Node34.h"

template <class T>
class BinaryTree23{
private:
    Node<T> *root;
	void case1Left(Node<T>* node, Node<T>* parent, Node<T>* sibling);
	void case1Right(Node<T>* node, Node<T>* parent, Node<T>* sibling);
    
public:
    
    BinaryTree23();
    BinaryTree23(Node<T> *r);
    
    ~BinaryTree23();
    
    Node<T>* getRoot();
    
    void insert(T e);
    Node<T>* search(T e);
    void remove(T key);
    void remove(Node<T> *node);
	T findSuccessor(Node<T>* node, T key);
	void balanceRemoval(Node<T>* node);
    
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

}

template <class T>
void BinaryTree23<T>::remove(T key){
    Node<T>* node = search(key);
	if (!node)
		return;

	if (node->isLeaf()) {
		if (!node->getIsFull()) {
			balanceRemoval(node);
		}
		else {
			node->setIsFull(false);
			if (node->getInfoA() == key)
				node->setInfoA(node->getInfoB());
			node->setInfoB(0);
		}
		return;
	}

	T successor = findSuccessor(node, key);
}

template <class T>
void BinaryTree23<T>::balanceRemoval(Node<T>* node) {
	Node<T>* parent = node->getParent();
	if (!parent) {
		root = node->getLeft();
		delete node;
		return;
	}

	if (!parent->getIsFull()) {
		if (parent->getLeft() == node) {
			if (parent->getCenter()->getIsFull()) {
				case1Right(node, parent, parent->getCenter());
			}
			else {
				node->setInfoA(parent->getInfoA());
				node->setInfoB(parent->getCenter()->getInfoA());
				parent->setInfoA(0);
				node->setCenter(parent->getCenter()->getLeft());
				node->setRight(parent->getCenter()->getCenter());
				node->setIsFull(true);
				parent->setCenter(nullptr);
				balanceRemoval(parent);
			}
		}
		else {
			if (parent->getLeft()->getIsFull()) {
				case1Left(node, parent, parent->getLeft());
			}
			else {
				parent->getLeft()->setInfoB(parent->getInfoA());
				parent->setInfoA(0);
				parent->getLeft()->setRight(node->getLeft());
				parent->getLeft()->setIsFull(true);
				parent->setCenter(nullptr);
				balanceRemoval(parent);
			}
		}
	}

	else {
		if (parent->getLeft() == node) {
			if (parent->getCenter()->getIsFull())
				case1Right(node, parent, parent->getCenter());
			else if (parent->getRight()->getIsFull()) {
				parent->getRight()->setIsFull(false);
				node->setInfoA(parent->getInfoA());
				parent->setInfoA(parent->getCenter()->getInfoA());
				parent->getCenter()->setInfoA(parent->getInfoB());
				parent->setInfoB(parent->getRight()->getInfoA());
				parent->getRight()->setInfoA(parent->getRight()->getInfoB());
				parent->getRight()->setInfoB(0);
				node->setCenter(parent->getCenter()->getLeft());
				parent->getCenter()->setLeft(parent->getCenter()->getCenter());
				parent->getCenter()->setCenter(parent->getRight()->getLeft());
				parent->getRight()->setLeft(parent->getRight()->getCenter());
				parent->getRight()->setCenter(parent->getRight()->getRight());
				parent->getRight()->setRight(nullptr);
			}
			else {
				parent->setIsFull(false);
				node->setInfoA(parent->getInfoA());
				parent->setInfoA(parent->getCenter()->getInfoA());
				parent->getCenter()->setInfoA(parent->getInfoB());
				parent->getCenter()->setInfoB(parent->getRight()->getInfoA());
				parent->getCenter()->setIsFull(true);
				parent->setInfoB(0);
				node->setCenter(parent->getCenter()->getLeft());
				parent->getCenter()->setLeft(parent->getCenter()->getCenter());
				parent->getCenter()->setCenter(parent->getRight()->getLeft());
				parent->getCenter()->setRight(parent->getRight()->getCenter());		
				parent->setRight(nullptr);
			}
		}
	
		else if (parent->getCenter() == node) {
			if (parent->getLeft()->getIsFull())
				case1Left(node, parent, parent->getLeft());
			else if (parent->getRight()->getIsFull()) {
				parent->getRight()->setIsFull(false);
				node->setInfoA(parent->getInfoB());
				parent->setInfoB(parent->getRight()->getInfoA());
				parent->getRight()->setInfoA(parent->getRight()->getInfoB());
				parent->getRight()->setInfoB(0);
				node->setCenter(parent->getRight()->getLeft());
				parent->getRight()->setLeft(parent->getRight()->getCenter());
				parent->getRight()->setCenter(parent->getRight()->getRight());
				parent->getRight()->setRight(nullptr);
			}
			else {
				parent->setIsFull(false);
				parent->getLeft()->setInfoB(parent->getInfoA());
				parent->setInfoA(parent->getInfoB());
				parent->setInfoB(0);
				parent->getLeft()->setIsFull(true);
				parent->getLeft()->setRight(node->getLeft());
				parent->setCenter(parent->getRight());
				parent->setRight(nullptr);
			}
		}

		else {
			if (parent->getCenter()->getIsFull()) {
				parent->getCenter()->setIsFull(false);
				node->setInfoA(parent->getInfoB());
				parent->setInfoB(parent->getCenter()->getInfoB());
				parent->getCenter()->setInfoB(0);
				node->setCenter(node->getLeft());
				node->setLeft(parent->getCenter()->getRight());
				parent->getCenter()->setRight(nullptr);
			}
			else if (parent->getLeft()->getIsFull()) {
				parent->getLeft()->setIsFull(false);
				node->setInfoA(parent->getInfoB());
				parent->setInfoB(parent->getCenter()->getInfoA());
				parent->getCenter()->setInfoA(parent->getInfoA());
				parent->setInfoA(parent->getLeft()->getInfoB());
				parent->getLeft()->setInfoB(0);
				node->setCenter(node->getLeft());
				node->setLeft(parent->getCenter()->getCenter());
				parent->getCenter()->setCenter(parent->getCenter()->getLeft());
				parent->getCenter()->setLeft(parent->getLeft()->getRight());
				parent->getLeft()->setRight(nullptr);
			}
			else {
				parent->setIsFull(false);
				node->setInfoA(parent->getInfoB());
				parent->getLeft()->setInfoB(parent->getInfoA());
				parent->setInfoA(parent->getCenter()->getInfoA());
				parent->setInfoB(0);
				parent->getLeft()->setIsFull(true);				
				node->setCenter(node->getLeft());
				node->setLeft(parent->getCenter()->getCenter());
				parent->getLeft()->setRight(parent->getCenter()->getLeft());
				parent->setCenter(node);	
				parent->setRight(nullptr);
			}
		} 
	}
}

template <class T>
void BinaryTree23<T>::case1Left(Node<T>* node, Node<T>* parent, Node<T>* sibling) {
	sibling->setIsFull(false);
	node->setInfoA(parent->getInfoA());
	parent->setInfoA(sibling->getInfoB());
	sibling->setInfoB(0);
	node->setCenter(node->getLeft());
	node->setLeft(sibling->getRight());
	sibling->setRight(nullptr);
}

template <class T>
void BinaryTree23<T>::case1Right(Node<T>* node, Node<T>* parent, Node<T>* sibling) {
	sibling->setIsFull(false);
	node->setInfoA(parent->getInfoA());
	parent->setInfoA(sibling->getInfoA());
	sibling->setInfoA(sibling->getInfoB());
	sibling->setInfoB(0);
	node->setCenter(sibling->getLeft());
	sibling->setLeft(sibling->getCenter());
	sibling->setCenter(sibling->getRight());
	sibling->setRight(nullptr);
}

template <class T>
T BinaryTree23<T>::findSuccessor(Node<T>* node, T key) {
	Node<T>* p;
	if (node->getInfoA() == key)	
		p = node->getCenter();
	else
		p = node->getRight();

	while (p && p->getLeft())
		p = p->getLeft();

	T info = p->getInfoA();

	if (node->getInfoA() == key) {
		node->setInfoA(info);
	}
	else {
		node->setInfoB(info);
	}

	if (p->getIsFull()) {
		p->setIsFull(false);
		p->setInfoA(p->getInfoB());
		p->setInfoB(0);
	}
	else {
		balanceRemoval(p);
	}
	return info;
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
        
        this->inOrder(node->getCenter());
        
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
        
        this->postOrder(node->getCenter());
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
                    
                    location = location->getCenter();
                    
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
    pS->setCenter(nodeAux->getInLeft());
    node->setInfoA(nodeAux->getValueB());
    node->setLeft(nodeAux->getInRight());
    node->setCenter(nodeAux->getRightChild());
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
        p->setCenter(pB);
        root = p;
        
    }
    
    else if (p->getIsFull()){
        
        this->splitNode(medio, p, pS, pB);
        
    }
    
    else{
        if (medio > p->getInfoA()){
            
            p->setInfoB(medio);
			p->setRight(p->getCenter());
            p->setCenter(pS);
            p->setIsFull(true);
            
        }else{
            
            p->setInfoB(p->getInfoA());
            p->setInfoA(medio);
            p->setLeft(pS);
			p->setRight(p->getCenter());
            p->setCenter(pB);
            p->setIsFull(true);
            
        }
    }
    
}

template <class T>
Node<T>* BinaryTree23<T>::search(T e){
    
    Node<T> *location = root;
    int nivel = 0;
    while (location!= nullptr){
        
        if (location->getInfoA() == e || location->getInfoB() == e){
            std::cout << "nivel " << nivel << std::endl;
            std::cout << "altura " << nivel-1 << std::endl;
            return location;
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
                    location = location->getCenter();
                }
            }
        }
    }
    return nullptr;
    
}

template <class T>
int BinaryTree23<T>::height(Node<T>* node) {
	if (!node)
		return -1;
	else
		return std::max(height(node->getLeft()), height(node->getCenter()), height(node->getRight())) + 1;
}

template <class T>
int BinaryTree23<T>::depth(Node<T>* node) {
	if (!node->getParent())
		return 0;
	return depth(node->getParent()) + 1;
}

template <class T>
int BinaryTree23<T>::level(Node<T>* node) {
	return depth(node) + 1;
}

#endif
