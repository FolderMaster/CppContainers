#pragma once

namespace Containers
{
	template <class T>
	class IAddable
	{
	public:
		virtual void Add(T value = T()) = 0;
	};
}