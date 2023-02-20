#pragma once

#include "IForwardIterableMoveable.h"
#include "IValueIterableTakeable.h"
#include "ConstForwardIterator.h"

namespace Containers
{
	template <class TValue>
	class IConstForwardIterable : public IForwardIterableMoveable,
		public IValueIterableTakeable<TValue>
	{
	public:
		virtual ConstForwardIterator<TValue> CreateConstForwardBegin() const = 0;

		virtual ConstForwardIterator<TValue> CreateConstForwardEnd() const = 0;
	};
}