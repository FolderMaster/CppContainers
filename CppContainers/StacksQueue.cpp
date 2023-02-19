#pragma once

#include "StacksQueue.h"

namespace Containers
{
	template<class T>
	StacksQueue<T>::StacksQueue(IStackContainer<T>& enqueueContainer, IStackContainer<T>&
		dequeueContainer) : _enqueueStack(Stack<T>(enqueueContainer)),
		_dequeueStack(Stack<T>(dequeueContainer)) {}

	template<class T>
	StacksQueue<T>::~StacksQueue() {}

	template<class T>
	void StacksQueue<T>::Enqueue(T value)
	{
		_enqueueStack.Push(value);
	}

	template<class T>
	T StacksQueue<T>::Dequeue()
	{
		if (_dequeueStack.IsEmpty())
		{
			while (!_enqueueStack.IsEmpty())
			{
				_dequeueStack.Push(_enqueueStack.Pop());
			}
		}
		return _dequeueStack.Pop();
	}
}