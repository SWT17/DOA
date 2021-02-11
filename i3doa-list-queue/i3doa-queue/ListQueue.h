#pragma once
#include "../i3doa-list/linkedlist.h"
#include "../i3doa-list/vectorlist.h"
#include "Queue.h"

template<typename T>
class ListQueue : public Queue<T>
{
public:
	void push(const T& elm)
	{
		/* YOUR CODE HERE */
	}

	void pop()
	{
		/* YOUR CODE HERE */
	}

	T front()
	{
		T dataValue = 0;
		/* YOUR CODE HERE */
		return dataValue;
	}

	bool isEmpty()
	{
		bool isItEmpty = true;
		/* YOUR CODE HERE */
		return isItEmpty;
	}

private:
	VectorList<T> list;
	//LinkedList<T> list;
};
