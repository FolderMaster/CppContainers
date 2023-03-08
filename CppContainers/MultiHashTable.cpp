#pragma once

#include "MultiHashTable.h"

#include "SearchFunctions.h"
#include "Exceptions.h"

namespace Containers
{
	template<class TKey, class TValue>
	void MultiHashTable<TKey, TValue>::Rehash()
	{
		int size = _hashTable.GetSize();
		SingleList<KeyValuePair<TKey, SingleList<TValue>>> pairList =
			SingleList<KeyValuePair<TKey, SingleList<TValue>>>();
		for (int n = 0; n < size; ++n)
		{
			for (int h = 0; h < _hashTable[n].GetSize(); ++h)
			{
				pairList.AddItemEnd(_hashTable[n][h]);
			}
			_hashTable[n].Clear();
		}

		int newSize = round(size * _growFactor);
		for (int n = size; n < newSize; ++n)
		{
			_hashTable.AddValueEnd(SingleList<KeyValuePair<TKey, SingleList<TValue>>>());
		}

		for (int n = 0; n < pairList.GetSize(); ++n)
		{
			int arrayIndex = _hashFunction(pairList[n].Key, newSize);
			_hashTable[arrayIndex].AddItemEnd(pairList[n]);
		}
	}

	template<class TKey, class TValue>
	bool MultiHashTable<TKey, TValue>::IsNeedRehash()
	{
		int arraySize = _hashTable.GetSize();
		int listSize = 0;
		for (int n = 0; n < arraySize; ++n)
		{
			listSize += _hashTable[n].GetSize();
		}
		return listSize / (double)arraySize >= _resizeCoefficient;
	}

	template<class TKey, class TValue>
	size_t MultiHashTable<TKey, TValue>::GetSize() const
	{
		size_t size = 0;
		for (size_t n = 0; n < _hashTable.GetSize(); ++n)
		{
			size += _hashTable.TakeConstItem(n).GetSize();
		}
		return size;
	}

	template<class TKey, class TValue>
	bool MultiHashTable<TKey, TValue>::IsEmpty() const
	{
		for (size_t n = 0; n < _hashTable.GetSize(); ++n)
		{
			if (!_hashTable.TakeConstItem(n).IsEmpty())
			{
				return false;
			}
		}
		return true;
	}

	template<class TKey, class TValue>
	MultiHashTable<TKey, TValue>::MultiHashTable(int(*hashFucntion)(TKey, size_t)) :
		_hashFunction(hashFucntion),
		_hashTable(Array<SingleList<KeyValuePair<TKey, SingleList<TValue>>>>()) {}

	template<class TKey, class TValue>
	MultiHashTable<TKey, TValue>::MultiHashTable(const MultiHashTable<TKey, TValue>& other)
	{
		_hashFunction = other._hashFunction;
		_hashTable = other._hashTable;
	}

	template<class TKey, class TValue>
	MultiHashTable<TKey, TValue>::~MultiHashTable()
	{
		Clear();
	}

	template<class TKey, class TValue>
	MultiHashTable<TKey, TValue>& MultiHashTable<TKey, TValue>::operator=(const
		MultiHashTable<TKey, TValue>& other)
	{
		if (this != &other)
		{
			_hashFunction = other._hashFunction;
			_hashTable = other._hashTable;
		}
		return *this;
	}

	template<class TKey, class TValue>
	void MultiHashTable<TKey, TValue>::AddValue(TValue value, TKey key)
	{
		AddItem(value, key);
	}

