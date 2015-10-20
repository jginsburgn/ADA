//Original code fetched from https://github.com/alberto911/arboles
//Corresponding credits go to Alberto Pickering 2015

#ifndef __RBTree___
#define __RBTree___

#include <iostream>
#include <algorithm>
#include "RBNode.h"

template <class T>
class RBTree {

    RBNode<T> * root;
    RBNode<T> * flag;

    void FixInsert(RBNode<T> * third);
    void FixDelete(RBNode<T> * first);

    void RotateS(RBNode<T> * first);
    void RotateD(RBNode<T> * second);


public:

    RBTree();
    RBNode<T> * getRoot();
    void PrintAscending();
    void PrintAscending(RBNode<T> *n);
    void PrintDescending();
    void PrintDescending(RBNode<T> *n);
    void Insert(T e);
    bool IsRed(RBNode<T> *n);
    bool Search(T e);
    void Erase(T e);
    void Decreasing(RBNode<T> *n);
    int Height(RBNode<T>* node);
    int Depth(RBNode<T>* node);
    int Level(RBNode<T>* node);
};

template <class T>
RBTree<T>::RBTree(){
    root = nullptr;
    T e = 0;
    RBNode<T>* f = new RBNode<T>(e, nullptr, nullptr);
    f->SetColor("Black");
    flag = f;
}

template <class T>
RBNode<T>* RBTree<T>::getRoot(){
    return root;
}

template <class T>
void RBTree<T>::PrintAscending(){
    PrintAscending(root);
}

template <class T>
void RBTree<T>::PrintAscending(RBNode<T> *n){
    if (n==flag){
        return;
    }
    else{
        this->PrintAscending(n->GetLeft());
        cout << n->GetInfo() << "\n";
        this->PrintAscending(n->GetRight());
    }
}

template <class T>
void RBTree<T>::PrintDescending(){
    PrintDescending(root);
}

template <class T>
void RBTree<T>::PrintDescending(RBNode<T> *n){
    if (n==flag){
        return;
    }
    else{
        this->PrintDescending(n->GetRight());
        cout << n->GetInfo() << "\n";
        this->PrintDescending(n->GetLeft());
    }
}

template <class T>
void RBTree<T>::Insert(T e)
{

    if (root == nullptr){
        RBNode<T> *n = new RBNode<T>(e, nullptr, flag);
        n->SetColor("Black");
        root = n;
    }
    else{
        RBNode<T> *actual = root;
        RBNode<T> *anterior = root;
        while (actual != flag){
            if (e < actual->GetInfo()){
                anterior = actual;
                actual = actual->GetLeft();
            }else{
                anterior = actual;
                actual = actual->GetRight();
            }
        }
        if (e < anterior->GetInfo()){
            RBNode<T> *n = new RBNode<T>(e,anterior,flag);
            anterior->SetLeft(n);
            actual = n;
        }else{
            RBNode<T> *n = new RBNode<T>(e,anterior,flag);
            anterior->SetRight(n);
            actual = n;
        }
        this->FixInsert(actual);
    }

}

template <class T>
void RBTree<T>::RotateS(RBNode<T> *first){

    RBNode<T> *second = first->GetRight();
    first->SetRight(second->GetLeft());
    second->GetLeft()->setParent(first);
    second->setParent(first->GetParent());

    if (first->GetParent() ==nullptr){
        root= second;
    }else if  (first == first->GetParent()->GetLeft()){
        first->GetParent()->SetLeft(second);
    }else{
        first->GetParent()->SetRight(second);
    }
    second->SetLeft(first);
    first->setParent(second);
}

template <class T>
void RBTree<T>::RotateD(RBNode<T> *second){

    RBNode<T> *first = second->GetLeft();
    second->SetLeft(first->GetRight());
    first->GetRight()->setParent(second);
    first->setParent(second->GetParent());
    if (second->GetParent() == nullptr){
        root = first;
    }else if (second == second->GetParent()->GetLeft()){
        second->GetParent()->SetLeft(first);
    }else{
        second->GetParent()->SetRight(first);
    }
    first->SetRight(second);
    second->setParent(first);
}

template <class T>
void RBTree<T>::FixInsert(RBNode<T> *third){
    RBNode<T> *second;
    while (third->GetParent() != nullptr && third->GetParent()->GetColor() == "Red" ){
        if (third->GetParent() == third->GetParent()->GetParent()->GetLeft()){
            second = third->GetParent()->GetParent()->GetRight();
            if (second->GetColor() == "Red"){
                third->GetParent()->SetColor("Black");
                second->SetColor("Black");
                third->GetParent()->GetParent()->SetColor("Red");
                third = third->GetParent()->GetParent();
            }else{
                if (third == third->GetParent()->GetRight()){
                    third = third->GetParent();
                    this->RotateS(third);
                }
                third->GetParent()->SetColor("Black");
                third->GetParent()->GetParent()->SetColor("Red");
                this->RotateD(third->GetParent()->GetParent());
            }
        }else{
            second = third->GetParent()->GetParent()->GetLeft();
            if (second->GetColor() == "Red"){
                third->GetParent()->SetColor("Black");
                second->SetColor("Black");
                third->GetParent()->GetParent()->SetColor("Red");
                third = third->GetParent()->GetParent();
            }else{
                if (third == third->GetParent()->GetLeft()){
                    third = third->GetParent();
                    this->RotateD(third);
                }
                third->GetParent()->SetColor("Black");
                third->GetParent()->GetParent()->SetColor("Red");
                this->RotateS(third->GetParent()->GetParent());
            }
        }
    }
    root->SetColor("Black");

}

