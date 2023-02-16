#pragma once

namespace Containers
{
	template<class T>
	class IStack
	{
	public:
		virtual void Push(T value) = 0;

		virtual T Pop() = 0;
	};
}