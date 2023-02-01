#pragma once

namespace Containers
{
	class IBackIterable
	{
	public:
		virtual void* Back(void* pointer) = 0;

		virtual bool IsBack(void* pointer) = 0;
	};
}