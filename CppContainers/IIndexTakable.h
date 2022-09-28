#pragma once

#include "ISpecificTakable.h"

namespace Containers
{
	template<class T>
	class IIndexTakable : public ISpecificTakable<T>
	{
	public:
		virtual T& Take(int index) = 0;
	};
}