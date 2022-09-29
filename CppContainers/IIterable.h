#pragma once

namespace Containers
{
	template <class T>
	class IIterable
	{
	public:
		virtual T& Take(void* pointer) = 0;
	};
}