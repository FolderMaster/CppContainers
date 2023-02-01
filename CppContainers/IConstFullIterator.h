#pragma once

#include "IForwardMoveable.h"
#include "IBackMoveable.h"
#include "IValueIteratorTakeable.h"

namespace Containers
{
	template <class TValue>
	class IConstFullIterator : IForwardMoveable, IBackMoveable, IValueIteratorTakeable<TValue> {};
}