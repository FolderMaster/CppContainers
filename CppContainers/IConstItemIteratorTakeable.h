#pragma once

namespace Containers
{
	template <class TItem>
	class IConstItemIteratorTakeable
	{
	public:
		virtual const TItem& TakeConstItem() const = 0;
	};
}