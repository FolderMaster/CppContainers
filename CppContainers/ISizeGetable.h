#pragma once

namespace Containers
{
	class ISizeGetable
	{
	public:
		virtual size_t GetSize() = 0;

		virtual bool IsEmpty() = 0;
	};
}