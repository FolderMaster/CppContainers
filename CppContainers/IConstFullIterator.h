#pragma once

#include "IForwardIteratorMoveable.h"
#include "IBackIteratorMoveable.h"
#include "IValueIteratorTakeable.h"
#include "IConstItemIteratorTakeable.h"

namespace Containers
{
	template <class TValue>
	class IConstFullIterator : public IForwardIteratorMoveable, public IBackIteratorMoveable,
		public IValueIteratorTakeable<TValue>, public IConstItemIteratorTakeable<TValue> {};
}