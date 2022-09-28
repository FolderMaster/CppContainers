#pragma once

#include "IAddable.h"
#include "IRemovable.h"
#include "ITakable.h"
#include "ISizable.h"
#include "ICapacitable.h"

namespace Containers
{
	template<class T>
	class IContainer : public IAddable<T>, public IRemovable<T>, public ITakable<T>, public
		ISizable, public ICapacitable
	{
	};
}