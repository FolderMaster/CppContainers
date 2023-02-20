#pragma once

namespace Containers
{
	class ISizeContainerGetable
	{
	public:
		virtual size_t GetSize() const = 0;

		virtual bool IsEmpty() const = 0;
	};
}