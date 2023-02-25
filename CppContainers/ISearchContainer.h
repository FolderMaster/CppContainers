#pragma once

#include "ISizeContainerGetable.h"
#include "IValueContainerTakeable.h"
#include "IConstItemContainerTakeable.h"
#include "IItemContainerTakeable.h"

namespace Containers
{
	template<class TItem, class TEnumerable>
	class ISearchContainer : public ISizeContainerGetable,
		public IItemContainerTakeable<TItem, TEnumerable>,
		public IConstItemContainerTakeable<TItem, TEnumerable>,
		public IValueContainerTakeable<TItem, TEnumerable> {};
}