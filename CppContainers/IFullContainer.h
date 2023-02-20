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
#include "IConstBackIterable.h"
#include "IForwardIterable.h"
#include "IBackIterable.h"
#include "IStackContainer.h"
#include "IQueueContainer.h"

namespace Containers
{
	template<class T, class TEnumerable>
	class IFullContainer : public IContainerAddable<T, TEnumerable>,
		public ISpecificContainerAddable<T>, public IContainerRemoveable<TEnumerable>,
		public ISpecificContainerRemoveable, public IContainerClearable,
		public ISizeContainerGetable, public IValueContainerTakeable<T, TEnumerable>,
		public ISpecificValueContainerTakeable<T>, public IItemContainerTakeable<T, TEnumerable>,
		public IConstForwardIterable<T>, public IConstBackIterable<T>, public IForwardIterable<T>,
		public IBackIterable<T>, public IStackContainer<T>, public IQueueContainer<T> {};
}