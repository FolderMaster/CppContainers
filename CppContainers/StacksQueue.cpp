#pragma once

#include "StacksQueue.h"

namespace Containers
{
	template<class T>
	void StacksQueue<T>::CreateByStacksQueue(const StacksQueue<T>& other)
	{
		_enqueueStack = other._enqueueStack;
		_dequeueStack = other._dequeueStack;
	}

	template<class T>
	StacksQueue<T>::StacksQueue(IStackContainer<T>& enqueueContainer, IStackContainer<T>&
		dequeueContainer) : _enqueueStack(Stack<T>(enqueueContainer)),
		_dequeueStack(Stack<T>(dequeueContainer)) {}

	template<class T>
	StacksQueue<T>::StacksQueue(const StacksQueue<T>& other)
	{
		CreateByStacksQueue(other);
	}

	template<class T>
	StacksQueue<T>::~StacksQueue() {}

	template<class T>
	StacksQueue<T>& StacksQueue<T>::operator=(const StacksQueue<T>& other)
	{
		if (this != &other)
		{
			CreateByStacksQueue(other);
		}
		return *this;
	}

	template<class T>
	void StacksQueue<T>::EnqueueValue(T value)
	{
		_enqueueStack.PushValue(value);
	}

	template<class T>
	void StacksQueue<T>::EnqueueItem(T& item)
	{
		_enqueueStack.PushItem(item);
	}

	template<class T>
	T StacksQueue<T>::Dequeue()
	{
		if (_dequeueStack.IsEmpty())
		{
			while (!_enqueueStack.IsEmpty())
			{
				_dequeueStack.PushValue(_enqueueStack.Pop());
			}
		}
		return _dequeueStack.Pop();
	}
}