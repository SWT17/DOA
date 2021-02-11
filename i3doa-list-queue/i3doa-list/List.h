#pragma once

template<typename T>
class List
{
public:
	// Precondition:  
	// Postcondition: list [0] = data 
	virtual void headInsert(const T& data) = 0;
	
	// Precondition:  
	// Postcondition: First element in list has been removed 
	virtual void headRemove() = 0;

	// Precondition: index < length 
	// Postcondition: list[index] = data 
	virtual void insert(const T& data, unsigned int index) = 0;

	// Precondition: index < length 
	// Postcondition: Element at position 'index' has been removed 
	virtual void remove(const unsigned int index) = 0;

	// Precondition:  index < length 
	// Postcondition: The element at position 'index' is returned 
	virtual T& at(unsigned int index) = 0;

	// Precondition: 
	// Postcondition: Length of list is returned 
	virtual unsigned int length() const = 0;

	// Precondition: 
	// Postcondition: The list is cleared (length() = 0) 
	virtual void clear() = 0;

	// Special - Required for Queue in later exercise
	virtual void tailInsert(const T& data) { std::exception("Not Implemented"); };

	// Destructor
	virtual ~List() {}
};
