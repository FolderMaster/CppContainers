#pragma once

#include "IContainer.h"
#include "IFullIterable.h"

namespace Containers
{
	template <class T>
	class ITree : public IContainer<T>, public IFullIterable<T>
	{
	};
}