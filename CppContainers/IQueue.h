#pragma once

namespace Containers
{
	template<class T>
	class IQueue
	{
	public:
		virtual void Enqueue(T value) = 0;

		virtual T Dequeue() = 0;
	};
}