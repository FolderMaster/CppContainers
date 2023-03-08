#pragma once

#include "MinMaxStack.h"

namespace Containers
{
	template<class T>
	void MinMaxStack<T>::CreateByMinMaxStack(const MinMaxStack<T>& other)
	{
		this->_container = other._container;
		_minContainer = other._minContainer;
		_maxContainer = other._maxContainer;
	}

	template<class T>
	MinMaxStack<T>::MinMaxStack(IStackContainer<T>& container, IStackContainer<T>& minContainer,
		IStackContainer<T>& maxContainer) : Stack<T>(container), _minContainer(minContainer),
		_maxContainer(maxContainer)
	{
		minContainer.Clear();
		maxContainer.Clear();
	}

	template<class T>
	MinMaxStack<T>::MinMaxStack(const MinMaxStack<T>& other)
	{
		CreateByMinMaxStack(other);
	}

	template<class T>
	MinMaxStack<T>::~MinMaxStack() {}

	template<class T>
	MinMaxStack<T>& MinMaxStack<T>::operator=(const MinMaxStack<T>& other)
	{
		if (this != &other)
		{
			CreateByMinMaxStack(other);
		}
		return *this;
	}

	template<class T>
	void MinMaxStack<T>::PushValue(T value)
	{
		PushItem(value);
	}

	template<class T>
	void MinMaxStack<T>::PushItem(T& item)
	{
		this->_container.AddItemEnd(item);

		if (_minContainer.GetSize() > 0)
		{
			T& min = _minContainer.TakeItemEnd();
			_minContainer.AddItemEnd(item < min ? item : min);
		}
		else
		{
			_minContainer.AddItemEnd(item);
		}

		if (_maxContainer.GetSize() > 0)
		{
			T& max = _maxContainer.TakeItemEnd();
			_maxContainer.AddItemEnd(item > max ? item : max);
		}
		else
		{
			_maxContainer.AddItemEnd(item);
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