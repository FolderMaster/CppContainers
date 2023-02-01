#pragma once

namespace Containers
{
	template <class TValue>
	class IValueIterableTakeable
	{
	public:
		virtual TValue TakeValue(void* pointer) = 0;
	};
}