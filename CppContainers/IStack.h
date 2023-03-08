#pragma once

#include "ISizeContainerGetable.h"

namespace Containers
{
	template<class T>
	class IStack : public ISizeContainerGetable
	{
	public:
		virtual void PushValue(T value) = 0;

		virtual void PushItem(T& item) = 0;

		virtual T Pop() = 0;
	};
}