#pragma once

#include "MinStack.h"

namespace Containers
{
	template<class T>
	MinStack<T>::MinStack(IStackContainer<T>& container, IStackContainer<T>& minContainer) : 
		Stack<T>(container), _minContainer(minContainer) {}

	template<class T>
	MinStack<T>::~MinStack() {}

	template<class T>
	void MinStack<T>::Add(T value)
	{
		this->_container.AddEnd(value);

		if (_minContainer.GetSize() > 0)
		{
			T min = _minContainer.TakeValueEnd();
			_minContainer.AddEnd(value < min ? value : min);
		}
		else
		{
			_minContainer.AddEnd(value);
		}
	}

	template<class T>
	T MinStack<T>::TakeValue()
	{
		T result = this->_container.TakeValueEnd();

		this->_container.RemoveEnd();
		_minContainer.RemoveEnd();

		return result;
	}

	template<class T>
	T MinStack<T>::GetMin()
	{
		return _minContainer.TakeValueEnd();
	}
}