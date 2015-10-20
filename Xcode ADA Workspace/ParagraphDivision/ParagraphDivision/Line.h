//
//  Header.h
//  ParagraphDivision
//
//  Created by Jonathan Ginsburg on 10/8/15.
//  Copyright © 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef Line_h
#define Line_h

#include "../../Helper.h"

class Line {
private:
    float idealSpaceLength;
    std::vector<std::string> words;
    float length;
    bool triedToPushMore = false;
    float WordsLength() const {
        //words.size() = m
        float length = 0;
        for (int i = 0; i < words.size(); ++i) {
            length += words[i].length();
        }
        return length;
    }//m
    
    float ActualSpaceLength() const {
        return (length - WordsLength())/(words.size() - 1);
    }//m
    
public:
    Line(const float & newIdealSpaceLength, const float & newLength) : idealSpaceLength(newIdealSpaceLength), length(newLength) {};
    float Cost() const {
        if (!triedToPushMore) return 0;
        return words.size()*abs((long)(idealSpaceLength-ActualSpaceLength()));
    };//m
    bool PushWord(const std::string & word) {
        words.push_back(word);
        if (ActualSpaceLength() <= 0) {
            words.erase(words.begin() + Helper::getIndexOf<std::string>(word, words));
            triedToPushMore = true;
            return false;
        }
        return true;
    }//m
    std::vector<std::string> GetWords() const {return words;};
};

#endif /* Header_h */
