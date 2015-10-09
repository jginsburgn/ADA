//
//  main.cpp
//  ParagraphDivision
//
//  Created by Jonathan Ginsburg on 10/8/15.
//  Copyright © 2015 Jonathan Ginsburg. All rights reserved.
//

#include "Line.h"
#include <iostream>
#include <math.h>

std::vector<Line> ParagraphDivision (const std::vector<std::string> & words, const float & lineLenght, const float & idealSpaceLength) {
    //words.size() = m
    std::vector<Line> retVal;
    for (int i = 0; i < words.size(); ++i) {//m
        if (retVal.size() == 0) {
            retVal.push_back(Line(idealSpaceLength, lineLenght));
            retVal[retVal.size() - 1].PushWord(words[i]);//m - n
        }
        else if (!retVal[retVal.size()].PushWord(words[i])){
            retVal.push_back(Line(idealSpaceLength, lineLenght));
            retVal[retVal.size() - 1].PushWord(words[i]);//m - n
        }
    }
    return retVal;
}//O(m^2)

int main(int argc, const char * argv[]) {
    Helper::print("Welcome to the Paragraph Division Application. Jonathan Ginsburg (C). October 8, 2015.");
    std::vector<std::string> words;
    while (true) {
        std::string input = Helper::readLine("Enter word (Finalize for finishing word entering): ");
        if (input == "Finalize") {
            break;
        }
        else words.push_back(input);
    }
    std::vector<Line> answer = ParagraphDivision(words, Helper::read<float>("Enter the length of the lines (remember that this cannot be less than the size of the biggest entered word): "), Helper::read<float>("Enter the ideal length of spaces between words: "));
    std::cout << "The answer is as follows: " << std::endl;
    for (int i = 0; i < answer.size(); ++i) {
        Line line = answer[i];
        std::cout << "The following words must go in line " << i + 1 << ": " << line.GetWords() << std::endl;
        std::cout << "The cost of line " << i + 1 << " is: " << line.Cost() << std::endl;
    }
    return 0;
}
