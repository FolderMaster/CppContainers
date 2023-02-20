#pragma once

namespace Containers
{
	template <class TValue>
	class ISimpleContainerAddable
	{
	public:
		virtual void Add(TValue value) = 0;
	};
}