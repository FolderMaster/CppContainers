#pragma once

#include "DynamicArray.h"

#include "ConstForwardIterator.h"
#include "ConstBackIterator.h"
#include "ForwardIterator.h"
#include "BackIterator.h"

namespace Containers
{
	template<class T>
	T* DynamicArray<T>::Resize(size_t newSize)
	{
		if (newSize > _capacity)
		{
			if (_capacity == 0)
			{
				_capacity = 1;
			}
			while (_capacity < newSize)
			{
				_capacity *= _growthFactor;
			}
			return new T[_capacity];
		}
		else if (_capacity * _growthFactor < newSize && _capacity > 0)
		{
			while (_capacity > newSize)
			{
				_capacity /= _growthFactor;
			}

			return new T[_capacity];
		}
		else
		{
			return _array;
		}
	}

	template<class T>
	void DynamicArray<T>::CreateByDynamicArray(const DynamicArray<T>& other)
	{
		_array = Resize(other._size);
		_size = other._size;
		ConstForwardIterator<T> otherBegin = other.CreateConstForwardBegin();
		ForwardIterator<T> thisBegin = CreateForwardBegin();
		while (otherBegin.IsForward())
		{
			thisBegin.TakeItem() = otherBegin.TakeValue();
			otherBegin.Forward();
			thisBegin.Forward();
		}
	}

	template<class T>
	size_t DynamicArray<T>::GetSize() const
	{
		return _size;
	}

	template<class T>
	bool DynamicArray<T>::IsEmpty() const
	{
		return _size == 0;
	}

	template<class T>
	T& DynamicArray<T>::operator[](size_t index)
	{
		return TakeItem(index);
	}

	template<class T>
	DynamicArray<T>::DynamicArray() : _capacity(0), _size(0), _array(nullptr) {}

	template<class T>
	DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
	{
		CreateByDynamicArray(other);
	}

	template<class T>
	DynamicArray<T>::~DynamicArray()
	{
		delete[] _array;
	}

	template<class T>
	DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other)
	{
		if (this != &other)
		{
			delete[] _array;
			CreateByDynamicArray(other);
		}
		return *this;
	}

	template<class T>
	void DynamicArray<T>::Add(T value, size_t index)
	{
		T* newPointer = Resize(_size + 1);

		if (newPointer != _array)
		{
			for (size_t n = 0; n < index; ++n)
			{
				newPointer[n] = _array[n];
			}
		}
		for (size_t n = _size; n > index; --n)
		{
			newPointer[n] = _array[n - 1];
		}
		newPointer[index] = value;


		if (newPointer != _array)
		{
			delete[] _array;
			_array = newPointer;
		}
		++_size;
	}

	template<class T>
	void DynamicArray<T>::AddBegin(T value)
	{
		Add(value, 0);
	}

	template<class T>
	void DynamicArray<T>::AddEnd(T value)
	{
		Add(value, GetSize());
	}

	template<class T>
	void DynamicArray<T>::Remove(size_t index)
	{
		T* newPointer = Resize(_size - 1);
		if (newPointer != _array)
		{
			for (size_t n = 0; n < index; ++n)
			{
				newPointer[n] = _array[n];
			}
		}
		for (size_t n = index + 1; n < _size; ++n)
		{
			newPointer[n - 1] = _array[n];
		}

		if (newPointer != _array)
		{
			delete[] _array;
			_array = newPointer;
		}
		--_size;
	}

	template<class T>
	void DynamicArray<T>::RemoveBegin()
	{
		Remove(0);
	}

	template<class T>
	void DynamicArray<T>::RemoveEnd()
	{
		Remove(GetSize() - 1);
	}

	template<class T>
	void DynamicArray<T>::Clear()
	{
		Resize(0);
		_size = 0;
	}

	template<class T>
	T DynamicArray<T>::TakeValue(size_t index) const
	{
		return _array[index];
	}

	template<class T>
	T DynamicArray<T>::TakeValueBegin() const
	{
		return TakeValue((size_t)0);
	}

	template<class T>
	T DynamicArray<T>::TakeValueEnd() const
	{
		return TakeValue(GetSize() - 1);
	}

	template<class T>
	T& DynamicArray<T>::TakeItem(size_t index)
	{
		return _array[index];
	}

	template<class T>
	void* DynamicArray<T>::Forward(void* pointer) const
	{
		return (T*)pointer + 1;
	}

	template<class T>
	bool DynamicArray<T>::IsForward(void* pointer) const
	{
		T* newPointer = (T*)pointer + 1;
		return _array <= newPointer && newPointer <= _array + _size;
	}

	template<class T>
	void* DynamicArray<T>::Back(void* pointer) const
	{
		return (T*)pointer - 1;
	}

	template<class T>
	bool DynamicArray<T>::IsBack(void* pointer) const
	{
		T* newPointer = (T*)pointer - 1;
		return _array <= newPointer && newPointer <= _array + _size;
	}

	template<class T>
	T DynamicArray<T>::TakeValue(void* pointer) const
	{
		return *((T*)pointer);
	}

	template<class T>
	T& DynamicArray<T>::TakeItem(void* pointer)
	{
		return *((T*)pointer);
	}

	template<class T>
	ConstForwardIterator<T> DynamicArray<T>::CreateConstForwardBegin() const
	{
		return ConstForwardIterator<T>(_array, *this);
	}

	template<class T>
	ConstForwardIterator<T> DynamicArray<T>::CreateConstForwardEnd() const
	{
		return ConstForwardIterator<T>(_array + _size, *this);
	}

	template<class T>
	ConstBackIterator<T> DynamicArray<T>::CreateConstBackBegin() const
	{
		return ConstBackIterator<T>(_array + _size - 1, *this);
	}

	template<class T>
	ConstBackIterator<T> DynamicArray<T>::CreateConstBackEnd() const
	{
		return ConstBackIterator<T>(_array - 1, *this);
	}

	template<class T>
	ForwardIterator<T> DynamicArray<T>::CreateForwardBegin()
	{
		return ForwardIterator<T>(_array, *this);
	}

	template<class T>
	ForwardIterator<T> DynamicArray<T>::CreateForwardEnd()
	{
		return ForwardIterator<T>(_array + _size, *this);
	}

	template<class T>
	BackIterator<T> DynamicArray<T>::CreateBackBegin()
	{
		return BackIterator<T>(_array + _size - 1, *this);
	}

	template<class T>
	BackIterator<T> DynamicArray<T>::CreateBackEnd()
	{
		return BackIterator<T>(_array - 1, *this);
	}
}