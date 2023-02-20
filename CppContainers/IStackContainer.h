#pragma once

#include "ISpecificContainerAddable.h"
#include "ISpecificContainerRemoveable.h"
#include "ISpecificValueContainerTakeable.h"
#include "ISizeContainerGetable.h"

namespace Containers
{
	template<class T>
	class IStackContainer : public ISpecificContainerAddable<T>,
		public ISpecificValueContainerTakeable<T>, public ISpecificContainerRemoveable,
		public ISizeContainerGetable {};
}