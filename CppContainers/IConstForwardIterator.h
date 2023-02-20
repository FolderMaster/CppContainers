#pragma once

#include "IForwardIteratorMoveable.h"
#include "IValueIteratorTakeable.h"

namespace Containers
{
	template <class TValue>
	class IConstForwardIterator : public IForwardIteratorMoveable,
		public IValueIteratorTakeable<TValue> {};
}