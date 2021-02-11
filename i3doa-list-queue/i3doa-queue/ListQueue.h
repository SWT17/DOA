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
		list.tailInsert(elm);
	}

	void pop()
	{
		list.headRemove();
	}

	T front()
	{
		T dataValue = 0;
		dataValue = list.at(0);
		return dataValue;
	}

	bool isEmpty()
	{
		bool isItEmpty = true;
		if (list.length() != 0)
		{
			isItEmpty = false;
		}
		return isItEmpty;
	}

private:
	VectorList<T> list;
	//LinkedList<T> list;
};
