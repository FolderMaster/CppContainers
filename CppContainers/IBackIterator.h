#pragma once

#include "IBackIteratorMoveable.h"
#include "IValueIteratorTakeable.h"
#include "IItemIteratorTakeable.h"

namespace Containers
{
	template <class TValue, class TItem>
	class IBackIterator : IBackIteratorMoveable, IValueIteratorTakeable<TValue>,
		IItemIteratorTakeable<TItem> {};
}