#pragma once

#include "ITakable.h"

namespace Containers
{
	template <class T>
	class IIndexTakable : public ITakable<T>
	{
	public:
		virtual T& Take(int index) = 0;

		virtual T& TakeBegin() = 0;

		virtual T& TakeEnd() = 0;
	};
}