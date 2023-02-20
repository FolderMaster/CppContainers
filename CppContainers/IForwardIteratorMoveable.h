#pragma once

namespace Containers
{
	class IForwardIteratorMoveable
	{
	public:
		virtual void Forward() = 0;

		virtual bool IsForward() const = 0;
	};
}