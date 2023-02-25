#pragma once

#include "IBackIterableMoveable.h"
#include "IValueIterableTakeable.h"
#include "IItemIterableTakeable.h"
#include "IConstItemIterableTakeable.h"

#include "BackIterator.h"

namespace Containers
{
	template <class T>
	class IBackIterable : public IBackIterableMoveable, public IValueIterableTakeable<T>,
		public IItemIterableTakeable<T>, public IConstItemIterableTakeable<T>
	{
	public:
		virtual BackIterator<T> CreateBackBegin() = 0;

		virtual BackIterator<T> CreateBackEnd() = 0;
	};
}