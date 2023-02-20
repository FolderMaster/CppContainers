#pragma once

#include "IBackIteratorMoveable.h"
#include "IValueIteratorTakeable.h"

namespace Containers
{
	template <class TValue>
	class IConstBackIterator : public IBackIteratorMoveable, public IValueIteratorTakeable<TValue>
	{};
}