#pragma once

#include "IValueContainerAddable.h"
#include "IItemContainerAddable.h"

#include "IContainerRemoveable.h"

#include "IContainerClearable.h"

#include "IValueContainerTakeable.h"
#include "IItemContainerTakeable.h"
#include "IConstItemContainerTakeable.h"

#include "ISizeContainerGetable.h"

#include "IConstForwardIterable.h"
#include "IConstBackIterable.h"

#include "KeyValuePair.h"
#include "SingleLinkedList.h"

namespace Containers
{
	template <class TKey, class TValue>
	class IMultiDictionary : public IValueContainerAddable<TValue, TKey>,
		public IItemContainerAddable<TValue, TKey>, public IContainerRemoveable<TKey>,
		public IContainerClearable, public IValueContainerTakeable<SingleList<TValue>, TKey>,
		public IItemContainerTakeable<SingleList<TValue>, TKey>,
		public IConstItemContainerTakeable<SingleList<TValue>, TKey>, public ISizeContainerGetable,
		public IConstForwardIterable<KeyValuePair<TKey, SingleList<TValue>>>,
		public IConstBackIterable<KeyValuePair<TKey, SingleList<TValue>>> {};
}