#pragma once

#include "IContainerAddable.h"
#include "IContainerRemoveable.h"
#include "IValueContainerTakeable.h"
#include "IItemContainerTakeable.h"
#include "ISizeContainerGetable.h"

namespace Containers
{
	template <class TKey, class TValue>
	class IHashTable : public IContainerAddable<TValue, TKey>, public IContainerRemoveable<TKey>,
		public IValueContainerTakeable<TValue, TKey>, public IItemContainerTakeable<TValue, TKey>,
		public ISizeContainerGetable {};
}