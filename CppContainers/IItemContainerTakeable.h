#pragma once

namespace Containers
{
	template <class TItem, class TEnumerable>
	class IItemContainerTakeable
	{
	public:
		virtual TItem& TakeItem(TEnumerable enumarable) = 0;
	};
}