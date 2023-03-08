#pragma once

#include "Stack.h"

namespace Containers
{
	template<class T>
	void Stack<T>::CreateByStack(const Stack<T>& other)
	{
		_container = other._container;
	}

	template<class T>
	size_t Stack<T>::GetSize() const
	{
		return _container.GetSize();
	}

	template<class T>
	bool Stack<T>::IsEmpty() const
	{
		return _container.IsEmpty();
	}

	template<class T>
	Stack<T>::Stack(IStackContainer<T>& container) : _container(container)
	{
		container.Clear();
	}

	template<class T>
	Stack<T>::Stack(const Stack<T>& other)
	{
		CreateByStack(other);
	}

	template<class T>
	Stack<T>::~Stack() {}

	template<class T>
	Stack<T>& Stack<T>::operator=(const Stack<T>& other)
	{
		if (this != &other)
		{
			CreateByStack(other);
		}
		return *this;
	}

	template<class T>
	void Stack<T>::PushValue(T value)
	{
		PushItem(value);
	}

	template<class T>
	void Stack<T>::PushItem(T& item)
	{
		_container.AddItemEnd(item);
	}

	template<class T>
	T Stack<T>::Pop()
	{
		T result = _container.TakeValueEnd();
		_container.RemoveEnd();
		return result;
	}
}