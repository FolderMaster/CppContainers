#pragma once

namespace Containers
{
	template <class TValue>
	class ISpecificValueTakeable
	{
	public:
		virtual TValue TakeValueBegin() = 0;

		virtual TValue TakeValueEnd() = 0;
	};
}