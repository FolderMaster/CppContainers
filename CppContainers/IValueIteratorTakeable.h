#pragma once

namespace Containers
{
	template <class TValue>
	class IValueIteratorTakeable
	{
	public:
		virtual TValue TakeValue() = 0;
	};
}