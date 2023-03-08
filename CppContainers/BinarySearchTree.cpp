#pragma once

#include "BinarySearchTree.h"

#include "Exceptions.h"

namespace Containers
{
	template<class T>
	void BinarySearchTree<T>::RemoveSegment(TreeSegment<T>* current, TreeSegment<T>* change)
	{
		ReplaceSegment(current, change);
		delete current;
	}

	template<class T>
	void BinarySearchTree<T>::ReplaceSegment(TreeSegment<T>* current, TreeSegment<T>* change)
	{
		TreeSegment<T>* parent = current->Parent;
		if (parent != nullptr)
		{
			if (parent->Right == current)
			{
				parent->Right = change;
			}
			else
			{
				parent->Left = change;
			}
		}
		else
		{
			if (change != nullptr)
			{
				change->Parent = nullptr;
			}
			_root = change;
		}
	}

	template<class T>
	TreeSegment<T>* BinarySearchTree<T>::FindMinSegment(TreeSegment<T>* pointer)
	{
		if (pointer == nullptr)
		{
			throw KeyNotFoundException;
		}
		else
		{
			TreeSegment<T>* findPointer = pointer;
			while (findPointer->Left != nullptr)
			{
				findPointer = findPointer->Left;
			}
			return findPointer;
		}
	}

	template<class T>
	TreeSegment<T>* BinarySearchTree<T>::FindSegment(const T& value) const
	{
		TreeSegment<T>* pointer = _root;
		while (pointer != nullptr)
		{
			if (pointer->Item == value)
			{
				return pointer;
			}
			else
			{
				if (pointer->Item < value)
				{
					pointer = pointer->Right;
				}
				else
				{
					pointer = pointer->Left;
				}
			}
		}
		throw KeyNotFoundException;
	}

	template<class T>
	void BinarySearchTree<T>::CreateByBinarySearchTree(const BinarySearchTree<T>& other)
	{
	}

	template<class T>
	size_t BinarySearchTree<T>::GetSize() const
	{
		return size_t();
	}

	template<class T>
	bool BinarySearchTree<T>::IsEmpty() const
	{
		return _root == nullptr;
	}

	template<class T>
	BinarySearchTree<T>::BinarySearchTree() : _root(nullptr) {}

	template<class T>
	BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)
	{
		CreateByBinarySearchTree(other);
	}

	template<class T>
	BinarySearchTree<T>::~BinarySearchTree()
	{
		Clear();
	}

	template<class T>
	BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T>& other)
	{
		if (this != &other)
		{
			Clear();
			CreateByBinarySearchTree(other);
		}
		return *this;
	}

	template<class T>
	void BinarySearchTree<T>::AddValue(T value)
	{
		if (IsEmpty())
		{
			_root = new TreeSegment<T>(value);
		}
		else
		{
			TreeSegment<T>* pointer = _root;
			while (true)
			{
				if (pointer->Item < value)
				{
					if (pointer->Right == nullptr)
					{
						pointer->Right = new TreeSegment<T>(value, pointer);
						break;
					}
					else
					{
						pointer = pointer->Right;
					}
				}
				else
				{
					if (pointer->Left == nullptr)
					{
						pointer->Left = new TreeSegment<T>(value, pointer);
						break;
					}
					else
					{
						pointer = pointer->Left;
					}
				}
			}
		}
	}

	template<class T>
	void BinarySearchTree<T>::Remove(T value)
	{
		TreeSegment<T>* pointer = FindSegment(value);
		if (pointer->Right == nullptr && pointer->Left == nullptr)
		{
			RemoveSegment(pointer, nullptr);
		}
		else if (pointer->Right != nullptr && pointer->Left == nullptr)
		{
			pointer->Right->Parent = pointer->Parent;
			RemoveSegment(pointer, pointer->Right);
		}
		else if (pointer->Left != nullptr && pointer->Right == nullptr)
		{
			pointer->Left->Parent = pointer->Parent;
			RemoveSegment(pointer, pointer->Left);
		}
		else
		{
			TreeSegment<T>* minPointer = FindMinSegment(pointer->Right);
			T item = minPointer->Item;
			if (minPointer->Right != nullptr)
			{
				minPointer->Right->Parent = minPointer->Parent;
			}
			RemoveSegment(minPointer, minPointer->Right);
			pointer->Item = item;
		}
	}

	template<class T>
	void BinarySearchTree<T>::Clear()
	{
	}

	template<class T>
	T BinarySearchTree<T>::TakeValue(T value) const
	{
		return FindSegment(value)->Item;
	}

	template<class T>
	const T& BinarySearchTree<T>::TakeConstItem(T value) const
	{
		return FindSegment(value)->Item;
	}
}