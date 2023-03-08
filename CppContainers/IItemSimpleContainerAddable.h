#pragma once

namespace Containers
{
	template <class TItem>
	class IItemSimpleContainerAddable
	{
	public:
		virtual void AddItem(TItem& item) = 0;
	};
}