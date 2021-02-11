#pragma once
#include <stdexcept>
#include"List.h"


template<typename T>
class LinkedList : public List<T>
{
public:
	LinkedList() 
	: head(nullptr), size(0)
	{
		//test
	}


	~LinkedList()
	{
		clear();
	}

	void insert(const T& data, unsigned int index)
	{
		/* YOUR CODE HERE */

	}

	void remove(const unsigned int index)
	{
		/* YOUR CODE HERE */

	}

	unsigned int length() const
	{
		int len = 0;
		/* YOUR CODE HERE */
		return len;
	}

	T& at(unsigned int index)
	{
		/* YOUR CODE HERE (and remove the line below!) */
		return head->data; // Just to make the file compile!
	}

	void headInsert(const T& data)
	{
		Node* newNode = new Node(data, nullptr);
		newNode->data = data;
		newNode->next = head;
		head = newNode;

		// Or simply: 
		// head = new Node(data, head);

		++size;
	}

	void headRemove()
	{
		/* YOUR CODE HERE */
	}

	void clear()
	{
		/* YOUR CODE HERE */
	}


private:

	class Node
	{
	public:
		// Node Constructor
		// If d not given, use template type and create instance of type
		// If n not given, set n = nullptr
		Node(const T& d = T(), Node* n = nullptr) : data(d), next(n) {}

		// Public attributes
		T data;
		Node* next;
	};

	// Precondition: index < size
	// Postcondition: Pointer to Node @ index returned 
	Node* get(unsigned int index) const
	{
		Node* cursor = head;

		/* YOUR CODE HERE */

		return cursor;
	}


	Node* head;
	unsigned int size;
};
