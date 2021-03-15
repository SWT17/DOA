#pragma once
#include <algorithm>
#include <math.h>

// This the version of quicksort that actually performs partitioning, recursive calls, etc. 
template<typename T>
void quicksort(T* ar, int start, int end)
{
    // if (base case reached) return;  // Base case: No sorting necessary 
    // typically n<=1 but, insertionsort og quadraticsort is quicker for smal arrays
    // so basecase could be something like n<=15

    if ((start-end) == 0)
    {
        return;
    }

    // select pivot index and position pivot;
    // chose median of ar[1], ar[size(ar)/2], ar[end]
    
    int pivotvalue = findMedian(ar, start, end);

    //Partion with repsect to the found pivot value;
    auto it = std::partition(ar[start], ar[end],[](int i) {return i < pivotvalue;});


    // Assume: Pivot is at index k after partitioning 
    // do the whole thing again.
    //Key is, that all sorting happens with respect to the same T* ar pointer. So the array
    //is sorted in it self so to speak.

    //quicksort(ar, start, k - 1);

    //This sort the upperhalf with repsect to the first found k.
    //quicksort(ar, k + 1, end);
}


// This is the version of quicksort that the user sees. 
// Performs preprocessing, then calls the actual quicksort 
template<typename T>
void quicksort(T* ar, int n)
{
    // Preprocess ar (if required)
    // Check if array is already sorted?
    

    // Call Quicksort
    quicksort(ar, 0, n - 1);
}

template<typename T>
int findMedian(T* ar, int start, int end)
{
    int index = (int)round((end - start) / 2);
    return ar[index];
}

