#pragma once

#include "FullIterator.h"

#include "IFullIterable.h"

namespace Containers
{
	template<class T>
	FullIterator<T>::FullIterator(void* pointer, IFullIterable<T>& iterable) :
		_pointer(pointer), _iterable(iterable) {}

	template<class T>
	bool FullIterator<T>::operator!=(FullIterator<T> it)
	{
		return _pointer != it._pointer;
	}

	template<class T>
	void FullIterator<T>::Forward()
	{
		_pointer = _iterable.Forward(_pointer);
	}

	template<class T>
	void FullIterator<T>::Back()
	{
		_pointer = _iterable.Back(_pointer);
	}

	template<class T>
	bool FullIterator<T>::IsForward() const
	{
		return _iterable.IsForward(_pointer);
	}

	template<class T>
	bool FullIterator<T>::IsBack() const
	{
		return _iterable.IsBack(_pointer);
	}

	template<class T>
	T FullIterator<T>::TakeValue() const
	{
		return _iterable.TakeValue(_pointer);
	}

	template<class T>
	T& FullIterator<T>::TakeItem()
	{
		return _iterable.TakeItem(_pointer);
	}

	template<class T>
	const T& FullIterator<T>::TakeConstItem() const
	{
		return _iterable.TakeConstItem(_pointer);
	}
}