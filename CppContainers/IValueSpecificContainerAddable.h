#pragma once

namespace Containers
{
	template <class TValue>
	class IValueSpecificContainerAddable
	{
	public:
		virtual void AddValueBegin(TValue value) = 0;

		virtual void AddValueEnd(TValue value) = 0;
	};
}