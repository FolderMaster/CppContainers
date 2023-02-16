#pragma once

#include "Stack.h"

namespace Containers
{
	template<class T>
	Stack<T>::Stack(IStackContainer<T>& container) : _container(container) {}

	template<class T>
	Stack<T>::~Stack() {}

	template<class T>
	void Stack<T>::Push(T value)
	{
		_container.AddEnd(value);
	}

	template<class T>
	T Stack<T>::Pop()
	{
		T result = _container.TakeValueEnd();
		_container.RemoveEnd();
		return result;
	}
}