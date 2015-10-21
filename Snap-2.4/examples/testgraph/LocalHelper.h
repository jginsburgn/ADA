//
//  LocalHelper.h
//  snap-examples
//
//  Created by Jonathan Ginsburg on 10/21/15.
//  Copyright © 2015 infolab. All rights reserved.
//

#ifndef LocalHelper_h

#include <string>
#include <time.h>

//Local Helper Implementation
const std::string EMPTY_STRING = "";
time_t begin, end;

void Print(const std::string & message, bool addLineBreak = false){
    std::string processedMessage = message;
    if (addLineBreak) processedMessage.append("\n");
    printf(processedMessage.c_str());
}
std::string ReadWord(const std::string & prompt) {
    if (prompt != "") {
        Print(prompt);
    }
    char input[100];
    scanf("%99s", input);
    std::string retVal(input);
    return retVal;
}
int ReadInt(const std::string & prompt) {
    if (prompt != "") {
        Print(prompt);
    }
    int retVal = 0;
    scanf("%i", &retVal);
    return retVal;
}

void StartChronometer(){
    begin = time(NULL);
}

std::string DoubleToString(double value) {
    char buffer[32];
    snprintf(buffer,32,"%f",value);
    std::string retVal = buffer;
    return retVal;
}

std::string IntToString(int value){
    char buffer[32];
    snprintf(buffer,32,"%i",value);
    std::string retVal = buffer;
    return retVal;
}

std::string ChronometerLap(){
    //    printf ("It took me %d clicks (%f seconds).\n", t, ((float)t)/CLOCKS_PER_SEC);
    //    double num = ((float)t)/CLOCKS_PER_SEC;
    //    char output[50];
    //    snprintf(output,50,"%d",num);
    //    std::string retVal = output;
    end = time(NULL);
    double elapsedTime = difftime(end, begin);
    std::string retVal = DoubleToString(elapsedTime);
    return retVal;
}

//End of Local Helper

#define LocalHelper_h


#endif /* LocalHelper_h */
