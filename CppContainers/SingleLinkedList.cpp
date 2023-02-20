#pragma once

#include "SingleLinkedList.h"
#include "ConstForwardIterator.cpp"
#include "ForwardIterator.cpp"

namespace Containers
{
	template<class T>
	SingleSegment<T>* SingleLinkedList<T>::GetPointerOfIndex(int index) const
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
	size_t SingleLinkedList<T>::GetSize() const
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
	bool SingleLinkedList<T>::IsEmpty() const
	{
		return _head == nullptr;
	}

	template<class T>
	SingleLinkedList<T>::SingleLinkedList() : _head(nullptr), _tail(nullptr) {}

	template<class T>
	SingleLinkedList<T>::~SingleLinkedList()
	{
		Clear();
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
	void SingleLinkedList<T>::Clear()
	{
		if (_head != nullptr)
		{
			SingleSegment<T>* pointer = _head;
			SingleSegment<T>* deletePointer;
			while (pointer->Next != nullptr)
			{
				deletePointer = pointer;
				pointer = pointer->Next;
				delete deletePointer;
			}
			delete pointer;
			_head = nullptr;
			_tail = nullptr;
		}
	}

	template<class T>
	T SingleLinkedList<T>::TakeValue(int index) const
	{
		return GetPointerOfIndex(index)->Item;
	}

	template<class T>
	T SingleLinkedList<T>::TakeValueBegin() const
	{
		return TakeValue(0);
	}

	template<class T>
	T SingleLinkedList<T>::TakeValueEnd() const
	{
		return TakeValue(-2);
	}

	template<class T>
	T& SingleLinkedList<T>::TakeItem(int index)
	{
		return GetPointerOfIndex(index)->Item;
	}

	template<class T>
	void* SingleLinkedList<T>::Forward(void* pointer) const
	{
		return ((SingleSegment<T>*)pointer)->Next;
	}

	template<class T>
	bool SingleLinkedList<T>::IsForward(void* pointer) const
	{
		return ((SingleSegment<T>*)pointer) != nullptr;
	}

	template<class T>
	T SingleLinkedList<T>::TakeValue(void* pointer) const
	{
		return ((SingleSegment<T>*)pointer)->Item;
	}

	template<class T>
	T& SingleLinkedList<T>::TakeItem(void* pointer)
	{
		return ((SingleSegment<T>*)pointer)->Item;
	}

	template<class T>
	ConstForwardIterator<T> SingleLinkedList<T>::CreateConstForwardBegin() const
	{
		return ConstForwardIterator<T>(_head, *this);
	}

	template<class T>
	ConstForwardIterator<T> SingleLinkedList<T>::CreateConstForwardEnd() const
	{
		return ConstForwardIterator<T>(nullptr, *this);
	}

	template<class T>
	ForwardIterator<T> SingleLinkedList<T>::CreateForwardBegin()
	{
		return ForwardIterator<T>(_head, *this);
	}

	template<class T>
	ForwardIterator<T> SingleLinkedList<T>::CreateForwardEnd()
	{
		return ForwardIterator<T>(nullptr, *this);
	}
}