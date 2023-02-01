#pragma once

#include "IBackMoveable.h"
#include "IValueIteratorTakeable.h"

namespace Containers
{
	template <class TValue>
	class IConstBackIterator : public IBackMoveable, public IValueIteratorTakeable<TValue> {};
}