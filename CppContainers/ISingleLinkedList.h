#pragma once

#include "IAddable.h"
#include "ISpecificAddable.h"
#include "IRemoveable.h"
#include "ISpecificRemoveable.h"
#include "IItemContainerTakeable.h"
#include "ISpecificValueTakeable.h"
#include "IValueContainerTakeable.h"
#include "ISizeGetable.h"
#include "IConstForwardIterable.h"
#include "IStackContainer.h"
#include "IQueueContainer.h"

namespace Containers
{
	template<class T, class TEnumerable>
	class ISingleLinkedList : public IAddable<T, int>, public ISpecificAddable<T>,
		public IRemoveable<int>, public ISpecificRemoveable, public ISizeGetable,
		public IValueContainerTakeable<T, TEnumerable>, public ISpecificValueTakeable<T>,
		public IItemContainerTakeable<T, int>, public IConstForwardIterable<T>,
		public IStackContainer<T>, public IQueueContainer<T> {};
}