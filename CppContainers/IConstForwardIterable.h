#pragma once

#include "IForwardIterable.h"
#include "IValueIterableTakeable.h"
#include "ConstForwardIterator.h"

namespace Containers
{
	template <class TValue>
	class IConstForwardIterable : public IForwardIterable, public IValueIterableTakeable<TValue>
	{
	public:
		virtual ConstForwardIterator<TValue> CreateConstForwardBegin() = 0;

		virtual ConstForwardIterator<TValue> CreateConstForwardEnd() = 0;
	};
}