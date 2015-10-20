//
//  main.cpp
//  FileManager
//
//  Created by Jonathan Ginsburg on 9/28/15.
//  Copyright © 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <time.h>
#include "InDiskShell.h"

int main(int argc, const char * argv[]) {
    Helper::print("Welcome to the mini tester for the InDiskShell class. Jonathan Ginsburg (C) September 2015.");
    std::string path = Helper::readLine("Enter path: ");
    std::string fileName = Helper::readLine("Enter file name: ");
    InDiskShell<std::string> shell(path, fileName);
    shell << Helper::readLine("Enter the string to save: ");
    return 0;
}
