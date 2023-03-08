#pragma once

#include "ConstForwardIterator.h"

#include "IConstForwardIterable.h"

namespace Containers
{
	template<class T>
	ConstForwardIterator<T>::ConstForwardIterator(void* pointer, const IConstForwardIterable<T>*
		iterable) : _pointer(pointer), _iterable(iterable) {}

	template<class T>
	ConstForwardIterator<T>::ConstForwardIterator(const ConstForwardIterator<T>& other) :
		_pointer(other._pointer), _iterable(other._iterable) {}

	template<class T>
	ConstForwardIterator<T>& ConstForwardIterator<T>::operator=(const ConstForwardIterator<T>&
		other)
	{
		if (this != &other)
		{
			_pointer = other._pointer;
			_iterable = other._iterable;
		}
		return *this;
	}

	template<class T>
	bool ConstForwardIterator<T>::operator!=(ConstForwardIterator<T> it)
	{
		return _pointer != it._pointer;
	}

	template<class T>
	void ConstForwardIterator<T>::Forward()
	{
		_pointer = _iterable->Forward(_pointer);
	}

	template<class T>
	bool ConstForwardIterator<T>::IsForward() const
	{
		return _iterable->IsForward(_pointer);
	}

	template<class T>
	T ConstForwardIterator<T>::TakeValue() const
	{
		return _iterable->TakeValue(_pointer);
	}

	template<class T>
	const T& ConstForwardIterator<T>::TakeConstItem() const
	{
		return _iterable->TakeConstItem(_pointer);
	}
}