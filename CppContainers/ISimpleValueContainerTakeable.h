#pragma once

namespace Containers
{
	template <class TValue>
	class ISimpleValueContainerTakeable
	{
	public:
		virtual TValue TakeValue() const = 0;
	};
}