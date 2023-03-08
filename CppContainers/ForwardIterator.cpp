#pragma once

#include "ForwardIterator.h"

#include "IForwardIterable.h"

namespace Containers
{
	template<class T>
	ForwardIterator<T>::ForwardIterator(void* pointer, IForwardIterable<T>* iterable) :
		_pointer(pointer), _iterable(iterable) {}

	template<class T>
	ForwardIterator<T>::ForwardIterator(const ForwardIterator<T>& other) :
		_pointer(other._pointer), _iterable(other._iterable) {}

	template<class T>
	ForwardIterator<T>& ForwardIterator<T>::operator=(const ForwardIterator<T>& other)
	{
		if (this != &other)
		{
			_pointer = other._pointer;
			_iterable = other._iterable;
		}
		return *this;
	}

	template<class T>
	bool ForwardIterator<T>::operator!=(ForwardIterator<T> it)
	{
		return _pointer != it._pointer;
	}

	template<class T>
	void ForwardIterator<T>::Forward()
	{
		_pointer = _iterable->Forward(_pointer);
	}

	template<class T>
	bool ForwardIterator<T>::IsForward() const
	{
		return _iterable->IsForward(_pointer);
	}

	template<class T>
	T ForwardIterator<T>::TakeValue() const
	{
		return _iterable->TakeValue(_pointer);
	}

	template<class T>
	T& ForwardIterator<T>::TakeItem()
	{
		return _iterable->TakeItem(_pointer);
	}

	template<class T>
	const T& ForwardIterator<T>::TakeConstItem() const
	{
		return _iterable->TakeConstItem(_pointer);
	}
}