#pragma once

#include "IBackIterableMoveable.h"
#include "IValueIterableTakeable.h"
#include "IConstItemIterableTakeable.h"

#include "ConstBackIterator.h"

namespace Containers
{
	template <class TValue>
	class IConstBackIterable : public IBackIterableMoveable,
		public IValueIterableTakeable<TValue>, public IConstItemIterableTakeable<TValue>
	{
	public:
		virtual ConstBackIterator<TValue> CreateConstBackBegin() const = 0;

		virtual ConstBackIterator<TValue> CreateConstBackEnd() const = 0;
	};
}