#pragma once

#include "ITakable.h"

namespace Containers
{
	template<class T>
	class ISpecificTakable : public ITakable<T>
	{
	public:
		virtual T& TakeBegin() = 0;

		virtual T& TakeEnd() = 0;
	};
}