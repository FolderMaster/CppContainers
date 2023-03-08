#pragma once

namespace Containers
{
	template <class TValue>
	class IValueSimpleContainerAddable
	{
	public:
		virtual void AddValue(TValue value) = 0;
	};
}