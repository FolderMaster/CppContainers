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
#include "IConstBackIterable.h"
#include "IStackContainer.h"
#include "IQueueContainer.h"

namespace Containers
{
	template<class T, class TEnumerable>
	class IFullContainer : public IAddable<T, TEnumerable>, public ISpecificAddable<T>,
		public IRemoveable<TEnumerable>, public ISpecificRemoveable, public ISizeGetable,
		public IValueContainerTakeable<T, TEnumerable>, public ISpecificValueTakeable<T>,
		public IItemContainerTakeable<T, TEnumerable>, public IConstForwardIterable<T>,
		public IConstBackIterable<T>, public IStackContainer<T>, public IQueueContainer<T> {};
}