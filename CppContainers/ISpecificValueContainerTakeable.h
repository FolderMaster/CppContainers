#pragma once

namespace Containers
{
	template <class TValue>
	class ISpecificValueContainerTakeable
	{
	public:
		virtual TValue TakeValueBegin() const = 0;

		virtual TValue TakeValueEnd() const = 0;
	};
}