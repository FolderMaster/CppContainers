#pragma once

#include "AdditionalFunctions.h"

namespace Containers
{
	template<class T>
	void Swap(T& item1, T& item2)
	{
		T swapItem = item1;
		item1 = item2;
		item2 = swapItem;
	}

	int FindCoprime(int number)
	{
		for (int result = 2; true; ++result)
		{
			bool isCompire = true;
			for (int n = 2; n < result && n < number; ++n)
			{
				if (result % n == 0 && number % n == 0)
				{
					isCompire = false;
					break;
				}
			}
			if (isCompire)
			{
				return result;
			}
			++result;
		}
	}
}