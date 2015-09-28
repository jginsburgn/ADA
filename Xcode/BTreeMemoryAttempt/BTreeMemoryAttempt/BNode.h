//
//  BNode.h
//  BTreeMemoryAttempt
//
//  Created by Jonathan Ginsburg on 9/11/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef BTreeMemoryAttempt_BNode_h
#define BTreeMemoryAttempt_BNode_h

#include <vector>

template <class T>
class BTree;

template <class T>
class BNode {

    friend class BTree<T>;
    
private:
    int order = 0;
    
    std::vector<T> values;
    std::vector<BNode<T> *> children;
    
    bool IsFull();
    bool IsLeaf();
    BNode<T> * Split(T newValue, T & median);
    BNode<T> * SplitWithSplitChild(BNode<T> * newRightChild, T newValue, T & median);
    void PositionNewValue(T newValue);
    int ChildFor(T value) const;
    void EraseChildren();
    int IndexOfNewValue(T newValue) const;
    int IndexOfValueInNode(T value) const;
    T FindReplacementForKeyAt(int index, bool & found, int & indexOfSubtreeWhereFound);
    void ShiftChildrenLeftFrom(int childIndex);
    void ShiftValuesLeftFrom(int index);
    void Rebalance(int indexOfUnbalancedChild);
    T GetLeastValue();
    T GetGreatestValue();
    BNode<T> * GetLeftSibling(int indexOfChild);
    BNode<T> * GetRightSibling(int indexOfChild);
    bool CanSpareNumberOfValues(int numberOfValues);
    void RotateRightAt(int indexOfPivot);
    void RotateLeftAt(int indexOfPivot);
    void PushValueIntoChildAtFromThis(int indexOfChildToPush);
    void MergeSiblingsAt(int index);

public:

    BNode<T>(int newOrder){ order = newOrder; EraseChildren(); }
    void Insert(T newValue, std::vector<void *> * results);
    void Erase(T valueToErase, bool & underflowOcurred);
    void PrintAscending() const;
    void PrintDescending() const;
    bool Search(T value) const;
    bool IsLegal(bool isShallow) const;

};

template <class T>
bool BNode<T>::IsFull() {
    return values.size() == 2 * order;
}

template <class T>
bool BNode<T>::IsLeaf(){
    for (int i = 0; i < children.size(); ++i) {
        if (children[i]) {
            return false;
        }
    }
    return true;
}

template <class T>
BNode<T> * BNode<T>::Split(T newValue, T & median){
    BNode<T> * newRight = new BNode<T>(order);
    int indexOfNewValue = IndexOfNewValue(newValue);
    std::vector<T> tmpValues;
    std::vector<BNode<T> *> tmpChildren;
    for (int i = 0; i < values.size() + 1; ++i) {
        if (i == indexOfNewValue) {
            tmpValues.push_back(newValue);
        }
        else if (i > indexOfNewValue){
            tmpValues.push_back(values[i - 1]);
        }
        else tmpValues.push_back(values[i]);
    }
    for (int i = 0; i < children.size() + 1; ++i) {
        tmpChildren.push_back(nullptr);
    }
    for (int i = 0; i < children.size() + 1; ++i) {
        if (i == indexOfNewValue + 1) {
            tmpChildren[i] = nullptr;
        }
        else if (i > indexOfNewValue + 1){
            tmpChildren[i] = children[i - 1];
        }
        else tmpChildren[i] = children[i];
    }
    values.clear();
    median = tmpValues[(2 * order + 1)/2];
    for (int i = 0; i < order; ++i) {
        values.push_back(tmpValues[i]);
    }
    for (int i = order + 1; i < 2 * order + 1; ++i) {
        newRight->values.push_back(tmpValues[i]);
    }
    EraseChildren();
    newRight->EraseChildren();
    for (int i = 0; i < tmpChildren.size()/2; ++i) {
        children[i] = tmpChildren[i];
    }
    for (int i = 0; i < tmpChildren.size()/2; ++i) {
        newRight->children[i] = tmpChildren[i + tmpChildren.size()/2];
    }
    return newRight;

}

