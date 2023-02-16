#pragma once

#include "IQueueContainer.h"
#include "IQueue.h"

namespace Containers
{
	template<class T>
	class Queue : public IQueue<T>
	{
	private:
		IQueueContainer<T>& _container;
	public:
		Queue(IQueueContainer<T>& container);

		~Queue();

		virtual void Enqueue(T value) override;

		virtual T Dequeue() override;
	};
}