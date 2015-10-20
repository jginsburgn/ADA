//
//  main.cpp
//  TheHurriedTrucker
//
//  Created by Jonathan Ginsburg on 10/7/15.
//  Copyright © 2015 Jonathan Ginsburg. All rights reserved.
// Solved by Divide and Conquer

#include <iostream>
#include "../../Helper.h"

template <class T>
//Code fetched from: https://code.google.com/p/medicine-cpp/source/browse/trunk/cpp/sorting/SortingAlgorithms.cpp
void InsertionSort(std::vector<T> & data) {
    int length = (int)data.size();
    
    for (int i = 1; i < length; ++i)
    {
        bool inplace = true;
        int j = 0;
        for (; j < i; ++j)
        {
            if (data[i] < data[j])
            {
                inplace = false;
                break;
            }
        }
        
        if (!inplace)
        {
            int save = data[i];
            for (int k = i; k > j; --k)
            {
                data[k] = data[k-1];
            }
            data[j] = save;
        }
    }
}

std::vector<float> HurriedTruckStops(float reach, std::vector<float> highway){
    std::vector<float> answer;
    float currentPosition = 0;
    bool canReachNext = false;
    for (int i = 0; i < highway.size(); ++i) {
        if (highway[i] - currentPosition <= reach) {
            canReachNext = true;
        }
        else {
            if (canReachNext) {
                answer.push_back(highway[--i]);
                currentPosition = highway[i];
                canReachNext = false;
            }
            else throw "Truck cannot get to the end of the highway due to its reach.";
        }
    }
    return answer;
}
//Temporal complexity of HurriedTruckStops = O(n), with n = length of vector highway.

int main(int argc, const char * argv[]) {
    Helper::print("Welcome to The Hurried Trucker application. Jonathan Ginsburg (C) October 2015.");
    //Model the highway as a vector.
    std::vector<float> highway;
    //Get the length of highway.
    highway.push_back(Helper::read<float>("What is the length of the highway? "));
    float length = highway[0];
    //Fill data about gas stations
    while (true) {
        float input = Helper::read<float>("Enter a location of a gas station in the highway (0 to finish entering data): ");
        if (0 < input && input < length) {
            highway.push_back(input);
        }
        else{
            if (input == 0) {
                break;
            }
            else Helper::print("The location of a gas station must be inside the bounds of 0 and the length of the highway, exclusive.");
        }
    }
    //Order the highway vector in ascending order.
    InsertionSort<float>(highway);
    //Get the reach of the truck with full tank.
    float reach = Helper::read<float>("Enter the reach of the truck with full tank: ");
    //Get the gas stations where the truck must stop and show results.
    try {
        std::vector<float> answer = HurriedTruckStops(reach, highway);
        if (answer.size() == 0) {
            Helper::print("The truck can reach the end of the highway without visiting any gas stations.");
        }
        else std::cout << "The truck must visit the gas stations at positions: " << answer << std::endl;
    } catch (const char * exception) {
        Helper::print(exception);
    }
    return 0;
}
