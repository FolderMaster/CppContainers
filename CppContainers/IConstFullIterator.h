#pragma once

#include "IForwardIteratorMoveable.h"
#include "IBackIteratorMoveable.h"
#include "IValueIteratorTakeable.h"

namespace Containers
{
	template <class TValue>
	class IConstFullIterator : IForwardIteratorMoveable, IBackIteratorMoveable,
		IValueIteratorTakeable<TValue> {};
}