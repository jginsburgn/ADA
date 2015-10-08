//
//  Couple.h
//  TheStableCouples
//
//  Created by Jonathan Ginsburg on 10/7/15.
//  Copyright © 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef Couple_h
#define Couple_h

#include "Person.h"

class Couple {
private:
    Person firstMember;
    Person secondMember;
public:
    
    Couple(Person newFirstMember, Person newSecondMember) : firstMember(newFirstMember), secondMember(newSecondMember) {};
    
    Person GetFirstMember() const {return firstMember;};
    void SetFirstMember(Person newFirstMember) {firstMember = newFirstMember;};
    Person GetSecondMember() const {return secondMember;};
    void SetSecondMember(Person newSecondMember) {secondMember = newSecondMember;};
    bool operator == (const Couple & couple) const {
        return firstMember == couple.GetFirstMember() && secondMember == couple.GetSecondMember();
    }
};

std::ostream & operator << (std::ostream & os, const Couple & couple){
    os << "(" << couple.GetFirstMember() << ", " << couple.GetSecondMember() << ")";
    return os;
}

#endif /* Couple_h */