template <class T>
BNode<T> * BNode<T>::SplitWithSplitChild(BNode<T> * newRightChild, T newValue, T & median){
    BNode<T> * newRight = new BNode<T>(order);
    int indexOfNewValue = IndexOfNewValue(newValue);
    std::vector<T> tmpValues;
    std::vector<BNode<T> *> tmpChildren;
    for (int i = 0; i < values.size() + 1; ++i) {
        if (i == indexOfNewValue) {
            tmpValues.push_back(newValue);
        }
        else if (i > indexOfNewValue){
            tmpValues.push_back(values[i - 1]);
        }
        else tmpValues.push_back(values[i]);
    }
    for (int i = 0; i < children.size() + 1; ++i) {
        tmpChildren.push_back(nullptr);
    }
    for (int i = 0; i < children.size() + 1; ++i) {
        if (i == indexOfNewValue + 1) {
            tmpChildren[i] = newRightChild;
        }
        else if (i > indexOfNewValue + 1){
            tmpChildren[i] = children[i - 1];
        }
        else tmpChildren[i] = children[i];
    }
    values.clear();
    median = tmpValues[(2 * order + 1)/2];
    for (int i = 0; i < order; ++i) {
        values.push_back(tmpValues[i]);
    }
    for (int i = order + 1; i < 2 * order + 1; ++i) {
        newRight->values.push_back(tmpValues[i]);
    }
    EraseChildren();
    newRight->EraseChildren();
    for (int i = 0; i < tmpChildren.size()/2; ++i) {
        children[i] = tmpChildren[i];
    }
    for (int i = 0; i < tmpChildren.size()/2; ++i) {
        newRight->children[i] = tmpChildren[i + tmpChildren.size()/2];
    }
    return newRight;
}

template <class T>
void BNode<T>::PositionNewValue(T newValue){
    int index = IndexOfNewValue(newValue);
    std::vector<T> tmpValues = values;
    int valuesSize = (int)values.size();
    values.clear();
    for (int i = 0; i < valuesSize + 1; ++i) {
        if (i == index) {
            values.push_back(newValue);
        }
        else if (i > index){
            values.push_back(tmpValues[i - 1]);
        }
        else values.push_back(tmpValues[i]);
    }
    for (int i = (int)children.size() - 1; i > index + 1; i--) {
        children[i] = children[i - 1];
    }
    children[index + 1] = nullptr;
}

template <class T>
int BNode<T>::ChildFor(T value) const{
    int returner = - 1;
    int i = 0;
    while (value > values[i]) {
        if (i == values.size()) {
            if (children[i]) {
                returner = i;
            }
            break;
        }
        ++i;
    }
    if (children[i]) {
        returner = i;
    }
    return returner;
}

template <class T>
void BNode<T>::EraseChildren(){
    children.clear();
    for (int i = 0; i < 2 * order + 1; ++i) {
        children.push_back(nullptr);
    }
}

template <class T>
int BNode<T>::IndexOfNewValue(T newValue) const{
    int i = 0;
    if (values.size() == 0) {
        return i;
    }
    while (newValue > values[i] && i < values.size()) {
        if (i == values.size()) {
            return -1;
        }
        ++i;
    }
    return i;
}

template <class T>
int BNode<T>::IndexOfValueInNode(T value) const{
    int index = -1;
    for (int i = 0; i < values.size(); ++i) {
        if (values[i] == value) {
            index = i;
            break;
        }
    }
    return index;
}

template <class T>
T BNode<T>::FindReplacementForKeyAt(int index, bool & found, int & indexOfSubtreeWhereFound){
    found = false;
    indexOfSubtreeWhereFound = -1;
    if (children[index] || children[index + 1]) { //If there are potential children to look for value of replacement
        if (children[index]){ //There is a left child to look for value of replacement
            found = true;
            indexOfSubtreeWhereFound = index;
            return children[index]->GetGreatestValue();
        }
        else { //There is only right child to look for value of replacement
            found = true;
            indexOfSubtreeWhereFound = index + 1;
            return children[index + 1]->GetLeastValue();
        }
    }
    return T();
}

template <class T>
void BNode<T>::ShiftChildrenLeftFrom(int childIndex){
    for (int i = childIndex; i < children.size() - 1; ++i) {
        children[i] = children[i + 1];
    }
    children[children.size() - 1] = nullptr;
}

