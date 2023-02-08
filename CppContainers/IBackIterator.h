#pragma once

#include "IBackMoveable.h"
#include "IValueIteratorTakeable.h"
#include "IItemIteratorTakeable.h"

namespace Containers
{
	template <class TValue, class TItem>
	class IBackIterator : IBackMoveable, IValueIteratorTakeable<TValue>,
		IItemIteratorTakeable<TItem> {};
}