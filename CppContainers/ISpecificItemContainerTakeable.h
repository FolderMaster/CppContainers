#pragma once

namespace Containers
{
	template <class TItem>
	class ISpecificItemContainerTakeable
	{
	public:
		virtual TItem& TakeItemBegin() = 0;

		virtual TItem& TakeItemEnd() = 0;
	};
}