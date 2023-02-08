#pragma once

namespace Containers
{
	class ISpecificRemoveable
	{
	public:
		virtual void RemoveBegin() = 0;

		virtual void RemoveEnd() = 0;
	};
}