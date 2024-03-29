#pragma once

namespace Containers
{
	class ISpecificContainerRemoveable
	{
	public:
		virtual void RemoveBegin() = 0;

		virtual void RemoveEnd() = 0;
	};
}