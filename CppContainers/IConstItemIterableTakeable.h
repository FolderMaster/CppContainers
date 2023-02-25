#pragma once

namespace Containers
{
	template <class TItem>
	class IConstItemIterableTakeable
	{
	public:
		virtual const TItem& TakeConstItem(void* pointer) const = 0;
	};
}