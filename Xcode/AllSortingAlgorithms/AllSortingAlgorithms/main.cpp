#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <unistd.h>
#include "StringSplitter.cpp"

/*
 1. Ordenamiento de burbuja (Bubble Sort)
 2. Ordenamiento de burbuja bidireccional (Cocktail Sort)
 3. Ordenamiento por inserción (Insertion Sort)
 4. Ordenamiento por casilleros (Bucket Sort)
 5. Ordenamiento por cuentas (Counting Sort)
 6. Ordenamiento por mezcla (Merge Sort)
 7. Ordenamiento con árbol binario(Binary tree Sort)
 8. Ordenamiento Radix (Radix Sort)
 9. Ordenamiento Shell (Shell Sort)
 10. Ordenamiento por selección (Selection Sort)
 11. Ordenamiento por montículos (Heap Sort)
 12. Ordenamiento rápido (Quick Sort)
 13. Ordenamiento de ladrillos (Brick Sort)
 14. Ordenamiento por sacudidas (Shaker Sort)
 */

const int topBound = 10000; //greater number in random array
const int lowBound = 1; //least number in random array

std::ostream & operator << (std::ostream & os, const std::vector<int> & vector) {
    if (vector.size() == 0) { return os; }
    for (int i = 0; i < vector.size() - 1; ++i) {
        os << std::to_string(vector[i]) << ", ";
    }
    os << std::to_string(vector[vector.size()-1]) << ".";
    return os;
}

namespace SortingAlgorithms {
    //Code fetched from: https://code.google.com/p/medicine-cpp/source/browse/trunk/cpp/sorting/SortingAlgorithms.cpp
    void BubbleSort(std::vector<int> & data) {
        auto swap = [](std::vector<int> & data, int i, int j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        };
        
        int length = (int)data.size();
        
        for (int i = 0; i < length; ++i)
        {
            bool swapped = false;
            for (int j = 0; j < length - (i+1); ++j)
            {
                if (data[j] > data[j+1])
                {
                    swap(data, j, j+1);
                    swapped = true;
                }
            }
            
            if (!swapped) break;
        }
    }
    
    //Code fetched from: http://www.programering.com/a/MTMzkzNwATQ.html
    void CocktailSort(std::vector<int> & data) {
        int size = (int)data.size();
        int i, bottom = 0;
        int top = size - 1;
        bool swapped = true;
        auto swap = [](int *a, int *b) {
            int t;
            t = *a;
            *a = *b;
            *b = t;
        };
        while(swapped)    //If there is no element of the exchange, the array orderly
        {
            swapped = false;
            for(i = bottom; i <top; i++)
            {
                if(data[i] > data[i + 1])      //To judge whether the correct order of two elements
                {
                    swap(&data[i], &data[i + 1]);     //Let the two element of the exchange order
                    swapped = true;
                }
            }
            // The largest part of the exchange of unsorted elements to the top
            top = top - 1;
            for(i = top; i > bottom; i--)
            {
                if(data[i] < data[i - 1])
                {
                    swap(&data[i], &data[i - 1]);
                    swapped = true;
                }
            }
            //Will not sort the smallest element part of the exchange to the end
            bottom = bottom + 1;
        }
    }
    
