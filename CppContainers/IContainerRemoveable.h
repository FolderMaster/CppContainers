#pragma once

namespace Containers
{
	template <class TEnumerable>
	class IContainerRemoveable
	{
	public:
		virtual void Remove(TEnumerable enumarable) = 0;
	};
}