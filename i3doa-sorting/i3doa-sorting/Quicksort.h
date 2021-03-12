#pragma once

// This the version of quicksort that actually performs partitioning, recursive calls, etc. 
template<typename T>
void quicksort(T* ar, int start, int end)
{
  
    // if (base case reached) return;  // Base case: No sorting necessary 

    // select pivot index and position pivot;
    // partition ar[start; end];

    // Assume: Pivot is at index k after partitioning 
    //quicksort(ar, start, k - 1);
    //quicksort(ar, k + 1, end);
}


// This is the version of quicksort that the user sees. 
// Performs preprocessing, then calls the actual quicksort 
template<typename T>
void quicksort(T* ar, int n)
{
    // Preprocess ar (if required)

    // Call Quicksort
    quicksort(ar, 0, n - 1);
}
