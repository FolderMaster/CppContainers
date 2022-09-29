#pragma once

#include "IIterable.h"

namespace Containers
{
	template<class T>
	class IForwardIterable : public IIterable<T>
	{
	public:
		virtual void* Forward(void* pointer) = 0;
		virtual bool IsForward(void* pointer) = 0;
	};
}