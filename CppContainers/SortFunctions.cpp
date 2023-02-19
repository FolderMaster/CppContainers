#pragma once

#include "SortFunctions.h"

namespace Containers
{
	template<class T>
	bool IsMore(T a, T b)
	{
		return a > b;
	}

	template<class T>
	bool IsLess(T a, T b)
	{
		return a < b;
	}
}