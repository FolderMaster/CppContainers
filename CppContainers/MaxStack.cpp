#pragma once

#include "MaxStack.h"
#include "MinStack.h"

namespace Containers
{
	template<class T>
	MaxStack<T>::MaxStack(IStackContainer<T>& container, IStackContainer<T>& maxContainer) : 
		Stack<T>(container), _maxContainer(maxContainer) {}

	template<class T>
	MaxStack<T>::~MaxStack() {}

	template<class T>
	void MaxStack<T>::Add(T value)
	{
		this->_container.AddEnd(value);

		if (_maxContainer.GetSize() > 0)
		{
			T max = _maxContainer.TakeValueEnd();
			_maxContainer.AddEnd(value > max ? value : max);
		}
		else
		{
			_maxContainer.AddEnd(value);
		}
	}

	template<class T>
	T MaxStack<T>::TakeValue()
	{
		T result = this->_container.TakeValueEnd();

		this->_container.RemoveEnd();
		_maxContainer.RemoveEnd();

		return result;
	}

	template<class T>
	T MaxStack<T>::GetMax()
	{
		return _maxContainer.TakeValueEnd();
	}
}