    //Code fetched from: https://code.google.com/p/medicine-cpp/source/browse/trunk/cpp/sorting/SortingAlgorithms.cpp
    void InsertionSort(std::vector<int> & data) {
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
    
    //Code fetched form: http://www.sourcetricks.com/2013/03/bucket-sort.html#.VePkoNNViko
    void BucketSort(std::vector<int> & data) {
        using namespace std;
        auto hashF = [](int n) {
            return n/5;
        };
        auto doinsertionsortforbucket = [](std::vector<int> & data, int len){
            while( len-- > 0) {
                if (data[len] > data[len+1]) {
                    int tmp = data[len];
                    data[len] = data[len+1];
                    data[len+1] = tmp;
                } else
                    return;
            }
        };
        const int INPUT_SIZE = (int)data.size();
        const int BUCKET_K = topBound;
        queue<int> *buckets[BUCKET_K];
        for ( int i = 0; i < BUCKET_K; i++ )
            buckets[i] = new queue<int>;
        
        // Hash the input and insert the content into appropriate bucket based on hash.
        for (int i=0;i<INPUT_SIZE;i++)
        {
            int hashValue = hashF(data[i]);
            if (hashValue >= BUCKET_K)
                hashValue = BUCKET_K-1;
            
            buckets[hashValue]->push(data[i]);
        }
        
        // extract the content from each of the buckets in order.
        // using insertion sort
        int outputidx = 0;
        for ( int i = 0; i < BUCKET_K; i++ )
        {
            if (buckets[i]->size() == 1) {
                data[outputidx++] = buckets[i]->front();
                buckets[i]->pop();
            }
            if (buckets[i]->size() > 1)
            {
                while (!buckets[i]->empty())
                {
                    data[outputidx] = buckets[i]->front();
                    doinsertionsortforbucket(data, outputidx);
                    buckets[i]->pop();
                    outputidx++;
                }
            }
        }
        // clear buckets.
        for ( int i = 0; i < BUCKET_K; i++ )
            delete buckets[i];
        
    }
    
    //Code fetched from: http://www.sourcetricks.com/2013/03/counting-sort.html#.VePpYNNViko
    void CountingSort(std::vector<int> & data) {
        const int INPUT_SIZE = (int)data.size();
        
        const int BUCKET_K = topBound + 1;
        int CountArr[BUCKET_K] = { 0 };
        
        for (int i=0;i<INPUT_SIZE;i++)
        {
            CountArr[data[i]]++;
        }
        
        int outputindex=0;
        for (int j=0;j<BUCKET_K;j++)
        {
            while (CountArr[j]--)
                data[outputindex++] = j;
        }
    }
    
    //Code fetched from: https://code.google.com/p/medicine-cpp/source/browse/trunk/cpp/sorting/SortingAlgorithms.cpp
    void MergeSort(std::vector<int> & data, int low = -1, int high = -1, void Merge(std::vector<int> & data, int lowl, int highl, int lowr, int highr) = 0) {
        if (high == -1 || low == -1) {
            Merge = [](std::vector<int> & data, int lowl, int highl, int lowr, int highr){
                int tmp_low = lowl;
                std::vector<int> tmp;
                
                while (lowl <= highl && lowr <= highr)
                {
                    if (data[lowl] < data[lowr])
                    {
                        tmp.push_back(data[lowl++]);
                    }
                    else if (data[lowr] < data[lowl])
                    {
                        tmp.push_back(data[lowr++]);
                    }
                    else
                    {
                        tmp.push_back(data[lowl++]);
                        tmp.push_back(data[lowr++]);
                    }
                }
                
                while (lowl <= highl)
                {
                    tmp.push_back(data[lowl++]);
                }
                
                while (lowr <= highr)
                {
                    tmp.push_back(data[lowr++]);
                }
                
                std::vector<int>::const_iterator iter = tmp.begin();
                
                for(; iter != tmp.end(); ++iter)
                {
                    data[tmp_low++] = *iter;
                }
            };
            high = (int)data.size()-1;
            low = 0;
        }
        
        if (low >= high)
        {
            return;
        }
        
        int mid = low + (high-low)/2;
        
        MergeSort(data, low, mid, Merge);
        
        MergeSort(data, mid+1, high, Merge);
        
        Merge(data, low, mid, mid+1, high);
    }
    
    //Code fetched from: https://en.wikipedia.org/wiki/Tree_sort
    class BinaryTreeSort {
    public:
        class OBT{
        public:
            int * value = nullptr;
            OBT * left = nullptr;
            OBT * right = nullptr;
            
            ~OBT(){
                if (value) {
                    delete value;
                }
                if (left) {
                    delete left;
                }
                if (right) {
                    delete right;
                }
                
            }
            
            void Insert(int newValue){
                if (!value) {
                    value = new int;
                    *value = newValue;
                }
                else if (newValue < *value){
                    if (left) {
                        (*left).Insert(newValue);
                    }
                    else{
                        left = new OBT();
                        left->Insert(newValue);
                    }
                }
                else{
                    if (right) {
                        (*right).Insert(newValue);
                    }
                    else{
                        right = new OBT();
                        right->Insert(newValue);
                    }
                }
            }
            
            void Sort(std::vector<int> & data){
                if (!value) {
                    return;
                }
                else{
                    if (left) left->Sort(data);
                    data.push_back(*value);
                    if (right) right->Sort(data);
                }
            }
        };
    };
    void BinaryTreeSort(std::vector<int> & data){
        BinaryTreeSort::OBT sortingTree;
        for (int i = 0; i < data.size(); ++i) {
            sortingTree.Insert(data[i]);
        }
        data.clear();
        sortingTree.Sort(data);
    }
    
    //Code fetched from: https://code.google.com/p/medicine-cpp/source/browse/trunk/cpp/sorting/SortingAlgorithms.cpp
    void RadixSort(std::vector<int> & data) {
        auto findMaxDigits = [](std::vector<int> & data){
            auto numDigits = [](int n){
                int count = 0;
                while(n != 0)
                {
                    n = n/10;
                    ++count;
                }
                
                return count;
            };
            std::vector<int>::const_iterator iter = data.begin();
            int max = 0;
            for (; iter != data.end(); ++iter)
            {
                int numd = numDigits(*iter);
                if (max < numd)
                {
                    max = numd;
                }
            }
            
            return max;
        };
        auto GetPartialSorted = [](std::queue<int>  q[], int qcount, std::vector<int> & data){
            for (int i = 0; i < qcount; ++i)
            {
                if (q[i].size() > 0)
                {
                    int length = (int)q[i].size();
                    while (length--)
                    {
                        data.push_back(q[i].front());
                        q[i].pop();
                    }
                }
            }
        };
        auto PutInQueues = [](std::queue<int>  q[], int qcount, std::vector<int> & data, int digit){
            auto getDigitAt = [](int n, int digit){
                int dig = 0;
                while (digit--)
                {
                    dig = n % 10;
                    n = n / 10;
                }
                return dig;
            };
            std::vector<int>::const_iterator iter = data.begin();
            for(; iter != data.end(); ++iter)
            {
                int qpos = getDigitAt(*iter, digit);
                q[qpos].push(*iter);
            }
        };
        std::queue<int> q[10];
        int maxDigits = findMaxDigits(data);
        
        for (int i = 0; i < maxDigits; ++i)
        {
            PutInQueues(q, 10, data, i+1);
            data.clear();
            GetPartialSorted(q, 10, data);
        }
    }
    
    //Code fetched from: http://www.cplusplus.com/forum/general/123961/
    void ShellSort(std::vector<int> & data){
        int gap, i, j, temp;
        int n = (int)data.size();
        for (gap = n/2; gap > 0; gap /= 2){
            for (i = gap; i < n; i++){
                for (j = i - gap; j >= 0 && data[j] > data[j + gap]; j -= gap) {
                    temp = data[j];
                    data[j] = data[j+gap];
                    data[j+gap] = temp;
                }
            }
        }
    }
    
    //Code fetched from: http://cforbeginners.com/ssort.html
    void SelectionSort(std::vector<int> & data){
        //pos_min is short for position of min
        int pos_min,temp;
        int n = (int)data.size();
        for (int i=0; i < n-1; i++)
        {
            pos_min = i;//set pos_min to the current index of array
            for (int j=i+1; j < n; j++){
                if (data[j] < data[pos_min])
                    pos_min=j;
                //pos_min will keep track of the index that min is in, this is needed when a swap happens
            }
            //if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
            if (pos_min != i){
                temp = data[i];
                data[i] = data[pos_min];
                data[pos_min] = temp;
            }
        }
    }
    
    //Code fetched from: http://www.coders-hub.com/2015/02/heap-sort-using-c.html#.VeaLANNViko
    void MAX_HEAPIFY(std::vector<int> & data, int i, int n){
        int l,r,largest,loc;
        l=2*i;
        r=(2*i+1);
        if((l<=n)&&data[l]>data[i])
            largest=l;
        else
            largest=i;
        if((r<=n)&&(data[r]>data[largest]))
            largest=r;
        if(largest!=i){
            loc=data[i];
            data[i]=data[largest];
            data[largest]=loc;
            MAX_HEAPIFY(data, largest, n);
        }
    }
    void BUILD_MAX_HEAP(std::vector<int> & data){
        int n = (int)data.size();
        for(int k = n/2; k >= 1; k--){
            MAX_HEAPIFY(data, k, n);
        }
    };
    void HeapSort(std::vector<int> & data){
        BUILD_MAX_HEAP(data);
        int n = (int)data.size();
        int i, temp;
        for (i = n; i >= 2; i--)
        {
            temp = data[i];
            data[i] = data[1];
            data[1] = temp;
            MAX_HEAPIFY(data, 1, i - 1);
        }
    }
    
    //Code fetched from: https://code.google.com/p/medicine-cpp/source/browse/trunk/cpp/sorting/SortingAlgorithms.cpp
    int Partition(std::vector<int> & data, int low, int high){
        auto swap = [](std::vector<int> & data, int i, int j) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        };
        int p = low;
        for (int i = p+1; i <= high; ++i)
        {
            if (data[i] < data[p])
            {
                swap(data, i, p);
                if (i != p+1)
                {
                    swap(data, i, p+1);
                }
                p = p + 1;
            }
        }
        return p;
    };
    void QuickSort(std::vector<int> & data, int low, int high){
        if (low >= high) return;
        int p = Partition(data, low, high);
        QuickSort(data, low, p-1);
        QuickSort(data, p+1, high);
    }
    
