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
#include "IConstFullIterable.h"
#include "IConstBackIterable.h"
#include "IForwardIterable.h"
#include "IFullIterable.h"
#include "IBackIterable.h"

#include "IStackContainer.h"
#include "IQueueContainer.h"
#include "ISearchContainer.h"
#include "ISortContainer.h"

namespace Containers
{
	template<class T, class TEnumerable>
	class IFullContainer : public IValueContainerAddable<T, TEnumerable>,
		public IValueSpecificContainerAddable<T>, public IItemContainerAddable<T, TEnumerable>,
		public IItemSpecificContainerAddable<T>, public IContainerRemoveable<TEnumerable>,
		public ISpecificContainerRemoveable, public IContainerClearable,
		public ISizeContainerGetable, public IValueContainerTakeable<T, TEnumerable>,
		public ISpecificValueContainerTakeable<T>, public IItemContainerTakeable<T, TEnumerable>,
		public ISpecificItemContainerTakeable<T>,
		public IConstItemContainerTakeable<T, TEnumerable>,
		public ISpecificConstItemContainerTakeable<T>, public IConstForwardIterable<T>,
		public IConstBackIterable<T>, public IForwardIterable<T>, public IBackIterable<T>,
		public IFullIterable<T>, public IConstFullIterable<T>, public IStackContainer<T>,
		public IQueueContainer<T>, public ISearchContainer<T, TEnumerable>,
		public ISortContainer<T, TEnumerable> {};
}