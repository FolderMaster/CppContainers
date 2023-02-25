#pragma once

#include "IForwardIteratorMoveable.h"
#include "IValueIteratorTakeable.h"
#include "IConstItemIteratorTakeable.h"
#include "IItemIteratorTakeable.h"

namespace Containers
{
	template <class TValue, class TItem>
	class IForwardIterator : public IForwardIteratorMoveable,
		public IValueIteratorTakeable<TValue>, public IItemIteratorTakeable<TItem>,
		public IConstItemIteratorTakeable<TItem> {};
}