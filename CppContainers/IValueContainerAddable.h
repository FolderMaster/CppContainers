#pragma once

namespace Containers
{
	template <class TValue, class TEnumerable>
	class IValueContainerAddable
	{
	public:
		virtual void AddValue(TValue value, TEnumerable enumarable) = 0;
	};
}