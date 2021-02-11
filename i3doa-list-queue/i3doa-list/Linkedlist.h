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
		
	}


	~LinkedList()
	{
		clear();
	}

	void insert(const T& data, unsigned int index)
	{
		/* index<size list(index) is removed.
		* Traverse the list for index-1 - get the index-1 next in the new node. Index-1 next to point to
		* new node adresse
		*/
		if (index < size && index != 0)
		{
			Node* newNode = new Node(data,nullptr);
			Node* temp = get(index - 1);
			newNode->next = temp;
			temp->next = newNode;
			++size;
			return;
		}
		if (index == 0)
		{
			headInsert(data);
			return;
		}
		/*if (index == size)
		{
			tailInsert(data);
			return;
		}*/
		throw std::out_of_range("Index out of range");

	}

	void remove(const unsigned int index)
	{
		//Index<length, Element at index is removed, --size
		//Find index-1 - save next in temp - save temp-next in index-1 - delete temp - (--size)
		if (index < size)
		{
			Node* temp_index = get(index - 1);
			Node* temp = temp_index->next;
			temp_index->next = temp->next;
			delete temp;
			--size;
			return;
		}
		if (index == 0)
		{
			headRemove();
			--size;
			return;
		}
		
		throw std::out_of_range("index out of range");
		

	}

	unsigned int length() const
	{
		int len = 0;
		len = size;
		return len;
	}

	T& at(unsigned int index)
	{
		Node* temp = get(index);
		return temp->data; 
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
		if (size != 0 && size!=1)
		{
			//First element to be removed
			//Locate first element - Let the "next" of the node which head points to, be "next" on head.
			Node* temp = new Node();
			temp = head->next; // temp Node points to next of head.
			delete head;
			head = temp; // head is to point, at temp->next
			--size;
			return;
		}
		if(size == 1)
		{
			delete head;
			head = nullptr;
			--size;
			return;
		}
	
		throw std::out_of_range("index out of range");
		
	}

	void clear()
	{
		while (head)
		{
			headRemove();
		}
	}

	//void tailInsert(const T& data) 
	//{
	//	/*
	//	* Point is to increase size by 1, and put new node at the end of the list (at the tail)
	//	* Get the node at index==size,points its next to the new node, let the new node point to nullptr.
	//	*/
	//	Node* newNode = new Node(data, nullptr);
	//	Node* temp = get(size-1);
	//	temp->next = newNode;


	//}

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
		//Post Condition, return Node at index
		//Transverse the node chain index-times - Make a Node* temp of the Node at index
		Node* cursor = head;
		for(int i = 0;i<index;i++)
		{
			cursor = cursor->next;		
		}

		return cursor;
	}


	Node* head;
	unsigned int size;
};
