#pragma once
#include "List.h"
#include <vector>


template<typename T>
class VectorList : public List<T>
{
private:
	std::vector<T> vec;

public:
	virtual void headInsert(const T& data)
	{
		insert(data, 0);
	}

	virtual void headRemove()
	{
		remove(0);
	}

	virtual void insert(const T& data, unsigned int index)
	{
		if(index > vec.size()) throw std::out_of_range("Index out of range");
		vec.insert(vec.begin() + index, data);
	}

	virtual void remove(const unsigned int index)
	{
		if (index >= vec.size())
			throw std::out_of_range("index out of range");
		else
			vec.erase(vec.begin() + index);
	}

	virtual T& at(unsigned int index)
	{
		if (index >= vec.size()) throw std::out_of_range("Index out of range");
		return vec[index];
	}

	virtual unsigned int length() const
	{
		return (unsigned int)vec.size();
	}

	virtual void clear()
	{
		vec.clear();
	}

	void tailInsert(const T& data)
	{
		vec.push_back(data);
	}

};
