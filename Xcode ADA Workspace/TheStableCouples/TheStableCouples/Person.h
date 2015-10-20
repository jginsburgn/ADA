//
//  Person.h
//  TheStableCouples
//
//  Created by Jonathan Ginsburg on 10/7/15.
//  Copyright © 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef Person_h
#define Person_h

#include <string>
#include <iostream>

enum Gender {Femenine, Masculine};

class Person {
private:
    std::string name;
    Gender gender;
    int uniqueIdentifier;
    
public:
    
    Person(std::string newName, Gender newGender, int newUniqueIdentifier) : name(newName), gender(newGender), uniqueIdentifier(newUniqueIdentifier) {};
    
    std::string GetName() const {return name;};
    void SetName(std::string newName) {name = newName;};
    Gender GetGender() const {return gender;};
    void SetGender(Gender newGender) {gender = newGender;};
    int GetUniqueIdentifier() const {return uniqueIdentifier;};
    void SetUniqueIdentifier(int newUniqueIdentifier) {uniqueIdentifier = newUniqueIdentifier;};
    bool operator == (const Person & person) const {
        return name == person.GetName() && gender == person.GetGender() && uniqueIdentifier == person.GetUniqueIdentifier();
    }
};

std::ostream & operator << (std::ostream & os, const Person & person){
    std::string gender = person.GetGender() == Masculine ? "Masculine" : "Femenine";
    os << "(" << person.GetUniqueIdentifier() << ", " << person.GetName() << ", " << gender << ")";
    return os;
}

#endif /* Person_h */
