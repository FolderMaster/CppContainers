#pragma once

#include "Stack.h"

namespace Containers
{
	template<class T>
	Stack<T>::Stack(IStackContainer<T>& container) : _container(container) {};

	template<class T>
	Stack<T>::~Stack() {}

	template<class T>
	void Stack<T>::Add(T value)
	{
		_container.AddEnd(value);
	}

	template<class T>
	T Stack<T>::TakeValue()
	{
		T result = _container.TakeValueEnd();
		_container.RemoveEnd();
		return result;
	}
}