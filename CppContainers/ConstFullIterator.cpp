#pragma once

#include "ConstFullIterator.h"

#include "IConstFullIterable.h"

namespace Containers
{
	template<class T>
	ConstFullIterator<T>::ConstFullIterator(void* pointer, const IConstFullIterable<T>& iterable) :
		_pointer(pointer), _iterable(iterable) {}

	template<class T>
	bool ConstFullIterator<T>::operator!=(ConstFullIterator<T> it)
	{
		return _pointer != it._pointer;
	}

	template<class T>
	void ConstFullIterator<T>::Forward()
	{
		_pointer = _iterable.Forward(_pointer);
	}

	template<class T>
	void ConstFullIterator<T>::Back()
	{
		_pointer = _iterable.Back(_pointer);
	}

	template<class T>
	bool ConstFullIterator<T>::IsForward() const
	{
		return _iterable.IsForward(_pointer);
	}

	template<class T>
	bool ConstFullIterator<T>::IsBack() const
	{
		return _iterable.IsBack(_pointer);
	}

	template<class T>
	T ConstFullIterator<T>::TakeValue() const
	{
		return _iterable.TakeValue(_pointer);
	}

	template<class T>
	const T& ConstFullIterator<T>::TakeConstItem() const
	{
		return _iterable.TakeConstItem(_pointer);
	}
}