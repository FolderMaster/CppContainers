#pragma once

#include "IContainerAddable.h"
#include "IContainerRemoveable.h"
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
	class IMultiDictionary : public IContainerAddable<TValue, TKey>,
		public IContainerRemoveable<TKey>,
		public IValueContainerTakeable<SingleList<TValue>, TKey>,
		public IItemContainerTakeable<SingleList<TValue>, TKey>,
		public IConstItemContainerTakeable<SingleList<TValue>, TKey>, public ISizeContainerGetable,
		public IConstForwardIterable<KeyValuePair<TKey, SingleList<TValue>>>,
		public IConstBackIterable<KeyValuePair<TKey, SingleList<TValue>>> {};
}