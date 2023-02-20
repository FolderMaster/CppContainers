#pragma once

#include "ISizeContainerGetable.h"

namespace Containers
{
	template<class T>
	class IStack : public ISizeContainerGetable
	{
	public:
		virtual void Push(T value) = 0;

		virtual T Pop() = 0;
	};
}