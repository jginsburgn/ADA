#ifndef __BinaryTreeRB___
#define __BinaryTreeRB___

#include <iostream>
#include <algorithm>
#include "Node.h"

template <class T>
class BinaryTreeRB {
    
    RBNode<T> *root;
    RBNode<T> *flag;
    
    void fixinsert(RBNode<T> *third);
    void fixDelete(RBNode<T> *first);
    
    void RotateS(RBNode<T> *first);
    void RotateD(RBNode<T> *second);
    
    
public:
    
    BinaryTreeRB();
    
    RBNode<T>* getRoot();
    
    void InOrder();
    void InOrder(RBNode<T> *n);
    void postOrder();
    void postOrder(RBNode<T> *n);
    
    void insert(T e);
    bool isRed(RBNode<T> *n);
    bool search(T e);
    void removeInfo (T e);
    void decreasing(RBNode<T> *n);

	int height(RBNode<T>* RBNode);
    int depth(RBNode<T>* RBNode);
	int level(RBNode<T>* RBNode);
};

template <class T>
BinaryTreeRB<T>::BinaryTreeRB(){
    root = nullptr;
    T e = 0;
    RBNode<T>* f = new RBNode<T>(e, nullptr, nullptr);
    f->setColor("negro");
    flag = f;
}

template <class T>
RBNode<T>* BinaryTreeRB<T>::getRoot(){
    return root;
}

template <class T>
void BinaryTreeRB<T>::InOrder(){
    InOrder(root);
}

template <class T>
void BinaryTreeRB<T>::InOrder(RBNode<T> *n){
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
void BinaryTreeRB<T>::postOrder(RBNode<T> *n){
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
        RBNode<T> *n = new RBNode<T>(e, nullptr, flag);
        n->setColor("negro");
        root = n;
    }
    else{
        RBNode<T> *actual = root;
        RBNode<T> *anterior = root;
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
            RBNode<T> *n = new RBNode<T>(e,anterior,flag);
            anterior->setLeft(n);
            actual = n;
        }else{
            RBNode<T> *n = new RBNode<T>(e,anterior,flag);
            anterior->setRight(n);
            actual = n;
        }
        this->fixinsert(actual);
    }
    
}

template <class T>
void BinaryTreeRB<T>::RotateS(RBNode<T> *first){
    
    RBNode<T> *second = first->getRight();
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
void BinaryTreeRB<T>::RotateD(RBNode<T> *second){
    
    RBNode<T> *first = second->getLeft();
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
void BinaryTreeRB<T>::fixinsert(RBNode<T> *third){
    RBNode<T> *second;
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
bool BinaryTreeRB<T>::isRed(RBNode<T> *n){
    
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
    RBNode <T> *actual = root;
    int nivel = 0;
    while (actual != flag){
        if (actual->getInfo() == e){
            //std::cout << "nivel " << nivel << std::endl;
            //std::cout << "altura " << nivel-1 << std::endl;
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
    RBNode <T> *third = root;
    RBNode <T> *first,*second;
    
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
void BinaryTreeRB<T>::fixDelete(RBNode<T> *first){
    RBNode<T> *w;
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
void BinaryTreeRB<T>::decreasing(RBNode<T> *n){
    if (n==flag){
        return;
    }else{
        this->decreasing(n->getRight());
        cout << " " << n->getInfo();
        this->decreasing(n->getLeft());
    }
}

template <class T>
int BinaryTreeRB<T>::height(RBNode<T>* RBNode) {
	if (!RBNode)
		return -1;
	else
		return std::max(height(RBNode->getLeft()), height(RBNode->getRight())) + 1;
}

template <class T>
int BinaryTreeRB<T>::depth(RBNode<T>* RBNode) {
	if (!RBNode->getParent())
		return 0;
	return depth(RBNode->getParent()) + 1;
}

template <class T>
int BinaryTreeRB<T>::level(RBNode<T>* RBNode) {
	return depth(RBNode) + 1;
}

#endif
