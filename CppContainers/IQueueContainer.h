#pragma once

#include "IItemSpecificContainerAddable.h"

#include "ISpecificContainerRemoveable.h"

#include "IContainerClearable.h"

#include "ISpecificValueContainerTakeable.h"

#include "ISizeContainerGetable.h"

namespace Containers
{
	template<class T>
	class IQueueContainer : public IItemSpecificContainerAddable<T>,
		public ISpecificValueContainerTakeable<T>, public ISpecificContainerRemoveable,
		public ISizeContainerGetable, public IContainerClearable {};
}