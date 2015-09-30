//
//  InDiskShell.h
//  FileManager
//
//  Created by Jonathan Ginsburg on 9/28/15.
//  Copyright © 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef InDiskShell_h
#define InDiskShell_h

#include <string>
#include "FileManager.h"
#include "../../Helper.h"

std::string BuildFromSavableRepresentation(std::string savableRepresentation){
    return savableRepresentation;
}

std::string GetSavableRepresentation(std::string & info){
    return info;
}

template <class T>
class InDiskShell {
    
private:
    std::string path;
    std::string fileName;
    
    T * info = new T();
    
    std::string FullPath() const;
    
public:
    
    InDiskShell();
    InDiskShell(std::string newPath, std::string newFileName);
    ~InDiskShell();
    T GetInfo() const;
    T & GetEditableInfo();
    void operator<<(const T & newInfo);
    bool operator<(const InDiskShell & shell) const;
    bool operator==(const InDiskShell & shell) const;
    bool operator>(const InDiskShell & shell) const;
    void Save();
    void Load();
};

template <class T>
std::string InDiskShell<T>::FullPath() const {
    std::string fullPath = path;
    fullPath.append("/");
    fullPath.append(fileName);
    return fullPath;
}

template <class T>
InDiskShell<T>::InDiskShell() {
    path = ".";
    fileName = "emptyfilename";
    info = new T();
}

template <class T>
InDiskShell<T>::InDiskShell(std::string newPath, std::string newFileName) {
    path = newPath;
    fileName = newFileName;
    info = new T();
    Load();
}

template <class T>
InDiskShell<T>::~InDiskShell(){
    Save();
}

template <class T>
T InDiskShell<T>::GetInfo() const{
    return *info;
}

template <class T>
T & InDiskShell<T>::GetEditableInfo(){
    return *info;
}

template <class T>
void InDiskShell<T>::operator<<(const T & newInfo){
    *info = newInfo;
    Save();
}

template <class T>
bool InDiskShell<T>::operator<(const InDiskShell & shell) const{
    return GetInfo() < shell.GetInfo();
}

template <class T>
bool InDiskShell<T>::operator==(const InDiskShell & shell) const{
    return GetInfo() == shell.GetInfo();
}

template <class T>
bool InDiskShell<T>::operator>(const InDiskShell & shell) const{
    return GetInfo() > shell.GetInfo();
}

template <class T>
std::ostream & operator<<(std::ostream & os, const InDiskShell<T> & shell){
    os << shell.GetInfo();
    return os;
}

template <class T>
void InDiskShell<T>::Save(){
    std::vector<std::string> infoVector;
    infoVector.push_back(GetSavableRepresentation(*info));
    FileManager::saveSession(FullPath(), infoVector);
}

template <class T>
void InDiskShell<T>::Load(){
    std::vector<std::string> infoVector = FileManager::loadSession(FullPath());
    if (infoVector.size() != 1) {
        //File is corrupted
        FileManager::removeSavedSession(FullPath());
    }
    else {
        T newInfo = BuildFromSavableRepresentation(infoVector[0]);
        *info = newInfo;
    }
}

#endif /* InDiskShell_h */
