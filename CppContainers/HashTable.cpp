#pragma once

#include "HashTable.h"

#include "SearchFunctions.h"
#include "Exceptions.h"

namespace Containers
{
	template<class TKey, class TValue>
	void HashTable<TKey, TValue>::Rehash()
	{
		int size = _hashTable.GetSize();
		SingleList<KeyValuePair<TKey, TValue>> pairList = SingleList<KeyValuePair<TKey, TValue>>();
		for (int n = 0; n < size; ++n)
		{
			for (int h = 0; h < _hashTable[n].GetSize(); ++h)
			{
				pairList.AddEnd(_hashTable[n][h]);
			}
			_hashTable[n].Clear();
		}

		int newSize = round(size * _growFactor);
		for (int n = size; n < newSize; ++n)
		{
			_hashTable.AddEnd(SingleList<KeyValuePair<TKey, TValue>>());
		}

		for (int n = 0; n < pairList.GetSize(); ++n)
		{
			int arrayIndex = _hashFunction(pairList[n].Key, newSize);
			_hashTable[arrayIndex].AddEnd(pairList[n]);
		}
	}

	template<class TKey, class TValue>
	bool HashTable<TKey, TValue>::IsNeedRehash()
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
	size_t HashTable<TKey, TValue>::GetSize() const
	{
		size_t size = 0;
		for (size_t n = 0; n < _hashTable.GetSize(); ++n)
		{
			size += _hashTable.TakeValue(n).GetSize();
		}
		return size;
	}

	template<class TKey, class TValue>
	bool HashTable<TKey, TValue>::IsEmpty() const
	{
		for (size_t n = 0; n < _hashTable.GetSize(); ++n)
		{
			if (!_hashTable.TakeValue(n).IsEmpty())
			{
				return false;
			}
		}
		return true;
	}

	template<class TKey, class TValue>
	HashTable<TKey, TValue>::HashTable(int (*hashFucntion)(TKey, size_t)) :
		_hashFunction(hashFucntion), _hashTable(Array<SingleList<KeyValuePair<TKey, TValue>>>()) {}

	template<class TKey, class TValue>
	HashTable<TKey, TValue>::HashTable(const HashTable<TKey, TValue>& other)
	{
		_hashFunction = other._hashFunction;
		_hashTable = other._hashTable;
	}

	template<class TKey, class TValue>
	HashTable<TKey, TValue>::~HashTable() {}

	template<class TKey, class TValue>
	HashTable<TKey, TValue>& HashTable<TKey, TValue>::operator=(const HashTable<TKey, TValue>&
		other)
	{
		if (this != &other)
		{
			_hashFunction = other._hashFunction;
			_hashTable = other._hashTable;
		}
		return *this;
	}

	template<class TKey, class TValue>
	void HashTable<TKey, TValue>::Add(TValue value, TKey key)
	{
		if (_hashTable.GetSize() == 0)
		{
			SingleList<KeyValuePair<TKey, TValue>> list = SingleList<KeyValuePair<TKey, TValue>>();
			list.AddBegin(KeyValuePair<TKey, TValue>(key, value));
			_hashTable.AddBegin(list);
			Rehash();
		}
		else
		{
			int arrayIndex = _hashFunction(key, _hashTable.GetSize());
			KeyValuePair<TKey, TValue> pair = KeyValuePair<TKey, TValue>(key);
			SingleList<KeyValuePair<TKey, TValue>>& list = _hashTable[arrayIndex];
			int listIndex = LinearFindIndex(list, pair);
			if (listIndex != -1)
			{
				throw OccupiedKeyException;
			}
			else
			{
				list.AddEnd(KeyValuePair<TKey, TValue>(key, value));
				if (IsNeedRehash())
				{
					Rehash();
				}
			}
		}
	}

	template<class TKey, class TValue>
	void HashTable<TKey, TValue>::Remove(TKey key)
	{
		if (_hashTable.GetSize() == 0)
		{
			throw KeyNotFoundException;
		}
		else
		{
			int arrayIndex = _hashFunction(key, _hashTable.GetSize());
			KeyValuePair<TKey, TValue> pair = KeyValuePair<TKey, TValue>(key);
			SingleList<KeyValuePair<TKey, TValue>>& list = _hashTable[arrayIndex];
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
	TValue HashTable<TKey, TValue>::TakeValue(TKey key) const
	{
		if (_hashTable.GetSize() == 0)
		{
			throw KeyNotFoundException;
		}
		else
		{
			KeyValuePair<TKey, TValue> pair = KeyValuePair<TKey, TValue>(key);
			int arrayIndex = _hashFunction(key, _hashTable.GetSize());
			SingleList<KeyValuePair<TKey, TValue>> list = _hashTable.TakeValue(arrayIndex);
			int listIndex = LinearFindIndex(list, pair);
			if (listIndex == -1)
			{
				throw KeyNotFoundException;
			}
			else
			{
				return list[listIndex].Value;
			}
		}
	}

	template<class TKey, class TValue>
	TValue& HashTable<TKey, TValue>::TakeItem(TKey key)
	{
		if (_hashTable.GetSize() == 0)
		{
			throw KeyNotFoundException;
		}
		else
		{
			KeyValuePair<TKey, TValue> pair = KeyValuePair<TKey, TValue>(key);
			int arrayIndex = _hashFunction(key, _hashTable.GetSize());
			SingleList<KeyValuePair<TKey, TValue>>& list = _hashTable[arrayIndex];
			int listIndex = LinearFindIndex(list, pair);
			if (listIndex == -1)
			{
				throw KeyNotFoundException;
			}
			else
			{
				return list[listIndex].Value;
			}
		}
	}
}