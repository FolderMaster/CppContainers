#pragma once

namespace Containers
{
	template <class TValue>
	class ISimpleAddable
	{
	public:
		virtual void Add(TValue value) = 0;
	};
}