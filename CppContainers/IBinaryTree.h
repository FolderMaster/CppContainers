#pragma once

#include "IValueSimpleContainerAddable.h"

#include "IContainerRemoveable.h"

#include "IContainerClearable.h"

#include "IValueContainerTakeable.h"
#include "IConstItemContainerTakeable.h"

#include "ISizeContainerGetable.h"

namespace Containers
{
	template <class T>
	class IBinaryTree : public IValueSimpleContainerAddable<T>, public IContainerRemoveable<T>,
		public IContainerClearable, public IValueContainerTakeable<T, T>,
		public IConstItemContainerTakeable<T, T>, public ISizeContainerGetable {};
}