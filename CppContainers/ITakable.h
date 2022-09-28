#pragma once

namespace Containers
{
	template<class T>
	class ITakable
	{
	public:
		virtual T& Take() = 0;
	};
}