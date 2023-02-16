#include "MinMaxStack.h"

namespace Containers
{
	template<class T>
	MinMaxStack<T>::MinMaxStack(IStackContainer<T>& container, IStackContainer<T>& minContainer,
		IStackContainer<T>& maxContainer) : Stack<T>(container), _minContainer(minContainer),
		_maxContainer(maxContainer) {}

	template<class T>
	MinMaxStack<T>::~MinMaxStack() {}

	template<class T>
	void MinMaxStack<T>::Push(T value)
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
	T MinMaxStack<T>::Pop()
	{
		T result = this->_container.TakeValueEnd();

		this->_container.RemoveEnd();
		_minContainer.RemoveEnd();
		_maxContainer.RemoveEnd();

		return result;
	}

	template<class T>
	T MinMaxStack<T>::GetMin()
	{
		return _minContainer.TakeValueEnd();
	}

	template<class T>
	T MinMaxStack<T>::GetMax()
	{
		return _maxContainer.TakeValueEnd();
	}
}