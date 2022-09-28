#pragma once

#include "IContainer.h"
#include "ISpecificAddable.h"
#include "ISpecificRemovable.h"
#include "ISpecificTakable.h"

namespace Containers
{
	template<class T>
	class ISpecificContainer : public IContainer<T>, public ISpecificAddable<T>, public
		ISpecificRemovable<T>, public ISpecificTakable<T>
	{
	};
}