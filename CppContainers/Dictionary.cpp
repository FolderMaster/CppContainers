#pragma once

#include "Dictionary.h"
#include "SearchFunctions.cpp"
#include "SortFunctions.cpp"

namespace Containers
{
	template<class TKey, class TValue>
	Dictionary<TKey, TValue>::Dictionary() : _dictionary(Array<KeyValuePair<TKey, TValue>>()) {}

	template<class TKey, class TValue>
	Dictionary<TKey, TValue>::~Dictionary() {}

	template<class TKey, class TValue>
	void Dictionary<TKey, TValue>::Add(TValue value, TKey key)
	{
		KeyValuePair<TKey, TValue> pair = KeyValuePair<TKey, TValue>(key, value);
		int index = BinaryFindIndex(_dictionary, pair, _sortFunction);
		if (index == -1)
		{
			_dictionary.AddEnd(pair);
			BubbleSort(_dictionary, _sortFunction);
		}
		else
		{
			throw OccupiedKeyException;
		}
	}

	template<class TKey, class TValue>
	void Dictionary<TKey, TValue>::Remove(TKey key)
	{
		KeyValuePair<TKey, TValue> pair = KeyValuePair<TKey, TValue>(key);
		int index = BinaryFindIndex(_dictionary, pair, _sortFunction);
		if (index != -1)
		{
			_dictionary.Remove(index);
		}
		else
		{
			throw KeyNotFoundException;
		}
	}

	template<class TKey, class TValue>
	TValue Dictionary<TKey, TValue>::TakeValue(TKey key) const
	{
		KeyValuePair<TKey, TValue> pair = KeyValuePair<TKey, TValue>(key);
		return BinaryFindValue(_dictionary, pair, _sortFunction).Value;
	}

	template<class TKey, class TValue>
	TValue& Dictionary<TKey, TValue>::TakeItem(TKey key)
	{
		KeyValuePair<TKey, TValue> pair = KeyValuePair<TKey, TValue>(key);
		return BinaryFindItem(_dictionary, pair, _sortFunction).Value;
	}

	template<class TKey, class TValue>
	void* Dictionary<TKey, TValue>::Forward(void* pointer) const
	{
		return _dictionary.Forward(pointer);
	}

	template<class TKey, class TValue>
	bool Dictionary<TKey, TValue>::IsForward(void* pointer) const
	{
		return _dictionary.IsForward(pointer);
	}

	template<class TKey, class TValue>
	void* Dictionary<TKey, TValue>::Back(void* pointer) const
	{
		return _dictionary.Back(pointer);
	}

	template<class TKey, class TValue>
	bool Dictionary<TKey, TValue>::IsBack(void* pointer) const
	{
		return _dictionary.IsBack(pointer);
	}

	template<class TKey, class TValue>
	KeyValuePair<TKey, TValue> Dictionary<TKey, TValue>::TakeValue(void* pointer) const
	{
		return _dictionary.TakeValue(pointer);
	}

	template<class TKey, class TValue>
	ConstForwardIterator<KeyValuePair<TKey, TValue>>
		Dictionary<TKey, TValue>::CreateConstForwardBegin() const
	{
		return _dictionary.CreateConstForwardBegin();
	}

	template<class TKey, class TValue>
	ConstForwardIterator<KeyValuePair<TKey, TValue>>
		Dictionary<TKey, TValue>::CreateConstForwardEnd() const
	{
		return _dictionary.CreateConstForwardEnd();
	}

	template<class TKey, class TValue>
	ConstBackIterator<KeyValuePair<TKey, TValue>>
		Dictionary<TKey, TValue>::CreateConstBackBegin() const
	{
		return _dictionary.CreateConstBackBegin();
	}

	template<class TKey, class TValue>
	ConstBackIterator<KeyValuePair<TKey, TValue>>
		Dictionary<TKey, TValue>::CreateConstBackEnd() const
	{
		return _dictionary.CreateConstBackEnd();
	}
}