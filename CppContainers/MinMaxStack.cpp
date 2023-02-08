#include "MinMaxStack.h"

namespace Containers
{
	template<class T>
	MinMaxStack<T>::MinMaxStack(IStackContainer<T>& container, IStackContainer<T>& minContainer,
		IStackContainer<T>& maxContainer) : MinStack<T>(container, minContainer), MaxStack<T>(container, maxContainer) {}

	template<class T>
	MinMaxStack<T>::~MinMaxStack() {}

	template<class T>
	void MinMaxStack<T>::Add(T value)
	{
		((MinStack<T>*)this)->_container.AddEnd(value);

		if (this->_minContainer.GetSize() > 0)
		{
			T min = this->_minContainer.TakeValueEnd();
			this->_minContainer.AddEnd(value < min ? value : min);
		}
		else
		{
			this->_minContainer.AddEnd(value);
		}

		if (this->_maxContainer.GetSize() > 0)
		{
			T max = this->_maxContainer.TakeValueEnd();
			this->_maxContainer.AddEnd(value > max ? value : max);
		}
		else
		{
			this->_maxContainer.AddEnd(value);
		}
	}

	template<class T>
	T MinMaxStack<T>::TakeValue()
	{
		T result = ((MinStack<T>*)this)->_container.TakeValueEnd();

		((MinStack<T>*)this)->_container.RemoveEnd();
		this->_minContainer.RemoveEnd();
		this->_maxContainer.RemoveEnd();

		return result;
	}
}