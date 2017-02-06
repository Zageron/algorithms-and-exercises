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

#include "RuntimeArray.h"


int main()
{
	auto v0 = RunTimeArray{ 1, 2, 3, 4, 5};
	auto v1 = RunTimeArray();

	v1 = v0;
	assert(v0 == v1);

	return 0;
}

