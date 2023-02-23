#pragma once

namespace Containers
{
	class ICapacityContainerGetable
	{
	public:
		virtual size_t GetCapacity() const = 0;
	};
}