	template<class TKey, class TValue>
	void MultiHashTable<TKey, TValue>::AddItem(TValue& item, TKey key)
	{
		if (_hashTable.GetSize() == 0)
		{
			SingleList<KeyValuePair<TKey, SingleList<TValue>>> list =
				SingleList<KeyValuePair<TKey, SingleList<TValue>>>();
			KeyValuePair<TKey, SingleList<TValue>> listItem = KeyValuePair<TKey,
				SingleList<TValue>>(key, SingleList<TValue>());
			listItem.Value.AddItemBegin(item);
			list.AddItemBegin(listItem);
			_hashTable.AddItemBegin(list);
			Rehash();
		}
		else
		{
			int arrayIndex = _hashFunction(key, _hashTable.GetSize());
			KeyValuePair<TKey, SingleList<TValue>> pair =
				KeyValuePair<TKey, SingleList<TValue>>(key);
			SingleList<KeyValuePair<TKey, SingleList<TValue>>>& list = _hashTable[arrayIndex];
			int listIndex = LinearFindIndex(list, pair);
			if (listIndex != -1)
			{
				list[listIndex].Value.AddItemEnd(item);
			}
			else
			{
				KeyValuePair<TKey, SingleList<TValue>> itemList = KeyValuePair<TKey,
					SingleList<TValue>>(key, SingleList<TValue>());
				itemList.Value.AddItemBegin(item);
				list.AddItemEnd(itemList);
				if (IsNeedRehash())
				{
					Rehash();
				}
			}
		}
	}

	template<class TKey, class TValue>
	void MultiHashTable<TKey, TValue>::Remove(TKey key)
	{
		if (_hashTable.GetSize() == 0)
		{
			throw KeyNotFoundException;
		}
		else
		{
			int arrayIndex = _hashFunction(key, _hashTable.GetSize());
			KeyValuePair<TKey, SingleList<TValue>> pair =
				KeyValuePair<TKey, SingleList<TValue>>(key);
			SingleList<KeyValuePair<TKey, SingleList<TValue>>>& list = _hashTable[arrayIndex];
			int listIndex = LinearFindIndex(list, pair);
			if (listIndex == -1)
			{
				throw KeyNotFoundException;
			}
			else
			{
				list.Remove(listIndex);
				if (IsNeedRehash())
				{
					Rehash();
				}
			}
		}
	}

	template<class TKey, class TValue>
	void MultiHashTable<TKey, TValue>::Clear()
	{
		_hashTable.Clear();
	}

	template<class TKey, class TValue>
	SingleList<TValue> MultiHashTable<TKey, TValue>::TakeValue(TKey key) const
	{
		if (_hashTable.GetSize() == 0)
		{
			throw ValueNotFoundException;
		}
		else
		{
			int arrayIndex = _hashFunction(key, _hashTable.GetSize());
			KeyValuePair<TKey, SingleList<TValue>> pair =
				KeyValuePair<TKey, SingleList<TValue>>(key);
			const SingleList<KeyValuePair<TKey, SingleList<TValue>>>& list =
				_hashTable.TakeConstItem(arrayIndex);
			int listIndex = LinearFindIndex(list, pair);
			if (listIndex == -1)
			{
				throw ValueNotFoundException;
			}
			else
			{
				return list.TakeValue(listIndex).Value;
			}
		}
	}

	template<class TKey, class TValue>
	SingleList<TValue>& MultiHashTable<TKey, TValue>::TakeItem(TKey key)
	{
		if (_hashTable.GetSize() == 0)
		{
			throw ItemNotFoundException;
		}
		else
		{
			int arrayIndex = _hashFunction(key, _hashTable.GetSize());
			KeyValuePair<TKey, SingleList<TValue>> pair =
				KeyValuePair<TKey, SingleList<TValue>>(key);
			SingleList<KeyValuePair<TKey, SingleList<TValue>>>& list = _hashTable[arrayIndex];
			int listIndex = LinearFindIndex(list, pair);
			if (listIndex == -1)
			{
				throw ItemNotFoundException;
			}
			else
			{
				return list[listIndex].Value;
			}
		}
	}

	template<class TKey, class TValue>
	const SingleList<TValue>& MultiHashTable<TKey, TValue>::TakeConstItem(TKey key) const
	{
		if (_hashTable.GetSize() == 0)
		{
			throw ConstItemNotFoundException;
		}
		else
		{
			int arrayIndex = _hashFunction(key, _hashTable.GetSize());
			KeyValuePair<TKey, SingleList<TValue>> pair =
				KeyValuePair<TKey, SingleList<TValue>>(key);
			const SingleList<KeyValuePair<TKey, SingleList<TValue>>>& list =
				_hashTable.TakeConstItem(arrayIndex);
			int listIndex = LinearFindIndex(list, pair);
			if (listIndex == -1)
			{
				throw ConstItemNotFoundException;
			}
			else
			{
				return list.TakeConstItem(listIndex).Value;
			}
		}
	}
}