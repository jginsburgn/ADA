//
//  main.cpp
//  TheStableCouples
//
//  Created by Jonathan Ginsburg on 10/7/15.
//  Copyright © 2015 Jonathan Ginsburg. All rights reserved.
// Solved by backtracking

#include "../../Helper.h"
#include <iostream>
#include <vector>
#include "Couple.h"

std::vector<int> IndexesOfUncoupledMen(const std::vector<Person> & men, const std::vector<Couple> & couples) {
    //men.size() = m, couples.size() = n
    std::vector<int> indexesOfCoupledMen;
    for (int i = 0; i < couples.size(); ++i) {//n
        Person coupledMan = couples[i].GetFirstMember();
        indexesOfCoupledMen.push_back(Helper::getIndexOf<Person>(coupledMan, men)); //m
    }
    //mn
    std::vector<int> retVal;
    for (int i = 0; i < men.size(); ++i) {//m
        retVal.push_back(i);
    }
    retVal = Helper::vectorSubtraction<int>(retVal, indexesOfCoupledMen);//n
    return retVal;
}//O(mn)

std::vector<int> IndexesOfUncoupledWomen(const std::vector<Person> & women, const std::vector<Couple> & couples) {
    std::vector<int> indexesOfCoupledWomen;
    for (int i = 0; i < couples.size(); ++i) {
        Person coupledWoman = couples[i].GetSecondMember();
        indexesOfCoupledWomen.push_back(Helper::getIndexOf<Person>(coupledWoman, women));
    }
    std::vector<int> retVal;
    for (int i = 0; i < women.size(); ++i) {
        retVal.push_back(i);
    }
    retVal = Helper::vectorSubtraction<int>(retVal, indexesOfCoupledWomen);
    return retVal;
}//O(mn)

bool isFirstMorePreferredThanSecondByWoman(const Person & manOne, const Person & manTwo, const Person & woman, const std::vector<Person> & women, const std::vector<std::vector<Person>> & womensPreferences){
    //women.size() = m = womensPreferences.size()
    std::vector<Person> orderedPreferencesOfWoman;
    int indexOfWoman = Helper::getIndexOf<Person>(woman, women);//m
    for (int i = 0; i < womensPreferences.size(); ++i) {//m
        orderedPreferencesOfWoman.push_back(womensPreferences[indexOfWoman][i]);
    }
    return Helper::getIndexOf<Person>(manOne, orderedPreferencesOfWoman) < Helper::getIndexOf<Person>(manTwo, orderedPreferencesOfWoman);//m+m
}//O(m)

bool isFirstMorePreferredThanSecondByMan(const Person & womanOne, const Person & womanTwo, const Person & man, const std::vector<Person> & men, const std::vector<std::vector<Person>> & mensPreferences){
    std::vector<Person> orderedPreferencesOfMan;
    int indexOfMan = Helper::getIndexOf<Person>(man, men);
    for (int i = 0; i < mensPreferences.size(); ++i) {
        orderedPreferencesOfMan.push_back(mensPreferences[indexOfMan][i]);
    }
    return Helper::getIndexOf<Person>(womanOne, orderedPreferencesOfMan) < Helper::getIndexOf<Person>(womanTwo, orderedPreferencesOfMan);
}//O(m)

bool CoupleWouldLikeToSwitch(const Couple & coupleOne, const Couple & coupleTwo, const std::vector<Person> & men, const std::vector<Person> & women, const std::vector<std::vector<Person>> & mensPreferences, const std::vector<std::vector<Person>> & womensPreferences){
    //men.size() = women.size() = mensPreferences.size() = womensPreferences.size() = m
    Person manOne = coupleOne.GetFirstMember();
    Person womanOne = coupleOne.GetSecondMember();
    Person manTwo = coupleTwo.GetFirstMember();
    Person womanTwo = coupleTwo.GetSecondMember();
    if (isFirstMorePreferredThanSecondByMan(womanTwo, womanOne, manOne, men, mensPreferences)) {
        if (isFirstMorePreferredThanSecondByMan(womanOne, womanTwo, manTwo, men, mensPreferences)) {
            if (isFirstMorePreferredThanSecondByWoman(manTwo, manOne, womanOne, women, womensPreferences)) {
                if (isFirstMorePreferredThanSecondByWoman(manOne, manTwo, womanTwo, women, womensPreferences)) {
                    return true;
                }
            }
        }
    }
    return false;
}//O(m)

bool BreaksStability(const std::vector<Couple> & currentCouples, const Couple & newCouple, const std::vector<Person> & men, const std::vector<Person> & women, const std::vector<std::vector<Person>> & mensPreferences, const std::vector<std::vector<Person>> & womensPreferences) {
    // men.size() = women.size() = mensPreferences.size() = womensPreferences.size() = m, currentCouples.size() = n
    for (int i = 0; i < currentCouples.size(); ++i) {//m
        if (CoupleWouldLikeToSwitch(currentCouples[i], newCouple, men, women, mensPreferences, womensPreferences)) return true;//m
    }
    //m^2
    return false;
};//O(m^2)

