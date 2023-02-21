#pragma once

#include "ISizeContainerGetable.h"
#include "IValueContainerTakeable.h"

namespace Containers
{
	template<class TValue, class TEnumerable>
	class IValueSearchContainer : public ISizeContainerGetable,
		public IValueContainerTakeable<TValue, TEnumerable> {};
}