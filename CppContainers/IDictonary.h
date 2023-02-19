#pragma once

#include "IAddable.h"
#include "IRemoveable.h"
#include "IValueContainerTakeable.h"
#include "IItemContainerTakeable.h"

namespace Containers
{
	template <class TKey, class TValue>
	class IDictionary : public IAddable<TValue, TKey>, public IRemoveable<TKey>,
		public IValueContainerTakeable<TValue, TKey>,  public IItemContainerTakeable<TValue, TKey>
	{};
}