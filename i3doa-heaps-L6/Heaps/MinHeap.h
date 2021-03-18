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
		//Jeg ved ikke hvilken kode der skulle ligge i constructoren når en MinHeap generes
	}

	//Precondition: Der er en vetor at arbejde på.
	//postcondition: Ny værdi indsat og manipuleret rundt i træet så IsHeap er true;
	void insert(const T& x)
	{
		//Den her del af koden skal indsætte x på den sidste plads i arrayet.
		data.push_back(x);
		//Herefter skal den percolate up indtil den ikke kan komme længere opaf x<data(parent_index)
		//Det rekursive kald.
		int indexOfx = (data.size() - 1);
		percolateUp(indexOfx);
	}
	
	//Precondition: IsEmpty = false;
	//Postcondition: Vector size er 1 mindre. IsHeap er true,
	void remove()
	{
		if (isEmpty())
		{
			return;
		}
		//Element på den sidste plads, skal op forrest i vectoren.
		if (data.size() == 1)
		{
			//Kun et element tilbage i vectoren.
			data.pop_back();
			return;
		}
		int indexOfLastE = data.size() - 1;
		int indexOfFirstE = 0;
		swap(indexOfLastE, indexOfFirstE);
		//Så kan jeg fjerne det sidste element i vectoren
		data.pop_back();
		//Så kan jeg begynde percolate down.
		percolateDown(0);

	}
	

	//Precondition: Der skal være en vectoren til at starte med
	//Postcondition: IsEmpty er true hvis vectoren har size 0,
	//				og false hvis size>0;
	bool isEmpty() const
	{ 
		//
		if (data.size() == 0)
		{
			return true;
		}
		return false;//For compilation purpose only
	}
	
	T peek() const
	{
		//Return øverste objekt i træet , første objekt i vectoren.
		T val_return = data[0];
		return val_return;
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
			if (smallest(i) != i)
			{
				return false;
			}
		}
		return true;
	}

	
private:
	void heapify()
	{
		//Your code goes here
	}

	//Precondition: i>=0
	//Postcondition: Værdien på index "i" er lavere end værdien på index parent(i) men større end værdien på index left(i) & right(i)
	void percolateUp(size_t i)
	{
		//Ideen her er en række rekursive kald, indtil data er på den rigtig plads
		if (i > 0 && data[i] >data[parent(i)])
		{
			return;
		}
		if (i > 0 && data[i] < data[parent(i)])
		{
			swap(i,parent(i));
			//Rekursivt kald til perculateUp. Gentag processen, nu er værdien i bare på index parent(i)
			percolateUp(parent(i));
		}
		
	}

	//Precondition: En vectorsize>0
	//Postcondition: Værdien på "i" er flyttet så langt ned at værdien er større end sin parent men mindre end sine children.
	void percolateDown(size_t i)
	{
		//Tjek om i har et child, eller i er et leaf. Tjek om data(i) er større end left child, og om left child er mindre end right child.
		if (i < ((data.size() - 1) / 2) && data[i]>data[left(i)] && data[left(i)] < data[right(i)])
		{
			swap(i, left(i));
			percolateDown(left(i));

		}
		//Tjek om i har et child, eller i er et leaf. Tjek om data(i) er større end left child, og om right child er mindre end left child.
		if (i < ((data.size() - 1) / 2) 
			&& data[i]>data[right(i)] 
			&& data[right(i)] < data[left(i)])
		{
			swap(i, right(i));
			percolateDown(right(i));
		}
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