    //Code fetched from: http://algorithmsolver.blogspot.mx/2012/01/brick-sort.html
    void BrickSort(std::vector<int> & data) {
        auto swap = [](std::vector<int> & data, int i, int j){
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        };
        
        int n = (int)data.size();
        bool sorted = false;
        while(!sorted)
        {
            sorted=true;
            for (int i = 1; i < n-1; i += 2) {
                if(data[i] > data[i+1]) {
                    swap(data, i, i + 1);
                    sorted=false;
                }
            }
            for (int i = 0; i < n-1; i += 2) {
                if(data[i] > data[i + 1]) {
                    swap(data, i, i + 1);
                    sorted = false;
                }
            }
        }
    }
    
    //Code fetched from: http://www.mhhe.com/engcs/compsci/sahni/enrich/c2/SHAKER.HTM
    void ShakerSort(std::vector<int> & data) {
        int n = (int)data.size();
        // Sort a[0:n-1] using the shaker sort method.
        for (int p = 1; p <= n/2; p++) {
            // phase p of shaker sort
            // first do left to right bubbling pass
            for (int i = p-1; i < n-p; i++)
                if (data[i] > data[i+1]){
                    int temp = data[i];
                    data[i] = data[i+1];
                    data[i+1] = temp;
                }
            
            // now do right to left bubbling pass
            for (int i = n-p-1; i >= p; i--)
                if (data[i] < data[i-1]){
                    int temp = data[i];
                    data[i] = data[i-1];
                    data[i-1] = temp;
                }
        }
    }
}

