#pragma once

#include "ConstForwardIterator.h"
#include "IConstForwardIterable.h"

namespace Containers
{
	template<class T>
	ConstForwardIterator<T>::ConstForwardIterator(void* pointer, IConstForwardIterable<T>&
		iterable) : _pointer(pointer), _iterable(iterable) {}

	template<class T>
	bool ConstForwardIterator<T>::operator!=(ConstForwardIterator<T> it)
	{
		return _pointer != it._pointer;
	}

	template<class T>
	void ConstForwardIterator<T>::Forward()
	{
		_pointer = _iterable.Forward(_pointer);
	}

	template<class T>
	bool ConstForwardIterator<T>::IsForward()
	{
		return _iterable.IsForward(_pointer);
	}

	template<class T>
	T ConstForwardIterator<T>::TakeValue()
	{
		return _iterable.TakeValue(_pointer);
	}
}