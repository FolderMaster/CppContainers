#pragma once

#include "IQueue.h"
#include "Stack.h"

namespace Containers
{
	template<class T>
	class StacksQueue : IQueue<T>
	{
	private:
		Stack<T> _enqueueStack;

		Stack<T> _dequeueStack;

		void CreateByStacksQueue(const StacksQueue<T>& other);
	public:
		StacksQueue(IStackContainer<T>& enqueueContainer, IStackContainer<T>& dequeueContainer);

		StacksQueue(const StacksQueue<T>& other);

		~StacksQueue();

		StacksQueue<T>& operator=(const StacksQueue<T>& other);

		void EnqueueValue(T value) override;

		void EnqueueItem(T& item) override;

		T Dequeue() override;
	};
}