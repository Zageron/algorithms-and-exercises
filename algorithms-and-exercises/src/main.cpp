// Current Problem:
// C arrays have size determined at compile time. Design a C++ class that
// provides you with objects that behave like arrays of int except that their size is
// determined at run time. Explain the reasons for your design decisions.

#include <assert.h>
#include <cstddef>
#include <initializer_list>
#include <memory>
#include <iostream>
#include <vector>

class RunTimeArray
{
private:
	std::size_t length;
	int* v;

public:
	RunTimeArray();
	explicit RunTimeArray(std::size_t size);
	RunTimeArray(std::initializer_list<int> init);
	~RunTimeArray();

	RunTimeArray(const RunTimeArray& other);

	RunTimeArray& operator=(const RunTimeArray& other);
	int& operator[](std::size_t n);
	const int& operator[](std::size_t n) const;

	friend std::size_t size(const RunTimeArray& rta);
};

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

bool operator==(const RunTimeArray& left, const RunTimeArray& right)
{
	if (size(left) != size(right))
	{
		return false;
	}

	for (size_t i(0); i < size(left); i++)
	{
		if (left[i] != right[i])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	auto v0 = RunTimeArray{ 1, 2, 3, 4, 5};
	auto v1 = RunTimeArray();

	v1 = v0;
	assert(v1 == v0);

	return 0;
}

std::size_t size(const RunTimeArray& rta)
{
	return std::size_t(rta.length);
}
