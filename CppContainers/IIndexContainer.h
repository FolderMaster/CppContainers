#pragma once

#include "IContainer.h"
#include "IIndexAddable.h"
#include "IIndexRemovable.h"
#include "IIndexTakable.h"
#include "IIndexSizable.h"

namespace Containers
{
	template <class T>
	class IIndexContainer : public IContainer<T>, public IIndexAddable<T>, public 
		IIndexRemovable<T>, public IIndexTakable<T>,  public IIndexSizable
	{
	};
}