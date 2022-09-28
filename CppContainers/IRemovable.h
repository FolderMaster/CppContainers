#pragma once

namespace Containers
{
	template<class T>
	class IRemovable
	{
	public:
		virtual void Remove() = 0;
	};
}