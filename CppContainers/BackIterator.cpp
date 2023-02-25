#pragma once

#include "BackIterator.h"

#include "IBackIterable.h"

namespace Containers
{
	template<class T>
	BackIterator<T>::BackIterator(void* pointer, IBackIterable<T>& iterable) :
		_pointer(pointer), _iterable(iterable) {}

	template<class T>
	bool BackIterator<T>::operator!=(BackIterator<T> it)
	{
		return _pointer != it._pointer;
	}

	template<class T>
	void BackIterator<T>::Forward()
	{
		_pointer = _iterable.Back(_pointer);
	}

	template<class T>
	bool BackIterator<T>::IsForward() const
	{
		return _iterable.IsBack(_pointer);
	}

	template<class T>
	T BackIterator<T>::TakeValue() const
	{
		return _iterable.TakeValue(_pointer);
	}

	template<class T>
	T& BackIterator<T>::TakeItem()
	{
		return _iterable.TakeItem(_pointer);
	}

	template<class T>
	const T& BackIterator<T>::TakeConstItem() const
	{
		return _iterable.TakeConstItem(_pointer);
	}
}