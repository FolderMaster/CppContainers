#pragma once

#include "ISingleList.h"
#include "IFullIterable.h"

namespace Containers
{
	template <class T>
	class IFullContainer : public ISingleList<T>, public IFullIterable<T>
	{
	};
}