//
//  main.cpp
//  BubbleSort
//
//  Created by Jonathan Ginsburg on 8/10/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

void bubbleSort(std::vector<int> & list);

int main(int argc, const char * argv[]) {
    
    if (argc == 1) {
        std::cout << "Please enter \"BubbleSort <arg1>\", where <arg1> is the number of elements to sort. Try using \"time BubbleSort <arg1>\", for measuring the time of the sorting algorithm for the <arg1> number of elements to sort." << std::endl;
        return 0;
    }
    
    srand((int)time(NULL));
    std::vector<int> list;
    int listSize = atoi(argv[argc-1]);

    for (int i = 0; i < listSize; ++i) {
        list.push_back(rand() % 100001);
    }
    
//    for (int i = 0; i < listSize; ++i) {
//        std::cout << list.at(i) << std::endl;
//    }
    
    bubbleSort(list);
    
//    for (int i = 0; i < listSize; ++i) {
//        std::cout << list.at(i) << std::endl;
//    }
    
    return 0;
}

void bubbleSort(std::vector<int> & list){
    auto swap = [](std::vector<int> & listToSwap, int index){
        int temp = listToSwap.at(index-1);
        listToSwap.at(index-1) = listToSwap.at(index);
        listToSwap.at(index) = temp;
    };
    int n = (int)list.size();
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 1; i <= n-1; ++i) {
            if (list.at(i-1) > list.at(i)) {
                swap(list, i);
                swapped = true;
            }
        }
    }
}

/*
procedure bubbleSort( A : list of sortable items )
 n = length(A)
 repeat
    swapped = false
    for i = 1 to n-1 inclusive do
    #if this pair is out of order
        if A[i-1] > A[i] then
            #swap them and remember something changed
            swap( A[i-1], A[i] )
            swapped = true
        end if
    end for
 until not swapped
end procedure
Consulted from: https://en.wikipedia.org/wiki/Bubble_sort
*/