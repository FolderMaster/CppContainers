#pragma once

namespace Containers
{
	class IBackIterableMoveable
	{
	public:
		virtual void* Back(void* pointer) const = 0;

		virtual bool IsBack(void* pointer) const = 0;
	};
}