#pragma once

#include "IIndexContainer.h"
#include "IForwardIterable.h"

namespace Containers
{
	template <class T>
	class ISingleList : public IIndexContainer<T>, public IForwardIterable<T>
	{
	};
}