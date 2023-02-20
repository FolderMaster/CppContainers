#pragma once

namespace Containers
{
	class IBackIteratorMoveable
	{
	public:
		virtual void Back() = 0;

		virtual bool IsBack() const = 0;
	};
}