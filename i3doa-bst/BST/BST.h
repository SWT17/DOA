#pragma once

template<typename T>
class BST
{
public:
	template<typename T>
	class Node
	{
	public:
		Node(const T& _data = T(), Node<T>* l = nullptr, Node<T>* r = nullptr, Node<T>* p = nullptr)
			: data(_data), left(l), right(r), parent(p)
		{}

		T data;
		Node<T>* parent;
		Node<T>* left;
		Node<T>* right;
	};
private:
	Node<T>* root;

	// Recursive function to find Node with data = data
	Node<T>* findNode(Node<T>* itsRoot, const T& data)
	{
		/* Function to be implemented */ return nullptr;
	}

	// Recursive function to insert node with data
	Node<T>* insertNode(Node<T>* itsRoot, const T& data)
	{
		/* Function to be implemented */ return nullptr;
	}

	// Recursive function to find right-most node
	Node<T>* findRightmostChild(Node<T>* itsRoot) {
		/* Helper function can be implemented */ return nullptr;
	}

	// Recursive function to find left-most node
	Node<T>* findLeftmostChild(Node<T>* itsRoot) {
		/* Helper function can be implemented */ return nullptr;
	}


public:

	BST(Node<T>* root = nullptr) : root(root)
	{
	}

	bool search(const T& data)
	{
		// Recursive function called with root as seed
		return findNode(root, data) != nullptr;
	}

	void insert(const T& data)
	{
		// Recursive function called with root as seed
		insertNode(root, data);
	}

	void remove(const T& data)
	{
		/* Function to be implemented */
	}

};