#pragma once

namespace Containers
{
	template <class TItem>
	class ISpecificConstItemContainerTakeable
	{
	public:
		virtual const TItem& TakeConstItemBegin() const = 0;

		virtual const TItem& TakeConstItemEnd() const = 0;
	};
}