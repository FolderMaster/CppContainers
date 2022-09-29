#pragma once

namespace Containers
{
	template <class T>
	class IIterator
	{
	public:
		virtual T& Take() = 0;
	};
}