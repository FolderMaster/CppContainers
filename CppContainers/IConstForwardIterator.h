#pragma once

#include "IForwardMoveable.h"
#include "IValueIteratorTakeable.h"

namespace Containers
{
	template <class TValue>
	class IConstForwardIterator : public IForwardMoveable, public IValueIteratorTakeable<TValue> {};
}