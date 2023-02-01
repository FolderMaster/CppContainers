#pragma once

#include "IForwardMoveable.h"
#include "IBackMoveable.h"
#include "IValueIteratorTakeable.h"
#include "IItemIteratorTakeable.h"

namespace Containers
{
	template <class TValue, class TItem>
	class IFullIterator : IForwardMoveable, IBackMoveable, IValueIteratorTakeable<TValue>,
		IItemIteratorTakeable<TItem> {};
}