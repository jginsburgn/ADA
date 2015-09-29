//
//  BTreeInDisk.h
//  BTreeInDisk
//
//  Created by Jonathan Ginsburg on 9/28/15.
//  Copyright © 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef BTreeInDisk_h
#define BTreeInDisk_h

#include "../../BTreeMemoryAttempt/BTreeMemoryAttempt/BTree.h"
#include "../../FileManager/FileManager/InDiskShell.h"
#include <map>

int WhereIs(int value, std::vector<std::string> vec){
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == Helper::intToString(value)) {
            return i;
        }
    }
    return -1;
}

template <class T>
class BTreeInDisk {
    
private:
    void BuildTreeFromMetadata();
    
protected:
    std::string treeName;
    std::string path;
    std::string fullPath;
    std::string metadataPath;
    std::vector<std::string> metadata;
    BTree<InDiskShell<T>> * tree = nullptr;
    std::map<T, int> valueIdentifier;
    
public:
    BTreeInDisk(const std::string newPath, const std::string newTreeName, const int newOrder = 2);
    void Insert(T newValue);
    void Erase(T value);
    void PrintAscending() const;
    void PrintDescending() const;
    bool Search(T value) const;
    bool IsEmpty() const;
    bool IsLegal() const;
    
};

template <class T>
void BTreeInDisk<T>::BuildTreeFromMetadata(){
    for (int i = 1; i < metadata.size(); ++i) {
        InDiskShell<T> newShell(fullPath, metadata[i]);
        tree->Insert(newShell);
        valueIdentifier.insert(std::pair<T,int>(newShell.GetInfo(), std::atoi(metadata[i].c_str())));
    }
}

template <class T>
BTreeInDisk<T>::BTreeInDisk(const std::string newPath, const std::string newTreeName, const int newOrder){
    path = newPath;
    treeName = newTreeName;
    fullPath = newPath;
    fullPath.append("/");
    fullPath.append(treeName);
    metadataPath = fullPath;
    metadataPath.append("/metadata");
    metadata = FileManager::loadSession(metadataPath);
    if (metadata.size() == 0) {
        metadata.push_back(Helper::intToString(newOrder));
        FileManager::saveSession(metadataPath, metadata);
        tree = new BTree<InDiskShell<T>>(newOrder);
    }
    else {
        tree = new BTree<InDiskShell<T>>(newOrder);
        BuildTreeFromMetadata();
    }
}

template <class T>
void BTreeInDisk<T>::Insert(T newValue){
    int newUniqueIdentifier = std::atoi(metadata[metadata.size() - 1].c_str()) + 1;
    if (metadata.size() - 1 == 0) {
        newUniqueIdentifier = 0;
    }
    metadata.push_back(Helper::intToString(newUniqueIdentifier));
    valueIdentifier.insert(std::pair<T,int>(newValue, newUniqueIdentifier));
    FileManager::saveSession(metadataPath, metadata);
    InDiskShell<T> newShell(fullPath, Helper::intToString(newUniqueIdentifier));
    newShell << newValue;
    tree->Insert(newShell);
}

template <class T>
void BTreeInDisk<T>::Erase(T value){
    int uniqueIdentifier = valueIdentifier[value];
    std::string fileToRemovePath = fullPath;
    fileToRemovePath.append("/");
    fileToRemovePath.append(Helper::intToString(uniqueIdentifier));
    FileManager::removeSavedSession(fileToRemovePath);
    metadata.erase(metadata.begin() + WhereIs(uniqueIdentifier, metadata));
    FileManager::saveSession(metadataPath, metadata);
    InDiskShell<T> tmpShell(fullPath, "tmpShell");
    tmpShell << value;
    tree->Erase(tmpShell);
}

template <class T>
void BTreeInDisk<T>::PrintAscending() const{
    tree->PrintAscending();
}

template <class T>
void BTreeInDisk<T>::PrintDescending() const{
    tree->PrintDescending();
}

template <class T>
bool BTreeInDisk<T>::Search(T value) const{
    InDiskShell<T> tmpShell(fullPath, "tmpShell");
    tmpShell << value;
    return tree->Search(tmpShell);
}

template <class T>
bool BTreeInDisk<T>::IsEmpty() const{
    return tree->IsEmpty();
}

template <class T>
bool BTreeInDisk<T>::IsLegal() const{
    return tree->IsLegal();
}

#endif /* BTreeInDisk_h */
