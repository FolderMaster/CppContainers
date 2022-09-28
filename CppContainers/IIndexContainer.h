#pragma once

#include "ISpecificContainer.h"
#include "IIndexAddable.h"
#include "IIndexRemovable.h"
#include "IIndexTakable.h"

namespace Containers
{
	template<class T>
	class IIndexContainer : public ISpecificContainer<T>, public IIndexAddable<T>, public 
		IIndexRemovable<T>, public IIndexTakable<T>
	{
	};
}