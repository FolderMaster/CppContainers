#pragma once

#include "SingleLinkedList.h"
#include "ConstForwardIterator.cpp"

namespace Containers
{
	template<class T>
	SingleSegment<T>* SingleLinkedList<T>::GetPointerOfIndex(int index)
	{
		SingleSegment<T>* result;
		if (index >= 0)
		{
			result = _head;
			for (size_t n = 0; n < index; ++n, result = result->Next)
			{

			}
		}
		else if(index == -1)
		{
			result = nullptr;
		}
		else
		{
			result = _tail;
		}
		return result;
	}

	template<class T>
	size_t SingleLinkedList<T>::GetSize()
	{
		int size = 0;
		for (SingleSegment<T>* pointer = _head;
			pointer != nullptr;
			pointer = pointer->Next)
		{
			++size;
		}
		return size;
	}

	template<class T>
	SingleLinkedList<T>::SingleLinkedList()
	{
	}

	template<class T>
	SingleLinkedList<T>::~SingleLinkedList()
	{
	}

	template<class T>
	T& SingleLinkedList<T>::operator[](int index)
	{
		return TakeValue(index);
	}

	template<class T>
	void SingleLinkedList<T>::Add(T value, int index)
	{
		SingleSegment<T>* pointer = GetPointerOfIndex(index);
		if (pointer == nullptr)
		{
			if (_head == nullptr)
			{
				_head = new SingleSegment<T>(value);
				_tail = _head;
			}
			else
			{
				_tail->Next = new SingleSegment<T>(value);
				_tail = _tail->Next;
			}
		}
		else
		{
			SingleSegment<T>* connectingPointer = GetPointerOfIndex(index - 1);
			if (connectingPointer == nullptr)
			{
				_head = new SingleSegment<T>(value, _head);
			}
			else
			{
				connectingPointer->Next = new SingleSegment<T>(value, pointer);
			}
		}
	}

	template<class T>
	void SingleLinkedList<T>::AddBegin(T value)
	{
		Add(value, 0);
	}

	template<class T>
	void SingleLinkedList<T>::AddEnd(T value)
	{
		Add(value, -1);
	}

	template<class T>
	void SingleLinkedList<T>::Remove(int index)
	{
		SingleSegment<T>* pointer = GetPointerOfIndex(index);
		if (pointer == _head)
		{
			_head = pointer->Next;
		}
		delete pointer;
	}

	template<class T>
	void SingleLinkedList<T>::RemoveBegin()
	{
		Remove(0);
	}

	template<class T>
	void SingleLinkedList<T>::RemoveEnd()
	{
		Remove(-2);
	}

	template<class T>
	T SingleLinkedList<T>::TakeValue(int index)
	{
		return GetPointerOfIndex(index)->Item;
	}

	template<class T>
	T SingleLinkedList<T>::TakeValueBegin()
	{
		return TakeValue(0);
	}

	template<class T>
	T SingleLinkedList<T>::TakeValueEnd()
	{
		return TakeValue(-2);
	}

	template<class T>
	T& SingleLinkedList<T>::TakeItem(int index)
	{
		return GetPointerOfIndex(index)->Item;
	}

	template<class T>
	void* SingleLinkedList<T>::Forward(void* pointer)
	{
		return ((SingleSegment<T>*)pointer)->Next;
	}

	template<class T>
	bool SingleLinkedList<T>::IsForward(void* pointer)
	{
		return ((SingleSegment<T>*)pointer) != nullptr;
	}

	template<class T>
	T SingleLinkedList<T>::TakeValue(void* pointer)
	{
		return ((SingleSegment<T>*)pointer)->Item;
	}

	template<class T>
	ConstForwardIterator<T> SingleLinkedList<T>::CreateConstForwardBegin()
	{
		return ConstForwardIterator<T>(_head, *this);
	}

	template<class T>
	ConstForwardIterator<T> SingleLinkedList<T>::CreateConstForwardEnd()
	{
		return ConstForwardIterator<T>(nullptr, *this);
	}
}