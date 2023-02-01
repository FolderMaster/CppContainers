#pragma once

#include "DoubleLinkedList.h"
#include "ConstForwardIterator.cpp"
#include "ConstBackIterator.cpp"

namespace Containers
{
	template<class T>
	DoubleSegment<T>* DoubleLinkedList<T>::GetPointerOfIndex(int index)
	{
		DoubleSegment<T>* result;
		if (index >= 0)
		{
			result = _head;
			for (int n = 0; n < index; ++n, result = result->Next)
			{

			}
		}
		else
		{
			result = _tail;
			for (int n = -1; n > index; --n, result = result->Back)
			{

			}
		}
		return result;
	}

	template<class T>
	size_t DoubleLinkedList<T>::GetSize()
	{
		int size = 0;
		for (DoubleSegment<T>* pointer = _head;
			pointer != nullptr;
			pointer = pointer->Next)
		{
			++size;
		}
		return size;
	}

	template<class T>
	T& DoubleLinkedList<T>::operator[](size_t index)
	{
		return TakeItem(index);
	}

	template<class T>
	DoubleLinkedList<T>::DoubleLinkedList()
	{
	}

	template<class T>
	DoubleLinkedList<T>::~DoubleLinkedList()
	{
	}

	template<class T>
	void DoubleLinkedList<T>::Add(T value, size_t index)
	{
		DoubleSegment<T>* pointer = GetPointerOfIndex(index);
		if (pointer == nullptr)
		{
			_head = new DoubleSegment<T>(value);
			_tail = _head;
		}
		else
		{
			pointer->Back = new DoubleSegment<T>(value, pointer->Back, pointer);
			if (_head == pointer)
			{
				_head = pointer->Back;
			}
			else
			{
				pointer->Back->Back->Next = pointer->Back;
			}
		}
	}

	template<class T>
	void DoubleLinkedList<T>::Remove(size_t index)
	{
		DoubleSegment<T>* pointer = GetPointerOfIndex(index);
		if (pointer == _head)
		{
			_head = pointer->Next;
		}
		if (pointer == _tail)
		{
			_tail = pointer->Back;
		}
		if (pointer->Back != nullptr)
		{
			pointer->Back->Next = pointer->Next;
		}
		if (pointer->Next != nullptr)
		{
			pointer->Next->Back = pointer->Back;
		}
		delete pointer;
	}

	template<class T>
	T DoubleLinkedList<T>::TakeValue(size_t index)
	{
		return GetPointerOfIndex(index)->Item;
	}

	template<class T>
	T& DoubleLinkedList<T>::TakeItem(size_t index)
	{
		return GetPointerOfIndex(index)->Item;
	}

	template<class T>
	void* DoubleLinkedList<T>::Forward(void* pointer)
	{
		return ((DoubleSegment<T>*)pointer)->Next;
	}

	template<class T>
	bool DoubleLinkedList<T>::IsForward(void* pointer)
	{
		return ((DoubleSegment<T>*)pointer)->Next != nullptr;
	}

	template<class T>
	void* DoubleLinkedList<T>::Back(void* pointer)
	{
		return ((DoubleSegment<T>*)pointer)->Back;
	}

	template<class T>
	bool DoubleLinkedList<T>::IsBack(void* pointer)
	{
		return ((DoubleSegment<T>*)pointer)->Back != nullptr;
	}

	template<class T>
	T DoubleLinkedList<T>::TakeValue(void* pointer)
	{
		return ((DoubleSegment<T>*)pointer)->Item;
	}

	template<class T>
	ConstForwardIterator<T> DoubleLinkedList<T>::CreateConstForwardBegin()
	{
		return ConstForwardIterator<T>(_head, *this);
	}

	template<class T>
	ConstForwardIterator<T> DoubleLinkedList<T>::CreateConstForwardEnd()
	{
		return ConstForwardIterator<T>(nullptr, *this);
	}
	template<class T>
	ConstBackIterator<T> DoubleLinkedList<T>::CreateConstBackBegin()
	{
		return ConstBackIterator<T>(_tail, *this);
	}
	template<class T>
	ConstBackIterator<T> DoubleLinkedList<T>::CreateConstBackEnd()
	{
		return ConstBackIterator<T>(nullptr, *this);
	}
}