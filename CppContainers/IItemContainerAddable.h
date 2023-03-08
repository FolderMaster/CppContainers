#pragma once

namespace Containers
{
	template <class TItem, class TEnumerable>
	class IItemContainerAddable
	{
	public:
		virtual void AddItem(TItem& item, TEnumerable enumarable) = 0;
	};
}