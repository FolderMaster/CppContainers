#pragma once

#include "IForwardIterableMoveable.h"
#include "IValueIterableTakeable.h"
#include "IItemIterableTakeable.h"
#include "ForwardIterator.h"

namespace Containers
{
	template <class T>
	class IForwardIterable : public IForwardIterableMoveable,
		public IValueIterableTakeable<T>, public IItemIterableTakeable<T>
	{
	public:
		virtual ForwardIterator<T> CreateForwardBegin() = 0;

		virtual ForwardIterator<T> CreateForwardEnd() = 0;
	};
}