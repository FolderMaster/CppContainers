#pragma once

#include "Queue.h"

namespace Containers
{
	template<class T>
	void Queue<T>::CreateByQueue(const Queue<T>& other)
	{
		_container = other._container;
	}

	template<class T>
	Queue<T>::Queue(IQueueContainer<T>& container) : _container(container)
	{
		container.Clear();
	}

	template<class T>
	Queue<T>::Queue(const Queue<T>& other)
	{
		CreateByQueue(other);
	}

	template<class T>
	Queue<T>::~Queue() {}

	template<class T>
	Queue<T>& Queue<T>::operator=(const Queue<T>& other)
	{
		if (this != &other)
		{
			CreateByQueue(other);
		}
		return *this;
	}

	template<class T>
	void Queue<T>::EnqueueValue(T value)
	{
		EnqueueItem(value);
	}

	template<class T>
	void Queue<T>::EnqueueItem(T& item)
	{
		_container.AddItemBegin(item);
	}

	template<class T>
	T Queue<T>::Dequeue()
	{
		T result = _container.TakeValueEnd();
		_container.RemoveEnd();
		return result;
	}
}