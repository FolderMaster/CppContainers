#pragma once

#include "IAddable.h"
#include "IRemovable.h"
#include "ITakable.h"
#include "IIterable.h"
#include "ISizable.h"
#include "ICapacitable.h"

namespace Containers
{
	template <class T>
	class IContainer : public IAddable<T>, public IRemovable<T>, public ITakable<T>, public
		IIterable<T>, public ISizable, public ICapacitable
	{
	};
}