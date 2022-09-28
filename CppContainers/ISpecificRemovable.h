#pragma once

#include "IRemovable.h"

namespace Containers
{
	template<class T>
	class ISpecificRemovable : public IRemovable<T>
	{
	public:
		virtual void RemoveBegin() = 0;

		virtual void RemoveEnd() = 0;
	};
}