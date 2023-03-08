#pragma once

#include "IValueContainerAddable.h"
#include "IValueSpecificContainerAddable.h"
#include "IItemContainerAddable.h"
#include "IItemSpecificContainerAddable.h"

#include "IContainerRemoveable.h"
#include "ISpecificContainerRemoveable.h"

#include "IContainerClearable.h"

#include "ISpecificConstItemContainerTakeable.h"
#include "IConstItemContainerTakeable.h"
#include "ISpecificItemContainerTakeable.h"
#include "IItemContainerTakeable.h"
#include "ISpecificValueContainerTakeable.h"
#include "IValueContainerTakeable.h"

#include "ISizeContainerGetable.h"

#include "IConstForwardIterable.h"

#include "IForwardIterable.h"

#include "IStackContainer.h"
#include "IQueueContainer.h"
#include "ISearchContainer.h"
#include "ISortContainer.h"

namespace Containers
{
	template<class T, class TEnumerable>
	class ISingleLinkedList : public IValueContainerAddable<T, int>,
		public IValueSpecificContainerAddable<T>, public IItemContainerAddable<T, int>,
		public IItemSpecificContainerAddable<T>, public IContainerRemoveable<int>,
		public ISpecificContainerRemoveable, public IContainerClearable,
		public ISizeContainerGetable, public IValueContainerTakeable<T, TEnumerable>,
		public ISpecificValueContainerTakeable<T>, public IItemContainerTakeable<T, int>,
		public ISpecificItemContainerTakeable<T>, 
		public IConstItemContainerTakeable<T, TEnumerable>,
		public ISpecificConstItemContainerTakeable<T>, public IConstForwardIterable<T>,
		public IForwardIterable<T>, public IStackContainer<T>, public IQueueContainer<T>,
		public ISearchContainer<T, TEnumerable>, public ISortContainer<T, TEnumerable> {};
}