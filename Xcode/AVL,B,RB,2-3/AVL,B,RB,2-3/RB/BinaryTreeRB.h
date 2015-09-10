#ifndef __BinaryTreeRB___
#define __BinaryTreeRB___

#include <iostream>
#include <algorithm>
#include "Node.h"

template <class T>
class BinaryTreeRB {
    
    Node<T> *root;
    Node<T> *flag;
    
    void fixinsert(Node<T> *third);
    void fixDelete(Node<T> *first);
    
    void RotateS(Node<T> *first);
    void RotateD(Node<T> *second);
    
    
public:
    
    BinaryTreeRB();
    
    Node<T>* getRoot();
    
    void InOrder();
    void InOrder(Node<T> *n);
    void postOrder();
    void postOrder(Node<T> *n);
    
    void insert(T e);
    bool isRed(Node<T> *n);
    bool search(T e);
    void removeInfo (T e);
    void decreasing(Node<T> *n);

	int height(Node<T>* node);
    int depth(Node<T>* node);
	int level(Node<T>* node);
};

template <class T>
BinaryTreeRB<T>::BinaryTreeRB(){
    root = nullptr;
    T e = 0;
    Node<T>* f = new Node<T>(e, nullptr, nullptr);
    f->setColor("negro");
    flag = f;
}

template <class T>
Node<T>* BinaryTreeRB<T>::getRoot(){
    return root;
}

template <class T>
void BinaryTreeRB<T>::InOrder(){
    InOrder(root);
}

template <class T>
void BinaryTreeRB<T>::InOrder(Node<T> *n){
    if (n==flag){
        return;
    }
    else{
        this->InOrder(n->getLeft());
        cout << n->getInfo() << " ";
        this->InOrder(n->getRight());
    }
}

template <class T>
void BinaryTreeRB<T>::postOrder(){
    postOrder(root);
}

template <class T>
void BinaryTreeRB<T>::postOrder(Node<T> *n){
    if (n==flag){
        return;
    }
    else{
        this->postOrder(n->getRight());
        cout << n->getInfo() << " ";
        this->postOrder(n->getLeft());
    }
}

template <class T>
void BinaryTreeRB<T>::insert(T e)
{
    
    if (root == nullptr){
        Node<T> *n = new Node<T>(e, nullptr, flag);
        n->setColor("negro");
        root = n;
    }
    else{
        Node<T> *actual = root;
        Node<T> *anterior = root;
        while (actual != flag){
            if (e < actual->getInfo()){
                anterior = actual;
                actual = actual->getLeft();
            }else{
                anterior = actual;
                actual = actual->getRight();
            }
        }
        if (e < anterior->getInfo()){
            Node<T> *n = new Node<T>(e,anterior,flag);
            anterior->setLeft(n);
            actual = n;
        }else{
            Node<T> *n = new Node<T>(e,anterior,flag);
            anterior->setRight(n);
            actual = n;
        }
        this->fixinsert(actual);
    }
    
}

template <class T>
void BinaryTreeRB<T>::RotateS(Node<T> *first){
    
    Node<T> *second = first->getRight();
    first->setRight(second->getLeft());
    second->getLeft()->setParent(first);
    second->setParent(first->getParent());

    if (first->getParent() ==nullptr){
        root= second;
    }else if  (first == first->getParent()->getLeft()){
        first->getParent()->setLeft(second);
    }else{
        first->getParent()->setRight(second);
    }
    second->setLeft(first);
    first->setParent(second);
}

template <class T>
void BinaryTreeRB<T>::RotateD(Node<T> *second){
    
    Node<T> *first = second->getLeft();
    second->setLeft(first->getRight());
    first->getRight()->setParent(second);
    first->setParent(second->getParent());
    if (second->getParent() == nullptr){
        root = first;
    }else if (second == second->getParent()->getLeft()){
        second->getParent()->setLeft(first);
    }else{
        second->getParent()->setRight(first);
    }
    first->setRight(second);
    second->setParent(first);
}

template <class T>
void BinaryTreeRB<T>::fixinsert(Node<T> *third){
    Node<T> *second;
    while (third->getParent() != nullptr && third->getParent()->getColor() == "rojo" ){
        if (third->getParent() == third->getParent()->getParent()->getLeft()){
            second = third->getParent()->getParent()->getRight();
            if (second->getColor() == "rojo"){
                third->getParent()->setColor("negro");
                second->setColor("negro");
                third->getParent()->getParent()->setColor("rojo");
                third = third->getParent()->getParent();
            }else{
                if (third == third->getParent()->getRight()){
                    third = third->getParent();
                    this->RotateS(third);
                }
                third->getParent()->setColor("negro");
                third->getParent()->getParent()->setColor("rojo");
                this->RotateD(third->getParent()->getParent());
            }
        }else{
            second = third->getParent()->getParent()->getLeft();
            if (second->getColor() == "rojo"){
                third->getParent()->setColor("negro");
                second->setColor("negro");
                third->getParent()->getParent()->setColor("rojo");
                third = third->getParent()->getParent();
            }else{
                if (third == third->getParent()->getLeft()){
                    third = third->getParent();
                    this->RotateD(third);
                }
                third->getParent()->setColor("negro");
                third->getParent()->getParent()->setColor("rojo");
                this->RotateS(third->getParent()->getParent());
            }
        }
    }
    root->setColor("negro");
    
}

