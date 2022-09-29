#pragma once

#include "IIterator.h"

namespace Containers
{
	template <class T>
	class IForwardIterator : public IIterator<T>
	{
	public:
		virtual void Forward() = 0;
		virtual bool IsForward() = 0;
	};
}