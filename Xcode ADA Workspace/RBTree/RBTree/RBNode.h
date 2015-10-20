//Original code fetched from https://github.com/alberto911/arboles
//Corresponding credits go to Alberto Pickering 2015

#ifndef __RBRBNode__
#define __RBRBNode__

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class RBNode{

    T info;
    RBNode * parent;
    RBNode * left;
    RBNode * right;
    string color;

public:

    RBNode();
    RBNode(T e, RBNode *p, RBNode *dir);

    RBNode<T>* Grandparent();
    RBNode<T>* Uncle();

    void SetInfo(T value);
    T GetInfo();

    void SetLeft(RBNode<T> *value);
    RBNode<T> *GetLeft();

    void SetRight(RBNode<T> *value);
    RBNode<T> *GetRight();

    void setParent(RBNode<T> *value);
    RBNode<T> *GetParent();

    void SetColor(string c);
    string GetColor();

};

template <class T>
RBNode<T>::RBNode(){
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

template <class T>
RBNode<T>::RBNode(T e, RBNode *p, RBNode *dir){
    info = e;
    parent = p;
    left = dir;
    right = dir;
    color = "Red";
}

template <class T>
RBNode<T>* RBNode<T>::Grandparent(){
    if ((this != nullptr) && (this->parent != nullptr)){
        return this->GetParent()->GetParent();
    }else{
        return nullptr;
    }
}

template <class T>
RBNode<T>* RBNode<T>::Uncle(){
    if ((this != nullptr) && (this->parent != nullptr)){
        return this->GetParent()->GetParent();
    }else{
        return nullptr;
    }
}

template <class T>
void RBNode<T>::SetInfo(T value){
    info = value;
}

template <class T>
T RBNode<T>::GetInfo(){
    return info;
}

template <class T>
void RBNode<T>::setParent(RBNode<T> *value){
    parent = value;
}

template <class T>
RBNode<T>* RBNode<T>::GetParent(){
    return parent;
}

template <class T>
void RBNode<T>::SetLeft(RBNode<T> *value){
    left = value;
}

template <class T>
RBNode<T>* RBNode<T>::GetLeft(){
    return left;
}

template <class T>
void RBNode<T>::SetRight(RBNode<T> *value){
    right = value;
}

template <class T>
RBNode<T>* RBNode<T>::GetRight(){
    return right;
}

template <class T>
void RBNode<T>::SetColor(string c){
    color = c;
}

template <class T>
string RBNode<T>::GetColor(){
    return color;
}

#endif
