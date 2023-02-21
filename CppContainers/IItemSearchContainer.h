#pragma once

#include "ISizeContainerGetable.h"
#include "IItemContainerTakeable.h"

namespace Containers
{
	template<class TItem, class TEnumerable>
	class IItemSearchContainer : public ISizeContainerGetable,
		public IItemContainerTakeable<TItem, TEnumerable> {};
}