#pragma once

#include "IItemSpecificContainerAddable.h"

#include "ISpecificContainerRemoveable.h"

#include "IContainerClearable.h"

#include "ISpecificValueContainerTakeable.h"
#include "ISpecificItemContainerTakeable.h"

#include "ISizeContainerGetable.h"

namespace Containers
{
	template<class T>
	class IStackContainer : public IItemSpecificContainerAddable<T>,
		public ISpecificValueContainerTakeable<T>, public ISpecificItemContainerTakeable<T>,
		public ISpecificContainerRemoveable, public ISizeContainerGetable,
		public IContainerClearable {};
}