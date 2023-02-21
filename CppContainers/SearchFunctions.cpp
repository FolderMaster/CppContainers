#pragma once

#include "SearchFunctions.h"
#include "Exceptions.h"

namespace Containers
{
	template<class TValue>
	int LinearFindIndex(IConstForwardIterable<TValue>& iterable, TValue value)
	{
		int index = 0;
		ConstForwardIterator<TValue> begin = iterable.CreateConstForwardBegin();
		while (begin.IsForward())
		{
			if (begin.TakeValue() == value)
			{
				return index;
			}
			++index;
			begin.Forward();
		}
		return -1;
	}

	template<class TValue>
	TValue LinearFindValue(const IConstForwardIterable<TValue>& iterable, TValue value)
	{
		ConstForwardIterator<TValue> begin = iterable.CreateConstForwardBegin();
		while (begin.IsForward())
		{
			if (begin.TakeValue() == value)
			{
				return begin.TakeValue();
			}
			begin.Forward();
		}
		throw ValueNotFoundException;
	}

	template<class TItem>
	TItem& LinearFindItem(IForwardIterable<TItem>& iterable, TItem& item)
	{
		ForwardIterator<TItem> begin = iterable.CreateForwardBegin();
		while (begin.IsForward())
		{
			if (begin.TakeItem() == item)
			{
				return begin.TakeItem();
			}
			begin.Forward();
		}
		throw ItemNotFoundException;
	}

	template<class TValue, class TEnumerable>
	TEnumerable BinaryFindIndex(IValueSearchContainer<TValue, TEnumerable>& searchContainer,
		TValue value, bool (*sortFunction)(TValue, TValue))
	{
		size_t size = searchContainer.GetSize();
		for (int left = 0, right = size - 1, mid = size / 2; left <= right; mid = (left +
			right) / 2)
		{
			TValue takedValue = searchContainer.TakeValue(mid);
			if (takedValue == value)
			{
				return mid;
			}
			else
			{
				if (sortFunction(takedValue, value))
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
		}
		return -1;
	}

	template<class TValue, class TEnumerable>
	TValue BinaryFindValue(const IValueSearchContainer<TValue, TEnumerable>& searchContainer,
		TValue value, bool(*sortFunction)(TValue, TValue))
	{
		size_t size = searchContainer.GetSize();
		for (int left = 0, right = size - 1, mid = size / 2; left <= right; mid = (left +
			right) / 2)
		{
			TValue takedValue = searchContainer.TakeValue(mid);
			if (takedValue == value)
			{
				return takedValue;
			}
			else
			{
				if (sortFunction(takedValue, value))
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
		}
		throw ValueNotFoundException;
	}

	template<class TItem, class TEnumerable>
	TItem& BinaryFindItem(IItemSearchContainer<TItem, TEnumerable>& searchContainer,
		TItem& item, bool(*sortFunction)(TItem, TItem))
	{
		size_t size = searchContainer.GetSize();
		for (int left = 0, right = size - 1, mid = size / 2; left <= right; mid = (left +
			right) / 2)
		{
			TItem takedItem = searchContainer.TakeItem(mid);
			if (takedItem == item)
			{
				return takedItem;
			}
			else
			{
				if (sortFunction(takedItem, item))
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
		}
		throw ItemNotFoundException;
	}
}