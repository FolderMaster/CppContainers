#pragma once

#include "Queue.h"

namespace Containers
{
	template<class T>
	Queue<T>::Queue(IQueueContainer<T>& container) : _container(container) {}

	template<class T>
	Queue<T>::~Queue() {}

	template<class T>
	void Queue<T>::Enqueue(T value)
	{
		_container.AddBegin(value);
	}

	template<class T>
	T Queue<T>::Dequeue()
	{
		T result = _container.TakeValueEnd();
		_container.RemoveEnd();
		return result;
	}
}