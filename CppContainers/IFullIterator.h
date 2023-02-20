#pragma once

#include "IForwardIteratorMoveable.h"
#include "IBackIteratorMoveable.h"
#include "IValueIteratorTakeable.h"
#include "IItemIteratorTakeable.h"

namespace Containers
{
	template <class TValue, class TItem>
	class IFullIterator : IForwardIteratorMoveable, IBackIteratorMoveable,
		IValueIteratorTakeable<TValue>, IItemIteratorTakeable<TItem> {};
}