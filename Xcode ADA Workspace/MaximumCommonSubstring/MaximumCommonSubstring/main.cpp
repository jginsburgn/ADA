//
//  main.cpp
//  MaximumCommonSubstring
//
//  Created by Jonathan Ginsburg on 10/8/15.
//  Copyright © 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include <string>
#include "../../Helper.h"

std::string MaximumCommonSubstring(const std::string & operandOne, const std::string & operandTwo) {
    //operandOne.length() = operandTwo.length() = m
    std::string substring = "";
    if (operandOne.length() <= operandTwo.length()) {
        for (int i = (int)operandOne.length(); i >= 0; --i) {//m
            for (int j = 0; j < operandOne.length(); ++j) {//m
                substring = operandOne.substr(j, i);
                std::size_t found = operandTwo.find(substring);
                if (found!=std::string::npos)
                    return substring;
            }
        }
    }
    else {
        for (int i = (int)operandTwo.length(); i >= 0; --i) {
            for (int j = 0; j < operandTwo.length(); ++j) {
                substring = operandTwo.substr(j, i);
                std::size_t found = operandOne.find(substring);
                if (found!=std::string::npos)
                    return substring;
            }
        }
    }
    return substring;
}//O(m^2)

int main(int argc, const char * argv[]) {
    std::string mcs =  MaximumCommonSubstring(Helper::readLine("Enter first string: "), Helper::readLine("Enter second string: "));
    if (mcs.length() == 0) {
        mcs = "The empty string (epsilon).";
    }
    else std::cout << "The maximum common substring found is: " << mcs << "." << std::endl;
    return 0;
}
