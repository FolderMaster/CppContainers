#pragma once

namespace Containers
{
	template <class TValue, class TEnumerable>
	class IValueContainerTakeable
	{
	public:
		virtual TValue TakeValue(TEnumerable enumarable) const = 0;
	};
}