template <class T>
void BNode<T>::ShiftValuesLeftFrom(int index){
    
    if (values.size() == 0 || index >= values.size() - 1) {
        return;
    }
    for (int i = index; i < values.size() - 1; ++i) {
        values[i] = values[i + 1];
    }
    if (values.size() == 0) {
        return;
    }
    values.erase(values.end());
}

template <class T>
void BNode<T>::Rebalance(int indexOfUnbalancedChild){
    BNode<T> * unbalancedChild = children[indexOfUnbalancedChild];
    BNode<T> * leftSibling = GetLeftSibling(indexOfUnbalancedChild);
    BNode<T> * rightSibling = GetRightSibling(indexOfUnbalancedChild);
    int neededValuesForRebalancing = order - (int)unbalancedChild->values.size();
    
    if (leftSibling) {
        if (leftSibling->CanSpareNumberOfValues(neededValuesForRebalancing)) {
            for (int i = 0; i < neededValuesForRebalancing; ++i) {
                RotateRightAt(indexOfUnbalancedChild - 1);
            }
        }
        else {
            MergeSiblingsAt(indexOfUnbalancedChild - 1);
            children[indexOfUnbalancedChild] = nullptr;
        }
    }
    else {
        if (rightSibling) {
            if (rightSibling->CanSpareNumberOfValues(neededValuesForRebalancing)){
                for (int i = 0; i < neededValuesForRebalancing; ++i) {
                    RotateLeftAt(indexOfUnbalancedChild);
                }
            }
            else {
                MergeSiblingsAt(indexOfUnbalancedChild);
                children[indexOfUnbalancedChild + 1] = nullptr;
            }
        }
        else {
            PushValueIntoChildAtFromThis(indexOfUnbalancedChild);
            if (unbalancedChild->values.size() < order) {
                Rebalance(indexOfUnbalancedChild);
            }
        }
    }
}

template <class T>
T BNode<T>::GetLeastValue(){
    if (children[0]) {
        return (children[0])->GetLeastValue();
    }
    else return values[0];
}

template <class T>
T BNode<T>::GetGreatestValue(){
    if (children[values.size()]) {
        return children[values.size()]->GetGreatestValue();
    }
    else return values[values.size() - 1];
}

template <class T>
BNode<T> * BNode<T>::GetLeftSibling(int indexOfChild){
    if (indexOfChild == 0) {
        return nullptr;
    }
    else return children[indexOfChild - 1];
}

template <class T>
BNode<T> * BNode<T>::GetRightSibling(int indexOfChild){
    if (indexOfChild == children.size() - 1) {
        return nullptr;
    }
    else return children[indexOfChild + 1];
}

template <class T>
bool BNode<T>::CanSpareNumberOfValues(int numberOfValues){
    return (values.size() - order) >= numberOfValues;
}

template <class T>
void BNode<T>::RotateRightAt(int indexOfPivot){
    BNode<T> * rightChild = children[indexOfPivot + 1];
    BNode<T> * leftChild = children[indexOfPivot];
    
    //Insert value and child at rightchild
    rightChild->values.insert(rightChild->values.begin(), values[indexOfPivot]);
    rightChild->children.insert(rightChild->children.begin(), leftChild->children.at(leftChild->children.size() - 1));
    rightChild->children.erase(rightChild->children.begin() + rightChild->children.size() - 1);
    
    //Replace value of pivot
    values[indexOfPivot] = leftChild->values.at(leftChild->values.size() - 1);
    
    //Erase value and child at leftchild
    leftChild->values.erase(leftChild->values.begin() + leftChild->values.size() - 1);
    leftChild->children[leftChild->children.size() - 1] = nullptr;
}

template <class T>
void BNode<T>::RotateLeftAt(int indexOfPivot){
    BNode<T> * rightChild = children[indexOfPivot + 1];
    BNode<T> * leftChild = children[indexOfPivot];
    
    //Insert value and child at rightchild
    leftChild->values.insert(leftChild->values.end(), values[indexOfPivot]);
    leftChild->children[leftChild->values.size()] = rightChild->children.at(0);
    
    //Replace value of pivot
    values[indexOfPivot] = rightChild->values.at(0);
    
    //Erase value and child at leftchild
    rightChild->values.erase(rightChild->values.begin());
    rightChild->children.erase(rightChild->children.begin());
    rightChild->children.push_back(nullptr);
}

