#pragma once

namespace Containers
{
	template <class TValue, class TEnumerable>
	class IContainerAddable
	{
	public:
		virtual void Add(TValue value, TEnumerable enumarable) = 0;
	};
}