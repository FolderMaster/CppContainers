#pragma once

#include "IForwardIterable.h"

namespace Containers
{
	template <class T>
	class IFullIterable : public IForwardIterable<T>
	{
	public:
		virtual void* Back(void* pointer) = 0;
		virtual bool IsBack(void* pointer) = 0;
	};
}