template <class T>
void BNode<T>::PushValueIntoChildAtFromThis(int indexOfChildToPush){
    BNode<T> * child = children[indexOfChildToPush];
    if (!GetLeftSibling(indexOfChildToPush) && indexOfChildToPush != 0) {
        child->values.insert(child->values.begin(), values[indexOfChildToPush-1]);
        child->children.insert(child->children.begin(), nullptr);
        child->children.erase(child->children.begin() + child->children.size() - 1);
        
        values.erase(values.begin() + indexOfChildToPush - 1);
        
        ShiftChildrenLeftFrom(indexOfChildToPush - 1);
        //ShiftValuesLeftFrom(indexOfChildToPush - 1);
    }
    else {
        child->values.insert(child->values.end(), values[indexOfChildToPush]);
        
        values.erase(values.begin() + indexOfChildToPush);
        
        ShiftChildrenLeftFrom(indexOfChildToPush + 1);
        //ShiftValuesLeftFrom(indexOfChildToPush + 1);
    }
}

template <class T>
void BNode<T>::MergeSiblingsAt(int index){
    BNode<T> * right = children[index + 1];
    int rightValuesSize = (int)right->values.size();
    for (int i = 0; i < rightValuesSize; ++i) {
        RotateLeftAt(index);
    }
}

template <class T>
void BNode<T>::Insert(T newValue, std::vector<void *> * results){
    if (IsLeaf()) {
        if (IsFull()) {
            T * median = new T();
            BNode<T> * newRight = Split(newValue, *median);
            int * splitted = new int();
            *splitted = 1;
            results->push_back(splitted);
            results->push_back(newRight);
            results->push_back(median);
        }
        else {
            PositionNewValue(newValue);
            int * splitted = new int();
            *splitted = 0;
            results->push_back(splitted);
        }
    }
    else {
        if (IsFull()) {
            int childPositionToInsertNewValue = ChildFor(newValue);
            if (childPositionToInsertNewValue != -1) { //There is a child where newvalue fits
                std::vector<void *> * obtainedResults = new std::vector<void *>();
                BNode<T> * childToInsertNewValue = children[childPositionToInsertNewValue];
                childToInsertNewValue->Insert(newValue, obtainedResults);
                int * childSplitted = (int *)(*obtainedResults)[0];
                if (*childSplitted) { //Child splitted
                    T * median = new T();
                    int * returnedMedian = (int *)(*obtainedResults)[2];
                    BNode<T> * newRight = SplitWithSplitChild((BNode<T> *)(*obtainedResults)[1], *returnedMedian, *median);
                    int * splitted = new int();
                    *splitted = 1;
                    results->push_back(splitted);
                    results->push_back(newRight);
                    results->push_back(median);
                }
                else {
                    int * splitted = new int();
                    *splitted = 0;
                    results->push_back(splitted);
                }
                //for (int i = 0; i < results.size(); ++i) delete results[i];
            }
            else {
                T * median = new T();
                BNode<T> * newRight = Split(newValue, *median);
                int * splitted = new int();
                *splitted = 1;
                results->push_back(splitted);
                results->push_back(newRight);
                results->push_back(median);
            }
        }
        else {
            int childPositionToInsertNewValue = ChildFor(newValue);
            if (childPositionToInsertNewValue != -1) { //There is a child where newvalue fits
                BNode<T> * childToInsertNewValue = children[childPositionToInsertNewValue];
                std::vector<void *> * obtainedResults = new std::vector<void *>();
                childToInsertNewValue->Insert(newValue, obtainedResults);
                int * childSplitted = (int *)(*obtainedResults)[0];
                if (*childSplitted) { //Child splitted
                    int * median = (int *)(*obtainedResults)[2];
                    int index = IndexOfNewValue(*median);
                    PositionNewValue(*median);
                    children[index + 1] = (BNode<T> *)(*obtainedResults)[1];
                }
                int * splitted = new int();
                *splitted = 0;
                results->push_back(splitted);
                //for (int i = 0; i < results.size(); ++i) delete results[i];
            }
            else {
                PositionNewValue(newValue);
                int * splitted = new int();
                *splitted = 0;
                results->push_back(splitted);
            }
        }
    }
}

