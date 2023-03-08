#pragma once

#include "SearchFunctions.h"

#include "SingleLinkedList.h"
#include "Exceptions.h"

namespace Containers
{
	template<class TValue>
	int LinearFindIndex(const IConstForwardIterable<TValue>& iterable, TValue value)
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
	IForwardIterable<int>& LinearFindIndices(const IConstForwardIterable<TValue>& iterable,
		TValue value)
	{
		int index = 0;
		SingleList<int>* list = new SingleList<int>();
		ConstForwardIterator<TValue> begin = iterable.CreateConstForwardBegin();
		while (begin.IsForward())
		{
			if (begin.TakeValue() == value)
			{
				list->AddItemEnd(index);
			}
			++index;
			begin.Forward();
		}
		return *list;
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

	template<class TValue>
	IForwardIterable<TValue>& LinearFindValues(const IConstForwardIterable<TValue>& iterable,
		TValue value)
	{
		SingleList<TValue>* list = new SingleList<TValue>();
		ConstForwardIterator<TValue> begin = iterable.CreateConstForwardBegin();
		while (begin.IsForward())
		{
			if (begin.TakeValue() == value)
			{
				list->AddEnd(begin.TakeValue());
			}
			begin.Forward();
		}
		return *list;
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

	template<class TItem>
	IForwardIterable<TItem&>& LinearFindItems(IForwardIterable<TItem>& iterable, TItem& item)
	{
		SingleList<TItem&>* list = new SingleList<TItem&>();
		ForwardIterator<TItem> begin = iterable.CreateForwardBegin();
		while (begin.IsForward())
		{
			if (begin.TakeValue() == item)
			{
				list->AddItemEnd(begin.TakeItem());
			}
			begin.Forward();
		}
		return *list;
	}

	template<class TItem>
	const TItem& LinearFindConstItem(const IConstForwardIterable<TItem>& iterable, const TItem& item)
	{
		ConstForwardIterator<TItem> begin = iterable.CreateConstForwardBegin();
		while (begin.IsForward())
		{
			if (begin.TakeConstItem() == item)
			{
				return begin.TakeConstItem();
			}
			begin.Forward();
		}
		throw ConstItemNotFoundException;
	}

	template<class TItem>
	IForwardIterable<const TItem&>& LinearFindConstItems(const IConstForwardIterable<TItem> iterable, const TItem& item)
	{
		SingleList<const TItem&>* list = new SingleList<const TItem&>();
		ConstForwardIterator<TItem> begin = iterable.CreateConstForwardBegin();
		while (begin.IsForward())
		{
			if (begin.TakeConstItem() == item)
			{
				list->AddEnd(begin.TakeConstItem());
			}
			begin.Forward();
		}
		return *list;
	}

	template<class TValue, class TEnumerable>
	TEnumerable BinaryFindIndex(ISearchContainer<TValue, TEnumerable>& searchContainer,
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
	TValue BinaryFindValue(const ISearchContainer<TValue, TEnumerable>& searchContainer,
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
	TItem& BinaryFindItem(ISearchContainer<TItem, TEnumerable>& searchContainer,
		TItem& item, bool(*sortFunction)(TItem, TItem))
	{
		size_t size = searchContainer.GetSize();
		for (int left = 0, right = size - 1, mid = size / 2; left <= right; mid = (left +
			right) / 2)
		{
			TItem& takedItem = searchContainer.TakeItem(mid);
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

	template<class TItem, class TEnumerable>
	const TItem& BinaryFindConstItem(const ISearchContainer<TItem, TEnumerable>& searchContainer,
		const TItem& item, bool(*sortFunction)(TItem, TItem))
	{
		size_t size = searchContainer.GetSize();
		for (int left = 0, right = size - 1, mid = size / 2; left <= right; mid = (left +
			right) / 2)
		{
			const TItem& takedItem = searchContainer.TakeConstItem(mid);
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
		throw ConstItemNotFoundException;
	}
}