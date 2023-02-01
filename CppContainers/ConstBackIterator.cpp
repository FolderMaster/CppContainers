#pragma once

#include "ConstBackIterator.h"
#include "IConstBackIterable.h"

namespace Containers
{
	template<class T>
	ConstBackIterator<T>::ConstBackIterator(void* pointer, IConstBackIterable<T>& iterable) : 
		_iterable(iterable), _pointer(pointer) {}

	template<class T>
	bool ConstBackIterator<T>::operator!=(ConstBackIterator<T> it)
	{
		return _pointer != it._pointer;
	}

	template<class T>
	void ConstBackIterator<T>::Back()
	{
		_pointer = _iterable.Back(_pointer);
	}

	template<class T>
	bool ConstBackIterator<T>::IsBack()
	{
		return _iterable.IsBack(_pointer);
	}

	template<class T>
	T ConstBackIterator<T>::TakeValue()
	{
		return _iterable.TakeValue(_pointer);
	}
}