std::vector<Couple> Branch(const std::vector<Person> & men, const std::vector<Person> & women, const std::vector<std::vector<Person>> & mensPreferences, const std::vector<std::vector<Person>> & womensPreferences, const std::vector<Couple> & currentAnswer, const Couple & newCouple, bool & solved) {
    //men.size() = women.size() = mensPreferences.size() = womensPreferences.size() = m, currentAnswer.size() = n
    solved = false;
    std::vector<Couple> retVal;
    if (BreaksStability(currentAnswer, newCouple, men, women, mensPreferences, womensPreferences)) {//m^2
        return retVal;
    }
    else {
        retVal = currentAnswer;
        retVal.push_back(newCouple);
        
        if (retVal.size() == men.size()) {
            solved = true;
            return retVal;
        }
        else {
            std::vector<int> indexesOfUncoupledMen = IndexesOfUncoupledMen(men, retVal);//m^2
            std::vector<int> indexesOfUncoupledWomen = IndexesOfUncoupledWomen(women, retVal);//m^2
            for (int i = 0; i < indexesOfUncoupledMen.size(); ++i) {//m
                for (int j = 0; j < indexesOfUncoupledWomen.size(); ++j) {//m
                    bool wasSubBranchSolved = false;
                    Couple newSubBranchCouple = Couple(men[indexesOfUncoupledMen[i]], women[indexesOfUncoupledWomen[j]]);
                    std::vector<Couple> potentialAnswer = Branch(men, women, mensPreferences, womensPreferences, retVal, newSubBranchCouple, wasSubBranchSolved);//m!
                    if (wasSubBranchSolved) {
                        solved = true;
                        return potentialAnswer;
                    }
                }
            }
            
        }
    }
    return retVal;
}//O(m!)

bool TheStableCouples(const std::vector<Person> & men, const std::vector<Person> & women, const std::vector<std::vector<Person>> & mensPreferences, const std::vector<std::vector<Person>> & womensPreferences, std::vector<Couple> & answer){
    bool solved = false;
    for (int i = 0; i < men.size(); ++i) {//m
        for (int j = 0; j < women.size(); ++j) {//m
            answer = Branch(men, women, mensPreferences, womensPreferences, std::vector<Couple>(), Couple(men[i], women[j]), solved);//m!
            if (solved) break;
        }
        if (solved) break;
    }
    return solved;
}//O(m!)

int main(int argc, const char * argv[]) {
    Helper::print("Welcome to The Stable Couples Application. Jonathan Ginsburg (C). October 7, 2015.");
    int numberOfCouples = Helper::read<int>("Enter the number of couples you want to build: ");
    std::vector<Person> men;
    for (int i = 0; i < numberOfCouples; ++i) {
        std::cout << "Let's get info of man number " << i + 1 << std::endl;
        men.push_back(Person(Helper::readLine("Enter name of man: "), Masculine, i));
    }
    std::vector<Person> women;
    for (int i = 0; i < numberOfCouples; ++i) {
        std::cout << "Let's get info of woman number " << i + 1 << std::endl;
        women.push_back(Person(Helper::readLine("Enter name of woman: "), Femenine, i + numberOfCouples));
    }
    std::vector<std::vector<Person>> mensPreferences;
    for (int i = 0; i < numberOfCouples; ++i) {
        std::vector<Person> tmp;
        std::cout << "Please enter preferences for " << men[i] << " in ascending order:" << std::endl;
        for (int j = 0; j < numberOfCouples; ++j) {
            std::cout << j + 1 << " for " << women[j] << "." << std::endl;
        }
        for (int j = 0; j < numberOfCouples; ++j) {
            int indexOfWoman = Helper::read<int>(">> ");
            tmp.push_back(women[indexOfWoman]);
        }
        mensPreferences.push_back(tmp);
    }
    std::vector<std::vector<Person>> womensPreferences;
    for (int i = 0; i < numberOfCouples; ++i) {
        std::vector<Person> tmp;
        std::cout << "Please enter preferences for " << women[i] << " in ascending order:" << std::endl;
        for (int j = 0; j < numberOfCouples; ++j) {
            std::cout << j + 1 << " for " << men[j] << "." << std::endl;
        }
        for (int j = 0; j < numberOfCouples; ++j) {
            int indexOfMan = Helper::read<int>(">> ");
            tmp.push_back(men[indexOfMan]);
        }
        womensPreferences.push_back(tmp);
    }
    std::vector<Couple> answer;
    if (TheStableCouples(men, women, mensPreferences, womensPreferences, answer)) std::cout << "One possible answer is as follows: " << answer << std::endl;
    else Helper::print("No answer found.");
    return 0;
}
