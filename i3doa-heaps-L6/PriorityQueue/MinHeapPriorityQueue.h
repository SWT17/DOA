#include "../Heaps/MinHeap.h"
#include "PriorityQueue.h"

template<class T>
class MinHeapPriorityQueue : public PriorityQueue<T>
{
public:
	MinHeapPriorityQueue()	{}
	void push(const T& x)	{ minHeap.insert(x);		}
	void pop()				{ minHeap.remove();			}
	T front()				{ return minHeap.peek();	} 
	bool isEmpty() const	{ return minHeap.isEmpty();	}

private:
	MinHeap<T> minHeap;
};
