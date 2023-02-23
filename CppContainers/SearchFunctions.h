#pragma once

#include "IValueSearchContainer.h"
#include "IItemSearchContainer.h"
#include "IForwardIterable.h"
#include "IConstForwardIterable.h"

namespace Containers
{
	template<class TValue>
	int LinearFindIndex(IConstForwardIterable<TValue>& iterable, TValue value);

	template<class TValue>
	IForwardIterable<int>& LinearFindIndices(const IConstForwardIterable<TValue>& iterable,
		TValue value);

	template<class TValue>
	TValue LinearFindValue(const IConstForwardIterable<TValue>& iterable, TValue value);

	template<class TValue>
	IForwardIterable<TValue>& LinearFindValues(const IConstForwardIterable<TValue>& iterable,
		TValue value);

	template<class TItem>
	TItem& LinearFindItem(IForwardIterable<TItem>& iterable, TItem& item);

	template<class TItem>
	IForwardIterable<TItem&>& LinearFindItems(IForwardIterable<TItem>& iterable,
		TItem& item);

	template<class TValue, class TEnumerable>
	TEnumerable BinaryFindIndex(IValueSearchContainer<TValue, TEnumerable>& searchContainer,
		TValue value, bool (*sortFunction)(TValue, TValue));

	template<class TValue, class TEnumerable>
	TValue BinaryFindValue(const IValueSearchContainer<TValue, TEnumerable>& searchContainer,
		TValue value, bool (*sortFunction)(TValue, TValue));

	template<class TItem, class TEnumerable>
	TItem& BinaryFindItem(IItemSearchContainer<TItem, TEnumerable>& searchContainer,
		TItem& item, bool (*sortFunction)(TItem, TItem));
}