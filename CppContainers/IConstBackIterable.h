#pragma once

#include "IBackIterable.h"
#include "IValueIterableTakeable.h"
#include "ConstBackIterator.h"

namespace Containers
{
	template <class TValue>
	class IConstBackIterable : public IBackIterable, public IValueIterableTakeable<TValue>
	{
	public:
		virtual ConstBackIterator<TValue> CreateConstBackBegin() = 0;

		virtual ConstBackIterator<TValue> CreateConstBackEnd() = 0;
	};
}