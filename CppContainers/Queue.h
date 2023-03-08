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

		void CreateByQueue(const Queue<T>& other);
	public:
		Queue(IQueueContainer<T>& container);

		Queue(const Queue<T>& other);

		~Queue();

		Queue<T>& operator=(const Queue<T>& other);

		void EnqueueValue(T value) override;

		void EnqueueItem(T& item) override;

		virtual T Dequeue() override;
	};
}