template <class T>
bool BinaryTreeRB<T>::isRed(Node<T> *n){
    
    if (n == flag){
        return true;
    }
    bool resp = true;
    if (root == n){
        resp = resp && root->getColor() == "negro";
    }
    if (n->getColor() == "rojo"){
        resp = resp && n->getLeft()->getColor() == "negro" && n->getRight()->getColor() == "negro";
    }
    return resp && this->isRed(n->getLeft()) && this->isRed(n->getRight());
    
}

template <class T>
bool BinaryTreeRB<T>::search(T e){
    Node <T> *actual = root;
    int nivel = 0;
    while (actual != flag){
        if (actual->getInfo() == e){
            std::cout << "nivel " << nivel << std::endl;
            std::cout << "altura " << nivel-1 << std::endl;
            return true;
        }
        if (e < actual->getInfo()){
            nivel++;
            actual = actual->getLeft();
        }else{
            nivel++;
            actual = actual->getRight();
        }
    }
    return false;
}

template <class T>
void BinaryTreeRB<T>::removeInfo (T e){
    Node <T> *third = root;
    Node <T> *first,*second;
    
    while (third->getInfo() != e){
        if (e < third->getInfo()){
            third = third->getLeft();
        }
        else{
            third = third->getRight();
        }
    }
    
    if (third->getLeft() != flag && third->getRight() != flag){
        second = third->getLeft();
        while (second->getRight() != flag){
            second = second->getRight();
        }
    }else{
        second = third;
    }
    
    if (second->getLeft() != flag){
        first = second->getLeft();
    }else{
        first = second->getRight();
    }
    
    first->setParent(second->getParent());
    if (second->getParent() == nullptr ){
        root =first;
    }else if (second == second->getParent()->getLeft()){
        second->getParent()->setLeft(first);
    }else{
        second->getParent()->setRight(first);
    }
    
    if (second != third){
        third->setInfo(second->getInfo());
    }
    if (second->getColor() == "negro" ){
        this->fixDelete(first);
    }
    delete second;
    
}

template <class T>
void BinaryTreeRB<T>::fixDelete(Node<T> *first){
    Node<T> *w;
    while (first != root && first->getColor() =="negro"){
        if (first == first->getParent()->getLeft()){
            w = first->getParent()->getRight();
            if (w->getColor() == "rojo"){
                w->setColor("negro");
                first->getParent()->setColor("rojo");
                this->RotateS(first->getParent());
                w = first->getParent()->getRight();
            }
            if (w->getLeft()->getColor() == "negro" && w->getRight()->getColor() == "negro"){
                w->setColor("rojo");
                first =  first->getParent();
            }else{
                if (w->getRight()->getColor() == "negro"){
                    w->getLeft()->setColor("negro");
                    w->setColor("rojo");
                    RotateD(w);
                    w = first->getParent()->getRight();
                }
                w->setColor(first->getParent()->getColor());
                first->getParent()->setColor("negro");
                w->getRight()->setColor("negro");
                RotateS(first->getParent());
                first = root;
            }
        }else{
            w = first->getParent()->getLeft();
            if (w->getColor() == "rojo"){
                w->setColor("negro");
                first->getParent()->setColor("rojo");
                this->RotateD(first->getParent());
                w=first->getParent()->getLeft();
            }
            if (w->getRight()->getColor() == "negro" && w->getLeft()->getColor() == "negro"){
                w->setColor("rojo");
                first =  first->getParent();
            }
            else{
                if (w->getLeft()->getColor() == "negro"){
                    w->getRight()->setColor("negro");
                    w->setColor("rojo");
                    RotateS(w);
                    w = first->getParent()->getLeft();
                }
                w->setColor(first->getParent()->getColor());
                first->getParent()->setColor("negro");
                w->getLeft()->setColor("negro");
                RotateD(first->getParent());
                first = root;
            }
        }
    }
    first->setColor("negro");
}


template <class T>
void BinaryTreeRB<T>::decreasing(Node<T> *n){
    if (n==flag){
        return;
    }else{
        this->decreasing(n->getRight());
        cout << " " << n->getInfo();
        this->decreasing(n->getLeft());
    }
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
