#pragma once

#include "IForwardIterator.h"

namespace Containers
{
	template <class T>
	class IFullIterator : public IForwardIterator<T>
	{
	public:
		virtual void Back() = 0;
		virtual bool IsBack() = 0;
	};
}