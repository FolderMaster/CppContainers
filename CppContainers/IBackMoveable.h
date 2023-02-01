#pragma once

namespace Containers
{
	class IBackMoveable
	{
	public:
		virtual void Back() = 0;

		virtual bool IsBack() = 0;
	};
}