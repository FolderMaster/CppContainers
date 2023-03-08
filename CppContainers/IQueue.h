#pragma once

namespace Containers
{
	template<class T>
	class IQueue
	{
	public:
		virtual void EnqueueValue(T value) = 0;

		virtual void EnqueueItem(T& item) = 0;

		virtual T Dequeue() = 0;
	};
}