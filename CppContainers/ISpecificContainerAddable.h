#pragma once

namespace Containers
{
	template <class TValue>
	class ISpecificContainerAddable
	{
	public:
		virtual void AddBegin(TValue value) = 0;

		virtual void AddEnd(TValue value) = 0;
	};
}