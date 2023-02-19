#pragma once

namespace Containers
{
	template<class TEnumerable>
	TEnumerable LinearFindIndex();

	template<class TEnumerable>
	TEnumerable BinaryFindIndex();

	template<class TValue>
	TValue LinearFindValue();

	template<class TValue>
	TValue BinaryFindValue();

	template<class TItem>
	TItem& LinearFindItem();

	template<class TItem>
	TItem& BinaryFindItem();
}