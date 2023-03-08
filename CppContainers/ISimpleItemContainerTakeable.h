#pragma once

namespace Containers
{
	template <class TItem>
	class ISimpleItemContainerTakeable
	{
	public:
		virtual TItem& TakeItem() = 0;
	};
}