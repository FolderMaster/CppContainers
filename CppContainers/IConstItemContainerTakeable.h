#pragma once

namespace Containers
{
	template <class TItem, class TEnumerable>
	class IConstItemContainerTakeable
	{
	public:
		virtual const TItem& TakeConstItem(TEnumerable enumarable) const = 0;
	};
}