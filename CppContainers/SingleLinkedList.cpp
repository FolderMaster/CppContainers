#pragma once

#include "SingleLinkedList.h"
#include "ConstForwardIterator.h"
#include "ForwardIterator.h"

namespace Containers
{
	template<class T>
	SingleSegment<T>* SingleLinkedList<T>::GetPointerOfIndex(int index) const
	{
		SingleSegment<T>* result;
		if (index >= 0)
		{
			result = _head;
			for (int n = 0; n < index; ++n, result = result->Next)
			{

			}
		}
		else if(index == -1)
		{
			result = nullptr;
		}
		else if(index == -2)
		{
			result = _tail;
		}
		else
		{
			result = _head;
			SingleSegment<T>* additionalPointer = _head;
			for (int n = -2; n > index; --n, additionalPointer = additionalPointer->Next)
			{

			}
			if (additionalPointer != nullptr)
			{
				while (additionalPointer != _tail)
				{
					additionalPointer = additionalPointer->Next;
					result = result->Next;
				}
			}
			else
			{
				result = nullptr;
			}
		}
		return result;
	}

	template<class T>
	void SingleLinkedList<T>::CreateBySingleLinkedList(const SingleLinkedList<T>& other)
	{
		if (other._head != nullptr)
		{
			SingleSegment<T>* otherPointer = other._head;
			_head = new SingleSegment<T>(otherPointer->Item);
			SingleSegment<T>* pointer = _head;
			while (otherPointer->Next != nullptr)
			{
				otherPointer = otherPointer->Next;
				pointer->Next = new SingleSegment<T>(otherPointer->Item);
				pointer = pointer->Next;
			}
			_tail = pointer;
		}
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
	T& SingleLinkedList<T>::operator[](int index)
	{
		return TakeItem(index);
	}

	template<class T>
	SingleLinkedList<T>::SingleLinkedList() : _head(nullptr), _tail(nullptr) {}

	template<class T>
	SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T>& other)
	{
		CreateBySingleLinkedList(other);
	}

	template<class T>
	SingleLinkedList<T>::~SingleLinkedList()
	{
		Clear();
	}

	template<class T>
	SingleLinkedList<T>& SingleLinkedList<T>::operator=(const SingleLinkedList<T>& other)
	{
		if (this != &other)
		{
			Clear();
			CreateBySingleLinkedList(other);
		}
		return *this;
	}

	template<class T>
	void SingleLinkedList<T>::Add(T value, int index)
	{
		if (index == 0)
		{
			if (_head == nullptr)
			{
				_head = new SingleSegment<T>(value);
				_tail = _head;
			}
			else
			{
				_head = new SingleSegment<T>(value, _head);
			}
		}
		else
		{
			SingleSegment<T>* pointer = GetPointerOfIndex(index - 1);
			if (_tail == pointer)
			{
				if (_tail == nullptr)
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
				pointer->Next = new SingleSegment<T>(value, pointer->Next);
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
		SingleSegment<T>* deletePointer;
		if (index == 0)
		{
			deletePointer = _head;
			if (_head == _tail)
			{
				_head = _tail = nullptr;
			}
			else
			{
				_head = _head->Next;
			}
		}
		else
		{
			SingleSegment<T>* pointer = GetPointerOfIndex(index - 1);
			if (pointer == nullptr)
			{
				deletePointer = _head;
				_head = _tail = nullptr;
			}
			else
			{
				deletePointer = pointer->Next;
				if (pointer->Next == _tail)
				{
					_tail = pointer;
					pointer->Next = nullptr;
				}
				else
				{
					pointer->Next = pointer->Next->Next;
				}
			}
		}
		delete deletePointer;
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