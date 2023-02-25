#pragma once

#include "IContainerAddable.h"
#include "IContainerRemoveable.h"
#include "IValueContainerTakeable.h"
#include "IItemContainerTakeable.h"
#include "IConstItemContainerTakeable.h"
#include "ISizeContainerGetable.h"

#include "SingleLinkedList.h"

namespace Containers
{
	template <class TKey, class TValue>
	class IMultiHashTable : public IContainerAddable<TValue, TKey>,
		public IContainerRemoveable<TKey>,
		public IValueContainerTakeable<SingleList<TValue>, TKey>,
		public IItemContainerTakeable<SingleList<TValue>, TKey>, 
		public IConstItemContainerTakeable<SingleList<TValue>, TKey>, public ISizeContainerGetable {};
}