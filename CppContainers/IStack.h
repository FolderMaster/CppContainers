#pragma once

#include "ISizeGetable.h"

namespace Containers
{
	template<class T>
	class IStack : public ISizeGetable
	{
	public:
		virtual void Push(T value) = 0;

		virtual T Pop() = 0;
	};
}