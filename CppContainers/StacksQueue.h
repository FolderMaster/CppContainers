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
	public:
		StacksQueue(IStackContainer<T>& enqueueContainer, IStackContainer<T>& dequeueContainer);

		~StacksQueue();

		void Enqueue(T value) override;

		T Dequeue() override;
	};
}