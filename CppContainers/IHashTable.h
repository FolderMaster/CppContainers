#pragma once

#include "IValueContainerAddable.h"
#include "IItemContainerAddable.h"

#include "IContainerRemoveable.h"

#include "IContainerClearable.h"

#include "IValueContainerTakeable.h"
#include "IItemContainerTakeable.h"
#include "IConstItemContainerTakeable.h"

#include "ISizeContainerGetable.h"

namespace Containers
{
	template <class TKey, class TValue>
	class IHashTable : public IValueContainerAddable<TValue, TKey>,
		public IItemContainerAddable<TValue, TKey>, public IContainerRemoveable<TKey>,
		public IValueContainerTakeable<TValue, TKey>, public IItemContainerTakeable<TValue, TKey>,
		public IConstItemContainerTakeable<TValue, TKey>, public IContainerClearable,
		public ISizeContainerGetable {};
}