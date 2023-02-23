#pragma once

#include "IContainerAddable.h"
#include "IContainerRemoveable.h"
#include "IValueContainerTakeable.h"
#include "IItemContainerTakeable.h"
#include "ISizeContainerGetable.h"
#include "IConstForwardIterable.h"
#include "IConstBackIterable.h"
#include "KeyValuePair.h"

namespace Containers
{
	template <class TKey, class TValue>
	class IDictionary : public IContainerAddable<TValue, TKey>, public IContainerRemoveable<TKey>,
		public IValueContainerTakeable<TValue, TKey>,  public IItemContainerTakeable<TValue, TKey>,
		public ISizeContainerGetable, public IConstForwardIterable<KeyValuePair<TKey, TValue>>,
		public IConstBackIterable<KeyValuePair<TKey, TValue>> {};
}