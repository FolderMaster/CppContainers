#pragma once

namespace Containers
{
	class IForwardIterable
	{
	public:
		virtual void* Forward(void* pointer) = 0;

		virtual bool IsForward(void* pointer) = 0;
	};
}