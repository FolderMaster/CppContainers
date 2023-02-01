#pragma once

namespace Containers
{
	template <class TItem>
	class IItemIteratorTakeable
	{
	public:
		virtual TItem TakeItem() = 0;
	};
}