#pragma once

namespace Containers
{
	template <class TEnumerable>
	class IRemoveable
	{
	public:
		virtual void Remove(TEnumerable enumarable) = 0;
	};
}