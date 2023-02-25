#pragma once

#include "ConstBackIterator.h"

#include "IConstBackIterable.h"

namespace Containers
{
	template<class T>
	ConstBackIterator<T>::ConstBackIterator(void* pointer, const IConstBackIterable<T>& iterable) : 
		_iterable(iterable), _pointer(pointer) {}

	template<class T>
	bool ConstBackIterator<T>::operator!=(ConstBackIterator<T> it)
	{
		return _pointer != it._pointer;
	}

	template<class T>
	void ConstBackIterator<T>::Forward()
	{
		_pointer = _iterable.Back(_pointer);
	}

	template<class T>
	bool ConstBackIterator<T>::IsForward() const
	{
		return _iterable.IsBack(_pointer);
	}

	template<class T>
	T ConstBackIterator<T>::TakeValue() const
	{
		return _iterable.TakeValue(_pointer);
	}

	template<class T>
	const T& ConstBackIterator<T>::TakeConstItem() const
	{
		return _iterable.TakeConstItem(_pointer);
	}
}