#pragma once

#include "DoubleLinkedList.h"

#include "ConstForwardIterator.h"
#include "ConstBackIterator.h"
#include "ForwardIterator.h"
#include "BackIterator.h"

namespace Containers
{
	template<class T>
	DoubleSegment<T>* DoubleLinkedList<T>::GetPointerOfIndex(int index) const
	{
		DoubleSegment<T>* result;
		if (index >= 0)
		{
			result = _head;
			for (int n = 0; n < index; ++n, result = result->Next)
			{

			}
		}
		else if (index == -1)
		{
			result = nullptr;
		}
		else
		{
			result = _tail;
			for (int n = -2; n > index; --n, result = result->Back)
			{

			}
		}
		return result;
	}

	template<class T>
	void DoubleLinkedList<T>::CreateByDoubleLinkedList(const DoubleLinkedList<T>& other)
	{
		if (other._head != nullptr)
		{
			DoubleSegment<T>* otherPointer = other._head;
			_head = new DoubleSegment<T>(otherPointer->Item);
			DoubleSegment<T>* pointer = _head;
			while (otherPointer->Next != nullptr)
			{
				otherPointer = otherPointer->Next;
				pointer->Next = new DoubleSegment<T>(pointer, otherPointer->Item);
				pointer->Next->Back = pointer;
				pointer = pointer->Next;
			}
			_tail = pointer;
		}
	}

	template<class T>
	size_t DoubleLinkedList<T>::GetSize() const
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
	bool DoubleLinkedList<T>::IsEmpty() const
	{
		return _head == nullptr;
	}

	template<class T>
	T& DoubleLinkedList<T>::operator[](int index)
	{
		return TakeItem(index);
	}

	template<class T>
	DoubleLinkedList<T>::DoubleLinkedList() : _head(nullptr), _tail(nullptr) {}

	template<class T>
	DoubleLinkedList<T>::~DoubleLinkedList()
	{
		Clear();
	}

	template<class T>
	DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T>& other)
	{
		CreateByDoubleLinkedList(other);
	}

	template<class T>
	DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList<T>& other)
	{
		if (this != &other)
		{
			Clear();
			CreateByDoubleLinkedList(other);
		}
		return *this;
	}

	template<class T>
	void DoubleLinkedList<T>::Add(T value, int index)
	{
		DoubleSegment<T>* pointer = GetPointerOfIndex(index);
		if (pointer == nullptr)
		{
			if (_head == nullptr)
			{
				_head = new DoubleSegment<T>(value);
				_tail = _head;
			}
			else
			{
				_tail->Next = new DoubleSegment<T>(value, _tail);
				_tail = _tail->Next;
			}
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
	void DoubleLinkedList<T>::AddBegin(T value)
	{
		Add(value, 0);
	}

	template<class T>
	void DoubleLinkedList<T>::AddEnd(T value)
	{
		Add(value, -1);
	}

	template<class T>
	void DoubleLinkedList<T>::Remove(int index)
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
	void DoubleLinkedList<T>::RemoveBegin()
	{
		Remove(0);
	}

	template<class T>
	void DoubleLinkedList<T>::RemoveEnd()
	{
		Remove(-2);
	}

	template<class T>
	void DoubleLinkedList<T>::Clear()
	{
		if (_head != nullptr)
		{
			DoubleSegment<T>* pointer = _head;
			while (pointer->Next != nullptr)
			{
				pointer = pointer->Next;
				delete pointer->Back;
			}
			delete pointer;
			_head = nullptr;
			_tail = nullptr;
		}
	}

	template<class T>
	T DoubleLinkedList<T>::TakeValue(int index) const
	{
		return GetPointerOfIndex(index)->Item;
	}

	template<class T>
	T DoubleLinkedList<T>::TakeValueBegin() const
	{
		return TakeValue(0);
	}

	template<class T>
	T DoubleLinkedList<T>::TakeValueEnd() const
	{
		return TakeValue(-2);
	}

	template<class T>
	T& DoubleLinkedList<T>::TakeItem(int index)
	{
		return GetPointerOfIndex(index)->Item;
	}

	template<class T>
	void* DoubleLinkedList<T>::Forward(void* pointer) const
	{
		return ((DoubleSegment<T>*)pointer)->Next;
	}

	template<class T>
	bool DoubleLinkedList<T>::IsForward(void* pointer) const
	{
		return ((DoubleSegment<T>*)pointer) != nullptr;
	}

	template<class T>
	void* DoubleLinkedList<T>::Back(void* pointer) const
	{
		return ((DoubleSegment<T>*)pointer)->Back;
	}

	template<class T>
	bool DoubleLinkedList<T>::IsBack(void* pointer) const
	{
		return ((DoubleSegment<T>*)pointer) != nullptr;
	}

	template<class T>
	T DoubleLinkedList<T>::TakeValue(void* pointer) const
	{
		return ((DoubleSegment<T>*)pointer)->Item;
	}

	template<class T>
	T& DoubleLinkedList<T>::TakeItem(void* pointer)
	{
		return ((DoubleSegment<T>*)pointer)->Item;
	}

	template<class T>
	ConstForwardIterator<T> DoubleLinkedList<T>::CreateConstForwardBegin() const
	{
		return ConstForwardIterator<T>(_head, *this);
	}

	template<class T>
	ConstForwardIterator<T> DoubleLinkedList<T>::CreateConstForwardEnd() const
	{
		return ConstForwardIterator<T>(nullptr, *this);
	}

	template<class T>
	ConstBackIterator<T> DoubleLinkedList<T>::CreateConstBackBegin() const
	{
		return ConstBackIterator<T>(_tail, *this);
	}

	template<class T>
	ConstBackIterator<T> DoubleLinkedList<T>::CreateConstBackEnd() const
	{
		return ConstBackIterator<T>(nullptr, *this);
	}

	template<class T>
	ForwardIterator<T> DoubleLinkedList<T>::CreateForwardBegin()
	{
		return ForwardIterator<T>(_head, *this);
	}

	template<class T>
	ForwardIterator<T> DoubleLinkedList<T>::CreateForwardEnd()
	{
		return ForwardIterator<T>(nullptr, *this);
	}

	template<class T>
	BackIterator<T> DoubleLinkedList<T>::CreateBackBegin()
	{
		return BackIterator<T>(_tail, *this);
	}

	template<class T>
	BackIterator<T> DoubleLinkedList<T>::CreateBackEnd()
	{
		return BackIterator<T>(nullptr, *this);
	}
}