#pragma once
#include "../Heaps/MinHeap.h"
#include<stdexcept>

template<typename T>
T select(const unsigned int k, const vector<T>& ar)
{
	if (k < 1 || k>ar.size()) throw invalid_argument("k must be in range [1, array_size)");

	// Create heap from ar (implicitly heapify array)
	// Your code goes here

	// Remove (k-1) elements
	//Your code goes here
	return 0;//Your code goes here
}


template<typename T>
void heapsort(vector<T>& ar)
{
	//Your code goes here
}
