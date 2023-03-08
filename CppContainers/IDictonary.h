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

namespace Containers
{
	template <class TKey, class TValue>
	class IDictionary : public IValueContainerAddable<TValue, TKey>,
		public IItemContainerAddable<TValue, TKey>, public IContainerRemoveable<TKey>,
		public IValueContainerTakeable<TValue, TKey>,  public IItemContainerTakeable<TValue, TKey>,
		public IConstItemContainerTakeable<TValue, TKey>, public ISizeContainerGetable,
		public IConstForwardIterable<KeyValuePair<TKey, TValue>>, public IContainerClearable,
		public IConstBackIterable<KeyValuePair<TKey, TValue>> {};
}