template <class T>
bool RBTree<T>::IsRed(RBNode<T> *n){

    if (n == flag){
        return true;
    }
    bool resp = true;
    if (root == n){
        resp = resp && root->GetColor() == "Black";
    }
    if (n->GetColor() == "Red"){
        resp = resp && n->GetLeft()->GetColor() == "Black" && n->GetRight()->GetColor() == "Black";
    }
    return resp && this->IsRed(n->GetLeft()) && this->IsRed(n->GetRight());

}

template <class T>
bool RBTree<T>::Search(T e){
    RBNode <T> *actual = root;
    int Level = 0;
    while (actual != flag){
        if (actual->GetInfo() == e){
            
            return true;
        }
        if (e < actual->GetInfo()){
            Level++;
            actual = actual->GetLeft();
        }else{
            Level++;
            actual = actual->GetRight();
        }
    }
    return false;
}

template <class T>
void RBTree<T>::Erase (T e){
    RBNode <T> *third = root;
    RBNode <T> *first,*second;

    while (third->GetInfo() != e){
        if (e < third->GetInfo()){
            third = third->GetLeft();
        }
        else{
            third = third->GetRight();
        }
    }

    if (third->GetLeft() != flag && third->GetRight() != flag){
        second = third->GetLeft();
        while (second->GetRight() != flag){
            second = second->GetRight();
        }
    }else{
        second = third;
    }

    if (second->GetLeft() != flag){
        first = second->GetLeft();
    }else{
        first = second->GetRight();
    }

    first->setParent(second->GetParent());
    if (second->GetParent() == nullptr ){
        root =first;
    }else if (second == second->GetParent()->GetLeft()){
        second->GetParent()->SetLeft(first);
    }else{
        second->GetParent()->SetRight(first);
    }

    if (second != third){
        third->SetInfo(second->GetInfo());
    }
    if (second->GetColor() == "Black" ){
        this->FixDelete(first);
    }
    delete second;

}

template <class T>
void RBTree<T>::FixDelete(RBNode<T> *first){
    RBNode<T> *w;
    while (first != root && first->GetColor() =="Black"){
        if (first == first->GetParent()->GetLeft()){
            w = first->GetParent()->GetRight();
            if (w->GetColor() == "Red"){
                w->SetColor("Black");
                first->GetParent()->SetColor("Red");
                this->RotateS(first->GetParent());
                w = first->GetParent()->GetRight();
            }
            if (w->GetLeft()->GetColor() == "Black" && w->GetRight()->GetColor() == "Black"){
                w->SetColor("Red");
                first =  first->GetParent();
            }else{
                if (w->GetRight()->GetColor() == "Black"){
                    w->GetLeft()->SetColor("Black");
                    w->SetColor("Red");
                    RotateD(w);
                    w = first->GetParent()->GetRight();
                }
                w->SetColor(first->GetParent()->GetColor());
                first->GetParent()->SetColor("Black");
                w->GetRight()->SetColor("Black");
                RotateS(first->GetParent());
                first = root;
            }
        }else{
            w = first->GetParent()->GetLeft();
            if (w->GetColor() == "Red"){
                w->SetColor("Black");
                first->GetParent()->SetColor("Red");
                this->RotateD(first->GetParent());
                w=first->GetParent()->GetLeft();
            }
            if (w->GetRight()->GetColor() == "Black" && w->GetLeft()->GetColor() == "Black"){
                w->SetColor("Red");
                first =  first->GetParent();
            }
            else{
                if (w->GetLeft()->GetColor() == "Black"){
                    w->GetRight()->SetColor("Black");
                    w->SetColor("Red");
                    RotateS(w);
                    w = first->GetParent()->GetLeft();
                }
                w->SetColor(first->GetParent()->GetColor());
                first->GetParent()->SetColor("Black");
                w->GetLeft()->SetColor("Black");
                RotateD(first->GetParent());
                first = root;
            }
        }
    }
    first->SetColor("Black");
}


template <class T>
void RBTree<T>::Decreasing(RBNode<T> *n){
    if (n==flag){
        return;
    }else{
        this->Decreasing(n->GetRight());
        cout << " " << n->GetInfo();
        this->Decreasing(n->GetLeft());
    }
}

template <class T>
int RBTree<T>::Height(RBNode<T>* node) {
	if (!node)
		return -1;
	else
		return std::max(Height(node->GetLeft()), Height(node->GetRight())) + 1;
}

template <class T>
int RBTree<T>::Depth(RBNode<T>* node) {
	if (!node->GetParent())
		return 0;
	return Depth(node->GetParent()) + 1;
}

template <class T>
int RBTree<T>::Level(RBNode<T>* node) {
	return Depth(node) + 1;
}

#endif
