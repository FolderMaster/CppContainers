#pragma once

#include "ISortContainer.h"

namespace Containers
{
	template<class T>
	bool IsMore(T a, T b);

	template<class T>
	bool IsLess(T a, T b);

	template<class TItem, class TEnumerable>
	void BubbleSort(ISortContainer<TItem, TEnumerable>& sortContainer,
		bool (*sortFunction)(TItem, TItem));
}