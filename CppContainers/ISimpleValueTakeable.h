#pragma once

namespace Containers
{
	template <class TValue>
	class ISimpleValueTakeable
	{
	public:
		virtual TValue TakeValue() = 0;
	};
}