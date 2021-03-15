#pragma once
#include<vector>
#include<iostream>
#include<cassert>
using namespace std;

//==================================================
// CLASS MinHeap
//==================================================
template<typename T>
class MinHeap
{
public:
	MinHeap() {}
	MinHeap(const vector<T>& arr) : data(arr)
	{
		//Your code goes here
	}

	void insert(const T& x)
	{
		//Your code goes here
	}
	
	void remove()
	{
		//Your code goes here
	}
	
	bool isEmpty() const
	{ 
		//Your code goes here
		return true;//For compilation purpose only
	}
	
	T peek() const
	{ 
		//Your code goes here
		return 0;//For compilation purpose only
	}

	//Utility function: prints out vector iterative 
	void dump() const
	{
		copy(data.begin(), data.end(), ostream_iterator<T>(cout, ", "));
		cout << endl;
	}


	bool isHeap() const
	{
		for(size_t i=0; i< (data.size()-1)/2; i++)
		{
			if(smallest(i) != i) return false;
		}
		return true;
	}

	
private:
	void heapify()
	{
		//Your code goes here
	}

	void percolateUp(size_t i)
	{
		//Your code goes here 
	}

	void percolateDown(size_t i)
	{
		//Your code goes here
	}
	
	size_t smallest(size_t i) const	// returns index of smallest of i and its parents
	{
		size_t small = i;
	
		if(	left(i)  < data.size() && 
			data[i]> data[left(i)]) 
			small = left(i);
		
		if(	right(i) < data.size() && 
			data[i]> data[right(i)] && 
			data[right(i)]< data[left(i)] ) 
			small = right(i);

		return small;
	}

	void swap(size_t x, size_t y) 
	{ 
		T temp = data[x]; 
		data[x]=data[y]; 
		data[y]=temp;
	}
	


	size_t parent(size_t i) const { return (i-1)/2; }
	size_t left(size_t i)	const { return 2*i+1;   }
	size_t right(size_t i)	const { return 2*i+2;   }

private:
	vector<T> data;
};

