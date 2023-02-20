#pragma once

namespace Containers
{
	class IForwardIterableMoveable
	{
	public:
		virtual void* Forward(void* pointer) const = 0;

		virtual bool IsForward(void* pointer) const = 0;
	};
}