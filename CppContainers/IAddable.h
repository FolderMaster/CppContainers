#pragma once

namespace Containers
{
	template <class TValue, class TEnumerable>
	class IAddable
	{
	public:
		virtual void Add(TValue value, TEnumerable enumarable) = 0;
	};
}