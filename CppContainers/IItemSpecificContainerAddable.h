#pragma once

namespace Containers
{
	template <class TItem>
	class IItemSpecificContainerAddable
	{
	public:
		virtual void AddItemBegin(TItem& item) = 0;

		virtual void AddItemEnd(TItem& item) = 0;
	};
}