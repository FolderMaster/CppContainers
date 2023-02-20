#pragma once

#include "IContainerAddable.h"
#include "ISpecificContainerAddable.h"
#include "IContainerRemoveable.h"
#include "ISpecificContainerRemoveable.h"
#include "IContainerClearable.h"
#include "IItemContainerTakeable.h"
#include "ISpecificValueContainerTakeable.h"
#include "IValueContainerTakeable.h"
#include "ISizeContainerGetable.h"
#include "IConstForwardIterable.h"
#include "IForwardIterable.h"
#include "IStackContainer.h"
#include "IQueueContainer.h"

namespace Containers
{
	template<class T, class TEnumerable>
	class ISingleLinkedList : public IContainerAddable<T, int>,
		public ISpecificContainerAddable<T>, public IContainerRemoveable<int>,
		public ISpecificContainerRemoveable, public IContainerClearable,
		public ISizeContainerGetable, public IValueContainerTakeable<T, TEnumerable>,
		public ISpecificValueContainerTakeable<T>, public IItemContainerTakeable<T, int>,
		public IConstForwardIterable<T>, public IForwardIterable<T>, public IStackContainer<T>,
		public IQueueContainer<T> {};
}