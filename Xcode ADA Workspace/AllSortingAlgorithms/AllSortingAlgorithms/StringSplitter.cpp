//
//  StringHelper.cpp
//  AllSortingAlgorithms
//
//  Created by Jonathan Ginsburg on 9/2/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <string>
#include <vector>
#include <sstream>

#ifndef StringSplitter_JGN
#define StringSplitter_JGN

std::vector<std::string> & split(const std::string &s, char delim, std::vector<std::string> & elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

#endif