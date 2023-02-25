#pragma once

#include "IForwardIteratorMoveable.h"
#include "IValueIteratorTakeable.h"
#include "IConstItemIteratorTakeable.h"

namespace Containers
{
	template <class TValue>
	class IConstForwardIterator : public IForwardIteratorMoveable,
		public IValueIteratorTakeable<TValue>,  public IConstItemIteratorTakeable<TValue> {};
}