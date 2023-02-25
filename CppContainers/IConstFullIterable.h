#pragma once

#include "IForwardIterableMoveable.h"
#include "IBackIterableMoveable.h"
#include "IValueIterableTakeable.h"
#include "IConstItemIterableTakeable.h"

#include "ConstFullIterator.h"

namespace Containers
{
	template <class T>
	class IConstFullIterable : public IForwardIterableMoveable, public IBackIterableMoveable,
		public IValueIterableTakeable<T>, public IConstItemIterableTakeable<T>
	{
	public:
		virtual ConstFullIterator<T> CreateConstFullBegin() const = 0;

		virtual ConstFullIterator<T> CreateConstFullEnd() const = 0;

		virtual ConstFullIterator<T> CreateConstBackFullBegin() const = 0;

		virtual ConstFullIterator<T> CreateConstBackFullEnd() const = 0;
	};
}