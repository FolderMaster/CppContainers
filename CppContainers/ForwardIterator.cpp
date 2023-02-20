#pragma once

#include "ForwardIterator.h"
#include "IForwardIterable.h"

namespace Containers
{
	template<class T>
	ForwardIterator<T>::ForwardIterator(void* pointer, IForwardIterable<T>& iterable) :
		_pointer(pointer), _iterable(iterable) {}

	template<class T>
	bool ForwardIterator<T>::operator!=(ForwardIterator<T> it)
	{
		return _pointer != it._pointer;
	}

	template<class T>
	void ForwardIterator<T>::Forward()
	{
		_pointer = _iterable.Forward(_pointer);
	}

	template<class T>
	bool ForwardIterator<T>::IsForward() const
	{
		return _iterable.IsForward(_pointer);
	}

	template<class T>
	T ForwardIterator<T>::TakeValue() const
	{
		return _iterable.TakeValue(_pointer);
	}

	template<class T>
	T& ForwardIterator<T>::TakeItem()
	{
		return _iterable.TakeItem(_pointer);
	}
}