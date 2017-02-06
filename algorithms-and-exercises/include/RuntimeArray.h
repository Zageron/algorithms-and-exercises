#pragma once
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

inline bool operator==(const RunTimeArray& left, const RunTimeArray& right)
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

inline std::size_t size(const RunTimeArray& rta)
{
	return std::size_t(rta.length);
}