template <class T>
void BNode<T>::Erase(T valueToErase, bool & underflowOcurred){
    int indexOfValueInNode = IndexOfValueInNode(valueToErase);
    if (indexOfValueInNode != -1) { //Value is contained in node
        if (IsLeaf()) { //Node is leaf and value is contained in node
            values.erase(values.begin() + indexOfValueInNode);
            underflowOcurred = values.size() < order;
            return;
        }
        else { //Node is not leaf and value is contained in node
            bool valueForReplacementFound = false;
            int indexOfSubtreeWhereFound = -1;
            T valueForReplacement = FindReplacementForKeyAt(indexOfValueInNode, valueForReplacementFound, indexOfSubtreeWhereFound);
            if (valueForReplacementFound) { //Replacement value was found and value is contained in node
                values[indexOfValueInNode] = valueForReplacement;
                bool underFlowInSubtreeOcurred = false;
                children[indexOfSubtreeWhereFound]->Erase(valueForReplacement, underFlowInSubtreeOcurred);
                if (underFlowInSubtreeOcurred) {
                    //Rebalance
                    Rebalance(indexOfSubtreeWhereFound);
                    underflowOcurred = values.size() < order;
                    return;
                }
                else {
                    underflowOcurred = false;
                    return;
                }
            }
            else { //Replacement value was not found and value is contained in node
                values.erase(values.begin() + indexOfValueInNode);
                ShiftChildrenLeftFrom(indexOfValueInNode);
                underflowOcurred = values.size() < order;
                return;
            }
        }
    }
    else { //Value to erase is not found in the current node
        if (IsLeaf()) { //There are no children to look for value to erase.
            underflowOcurred = false;
            return;
        }
        else {
            int indexOfChildToSearchForValue = IndexOfNewValue(valueToErase);
            if (indexOfChildToSearchForValue != -1 && children[indexOfChildToSearchForValue]) { //If there is child to search for value
                bool underflowInChildOcurred = false;
                children[indexOfChildToSearchForValue]->Erase(valueToErase, underflowInChildOcurred);
                if (underflowInChildOcurred) {
                    //Rebalance
                    Rebalance(indexOfChildToSearchForValue);
                    underflowOcurred = values.size() < order;
                    return;
                }
            }
            else {
                underflowOcurred = false;
                return;
            }
        }
    }
}

template <class T>
void BNode<T>::PrintAscending() const {
    for (int i = 0; i < values.size(); ++i) {
        if (children[i]) {
            children[i]->PrintAscending();
        }
        std::cout << values[i] << "\n";
    }
    if (children[values.size()]) {
        children[values.size()]->PrintAscending();
    }
}

template <class T>
void BNode<T>::PrintDescending() const {
    for (int i = (int)values.size(); 0 < i; --i) {
        if (children[i]) {
            children[i]->PrintDescending();
        }
        std::cout << values[i - 1] << "\n";
    }
    if (children[0]) {
        children[0]->PrintDescending();
    }
}

template <class T>
bool BNode<T>::Search(T value) const {
    int indexOfValueInNode = IndexOfValueInNode(value);
    if (indexOfValueInNode == -1) {
        int childFor = ChildFor(value);
        if (childFor == -1) {
            return false;
        }
        else return children[childFor]->Search(value);
    }
    else return true;
}

template <class T>
bool BNode<T>::IsLegal(bool isShallow) const {
    bool retVal = true;
    
    if (isShallow) {
        retVal = values.size() <= 2 * order;
    }
    else {
        retVal = order <= values.size() && values.size() <= 2 * order;
    }
    
    if (retVal) {
        for (int i = 0; i < (int)children.size(); ++i) {
            if (children[i]) {
                retVal = retVal && children[i]->IsLegal(false);
            }
        }
        return retVal;
    }
    else return retVal;
}

#endif
