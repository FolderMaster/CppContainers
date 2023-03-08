#pragma once

namespace Containers
{
	template <class TItem>
	class ISimpleConstItemContainerTakeable
	{
	public:
		virtual const TItem& TakeItem() const = 0;
	};
}