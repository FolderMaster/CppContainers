#pragma once

#include "ISearchContainer.h"
#include "IForwardIterable.h"
#include "IConstForwardIterable.h"

namespace Containers
{
	template<class TValue>
	int LinearFindIndex(const IConstForwardIterable<TValue>& iterable, TValue value);

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

	template<class TItem>
	const TItem& LinearFindConstItem(const IConstForwardIterable<TItem>& iterable,
		const TItem& item);

	template<class TItem>
	IForwardIterable<const TItem&>& LinearFindConstItems(const IConstForwardIterable<TItem>
		iterable, const TItem& item);

	template<class TValue, class TEnumerable>
	TEnumerable BinaryFindIndex(const ISearchContainer<TValue, TEnumerable>& searchContainer,
		TValue value, bool (*sortFunction)(TValue, TValue));

	template<class TValue, class TEnumerable>
	TValue BinaryFindValue(const ISearchContainer<TValue, TEnumerable>& searchContainer,
		TValue value, bool (*sortFunction)(TValue, TValue));

	template<class TItem, class TEnumerable>
	TItem& BinaryFindItem(ISearchContainer<TItem, TEnumerable>& searchContainer,
		TItem& item, bool (*sortFunction)(TItem, TItem));

	template<class TItem, class TEnumerable>
	const TItem& BinaryFindConstItem(const ISearchContainer<TItem, TEnumerable>& searchContainer,
		const TItem& item, bool (*sortFunction)(TItem, TItem));
}