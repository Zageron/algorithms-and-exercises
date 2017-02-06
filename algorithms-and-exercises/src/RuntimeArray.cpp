#include "RuntimeArray.h"

RunTimeArray::RunTimeArray()
	: length(0), v(nullptr)
{
	// Empty
}

RunTimeArray::RunTimeArray(std::size_t size)
	: length(size)
	, v(new int[size])
{
	// Empty
}

RunTimeArray::RunTimeArray(std::initializer_list<int> init)
	: RunTimeArray(init.size())
{
	assert(init.size() <= length);
	std::copy(init.begin(), init.end(), v);
}

RunTimeArray::~RunTimeArray()
{
	delete[] v;
}

RunTimeArray::RunTimeArray(const RunTimeArray & other)
	: RunTimeArray(other.length)
{
	for (size_t i = 0; i < length; i++)
	{
		(*this)[i] = other[i];
	}
}

RunTimeArray& RunTimeArray::operator=(const RunTimeArray& other)
{
	if (this != &other)
	{
		if (this->length == other.length)
		{
			for (size_t i = 0; i < length; i++)
			{
				(*this)[i] = other[i];
			}
		}
		else
		{
			this -> ~RunTimeArray();
			new (this) RunTimeArray(other);
		}
	}

	return (*this);
}

int& RunTimeArray::operator[](std::size_t n)
{
	assert(n < length);
	return v[n];
}

const int& RunTimeArray::operator[](std::size_t n) const
{
	assert(n < length);
	return v[n];
}
