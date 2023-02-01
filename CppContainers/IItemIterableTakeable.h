#pragma once

namespace Containers
{
	template <class TItem>
	class IItemIterableTakeable
	{
	public:
		virtual TItem& TakeItem(void* pointer) = 0;
	};
}