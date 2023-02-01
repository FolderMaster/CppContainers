#pragma once

#include "IForwardMoveable.h"
#include "IValueIteratorTakeable.h"
#include "IItemIteratorTakeable.h"

namespace Containers
{
	template <class TValue, class TItem>
	class IForwardIterator : IForwardMoveable, IValueIteratorTakeable<TValue>, 
		IItemIteratorTakeable<TItem> {};
}