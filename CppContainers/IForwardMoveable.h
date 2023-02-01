#pragma once

namespace Containers
{
	class IForwardMoveable
	{
	public:
		virtual void Forward() = 0;

		virtual bool IsForward() = 0;
	};
}