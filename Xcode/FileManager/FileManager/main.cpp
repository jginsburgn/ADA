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
//    std::string filepath;
//    std::cin >> filepath;
//    std::string lineone;
//    std::cin >> lineone;
//    std::vector<std::string> vec;
//    vec.push_back(lineone);
//    FileManager::saveSession(filepath, vec);
    std::string path = Helper::readLine("Enter path:");
    std::string fileName = Helper::readLine("Enter file name:");
    
    InDiskShell<int> shell(path, fileName);
    std::cout << shell.GetInfo() << std::endl;
    shell << Helper::read<int>("Enter the number to save");
    
    return 0;
}
