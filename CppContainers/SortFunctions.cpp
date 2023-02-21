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

	template<class TItem, class TEnumerable>
	void BubbleSort(ISortContainer<TItem, TEnumerable>& sortContainer,
		bool(*sortFunction)(TItem, TItem))
	{
		size_t size = sortContainer.GetSize();
		for (int n = 0; n < size; ++n)
		{
			for (int k = n; k < size - 1; ++k)
			{
				TItem& firstItem = sortContainer.TakeItem(k);
				TItem& secondItem = sortContainer.TakeItem(k + 1);
				if (sortFunction(secondItem, firstItem))
				{
					TItem value = firstItem;
					firstItem = secondItem;
					secondItem = value;
				}
			}
		}
	}
}