//Fills vector with random numbers in range [1, 10000]
void FillIntVector(std::vector<int> & vector, const int size) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < size; ++i) vector.push_back((rand() % topBound) + lowBound);
}

int WhereIs(const char * array[], const int size, const char * string){
    for (int i = 0; i < size; ++i) {
        if (strcmp(array[i], string) == 0) {
            return i;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    using namespace std;
    using namespace chrono;
    
    int numberOfElements = 10;
    int numberOfRepetitions = 1;
    
    cout << endl << "Sorting Algorithm Meter 1.0 by Jonathan Ginsburg. (c) September 2, 2015. All rights reserved." << endl;
    
    if (argc == 1) {
        cout << "Type <<AllSortingAlgorithms help>>" << endl;
        
        cout << endl;
        return 0;
    }
    else {
        if (WhereIs(argv, argc, "help") != -1) {
            cout << "This is a tool for executing sorting algorithms over an int vector in C++ and measuring the executing times. Use any of the following commands:" << endl;
            cout << "\t1. AllSortingAlgorithms <arg1>, where <arg1> is the number of elements in the array to sort." << endl;
            cout << "\t2. AllSortingAlgorithms <arg1> <arg2>, where <arg1> is the number of elements in the array to sort and <arg2> is the number of measurements to make" << endl;
            
            cout << endl;
            return 0;
        }
        else if (argc == 2){
            if (atoi(argv[1]) >= 0) {
                numberOfElements = atoi(argv[1]);
            }
            else {
                cout << endl;
                return 0;
            }
        }
        else if (argc == 3){
            if (atoi(argv[1]) >= 0 && atoi(argv[2]) > 0) {
                numberOfElements = atoi(argv[1]);
                numberOfRepetitions = atoi(argv[2]);
            }
            else {
                cout << endl;
                return 0;
            }
        }
    }
    
    cout << endl;
    
    using namespace SortingAlgorithms;
    
    cout << "Number of elements in array = " << numberOfElements << ". Number of measurements to make = " << numberOfRepetitions << ":" << endl << endl;
    
    for (int i = 0; i < numberOfRepetitions; ++i) {
        vector<int> data;
        FillIntVector(data, numberOfElements);
        vector<int> copy = data;
        
        cout << "\tExecuting Bubble Sort:";
        high_resolution_clock::time_point begin = high_resolution_clock::now();
        BubbleSort(copy);
        high_resolution_clock::time_point end = high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << " " << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        copy = data;
        cout << "\tExecuting Cocktail Sort:";
        begin = high_resolution_clock::now();
        CocktailSort(copy);
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << " " << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        copy = data;
        cout << "\tExecuting Insertion Sort:";
        begin = high_resolution_clock::now();
        InsertionSort(copy);
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << " " << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        copy = data;
        cout << "\tExecuting Bucket Sort:";
        begin = high_resolution_clock::now();
        BucketSort(copy);
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << " " << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        copy = data;
        cout << "\tExecuting Counting Sort:";
        begin = high_resolution_clock::now();
        CountingSort(copy);
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << " " << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        copy = data;
        cout << "\tExecuting Merge Sort:";
        begin = high_resolution_clock::now();
        MergeSort(copy);
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << " " << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        copy = data;
        cout << "\tExecuting Binary Tree Sort:";
        begin = high_resolution_clock::now();
        BinaryTreeSort(copy);
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << " " << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        copy = data;
        cout << "\tExecuting Radix Sort:";
        begin = high_resolution_clock::now();
        RadixSort(copy);
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << " " << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        copy = data;
        cout << "\tExecuting Shell Sort:";
        begin = high_resolution_clock::now();
        ShellSort(copy);
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << " " << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        copy = data;
        cout << "\tExecuting Selection Sort:";
        begin = high_resolution_clock::now();
        SelectionSort(copy);
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << " " << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        copy = data;
        cout << "\tExecuting Heap Sort:";
        begin = high_resolution_clock::now();
        HeapSort(copy);
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << " " << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        copy = data;
        cout << "\tExecuting Quick Sort:";
        begin = high_resolution_clock::now();
        QuickSort(copy, 0, (int)copy.size()-1);
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << " " << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        copy = data;
        cout << "\tExecuting Brick Sort:";
        begin = high_resolution_clock::now();
        BrickSort(copy);
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << " " << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;
        
        copy = data;
        cout << "\tExecuting Shaker Sort:";
        begin = high_resolution_clock::now();
        ShakerSort(copy);
        end = high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>( end - begin ).count();// Time in microseconds
        cout << " " << duration << " micro s" << " = " << duration / 1000000 << " s." << endl;

        cout << endl;
    }
    
    cout << endl;
    return 0;
}
