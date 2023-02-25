#pragma once

#include "IForwardIterableMoveable.h"
#include "IBackIterableMoveable.h"
#include "IValueIterableTakeable.h"
#include "IItemIterableTakeable.h"
#include "IConstItemIterableTakeable.h"

#include "FullIterator.h"

namespace Containers
{
	template <class T>
	class IFullIterable : public IForwardIterableMoveable, public IBackIterableMoveable,
		public IValueIterableTakeable<T>, public IItemIterableTakeable<T>,
		public IConstItemIterableTakeable<T>
	{
	public:
		virtual FullIterator<T> CreateFullBegin() = 0;

		virtual FullIterator<T> CreateFullEnd() = 0;

		virtual FullIterator<T> CreateBackFullBegin() = 0;

		virtual FullIterator<T> CreateBackFullEnd() = 0;
	};
}