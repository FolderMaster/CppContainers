#pragma once

#include "IForwardIteratorMoveable.h"
#include "IBackIteratorMoveable.h"
#include "IValueIteratorTakeable.h"
#include "IConstItemIteratorTakeable.h"
#include "IItemIteratorTakeable.h"

namespace Containers
{
	template <class TValue, class TItem>
	class IFullIterator : public IForwardIteratorMoveable, public IBackIteratorMoveable,
		public IValueIteratorTakeable<TValue>, public IItemIteratorTakeable<TItem>,
		public IConstItemIteratorTakeable<TItem> {};
}