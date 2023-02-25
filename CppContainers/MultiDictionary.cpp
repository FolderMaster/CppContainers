#pragma once

#include "MultiDictionary.h"

#include "SearchFunctions.h"
#include "SortFunctions.h"
#include "Exceptions.h"

namespace Containers
{
	template<class TKey, class TValue>
	size_t MultiDictionary<TKey, TValue>::GetSize() const
	{
		return _dictionary.GetSize();
	}

	template<class TKey, class TValue>
	bool MultiDictionary<TKey, TValue>::IsEmpty() const
	{
		return _dictionary.IsEmpty();
	}

	template<class TKey, class TValue>
	MultiDictionary<TKey, TValue>::MultiDictionary() :
		_dictionary(Array<KeyValuePair<TKey, SingleList<TValue>>>()) {}

	template<class TKey, class TValue>
	MultiDictionary<TKey, TValue>::MultiDictionary(const MultiDictionary<TKey, TValue>& other) :
		_dictionary(other._dictionary), _sortFunction(other._sortFunction) {}

	template<class TKey, class TValue>
	MultiDictionary<TKey, TValue>::~MultiDictionary() {}

	template<class TKey, class TValue>
	MultiDictionary<TKey, TValue>& MultiDictionary<TKey, TValue>::operator=(const
		MultiDictionary<TKey, TValue>& other)
	{
		if (this != &other)
		{
			_dictionary = other._dictionary;
			_sortFunction = other._sortFunction;
		}
		return *this;
	}

	template<class TKey, class TValue>
	void MultiDictionary<TKey, TValue>::Add(TValue value, TKey key)
	{
		KeyValuePair<TKey, SingleList<TValue>> pair = KeyValuePair<TKey, SingleList<TValue>>(key);
		int index = BinaryFindIndex(_dictionary, pair, _sortFunction);
		if (index == -1)
		{
			pair.Value = SingleList<TValue>();
			pair.Value.AddBegin(value);
			_dictionary.AddEnd(pair);
			BubbleSort(_dictionary, _sortFunction);
		}
		else
		{
			_dictionary[index].Value.AddEnd(value);
		}
	}

	template<class TKey, class TValue>
	void MultiDictionary<TKey, TValue>::Remove(TKey key)
	{
		KeyValuePair<TKey, SingleList<TValue>> pair = KeyValuePair<TKey, SingleList<TValue>>(key);
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
	SingleList<TValue> MultiDictionary<TKey, TValue>::TakeValue(TKey key) const
	{
		KeyValuePair<TKey, SingleList<TValue>> pair = KeyValuePair<TKey, SingleList<TValue>>(key);
		return BinaryFindValue(_dictionary, pair, _sortFunction).Value;
	}

	template<class TKey, class TValue>
	SingleList<TValue>& MultiDictionary<TKey, TValue>::TakeItem(TKey key)
	{
		KeyValuePair<TKey, SingleList<TValue>> pair = KeyValuePair<TKey, SingleList<TValue>>(key);
		return BinaryFindItem(_dictionary, pair, _sortFunction).Value;
	}

	template<class TKey, class TValue>
	const SingleList<TValue>& MultiDictionary<TKey, TValue>::TakeConstItem(TKey key) const
	{
		KeyValuePair<TKey, SingleList<TValue>> pair = KeyValuePair<TKey, SingleList<TValue>>(key);
		return BinaryFindConstItem(_dictionary, pair, _sortFunction).Value;
	}

	template<class TKey, class TValue>
	void* MultiDictionary<TKey, TValue>::Forward(void* pointer) const
	{
		return _dictionary.Forward(pointer);
	}

	template<class TKey, class TValue>
	bool MultiDictionary<TKey, TValue>::IsForward(void* pointer) const
	{
		return _dictionary.IsForward(pointer);
	}

	template<class TKey, class TValue>
	void* MultiDictionary<TKey, TValue>::Back(void* pointer) const
	{
		return _dictionary.Back(pointer);
	}

	template<class TKey, class TValue>
	bool MultiDictionary<TKey, TValue>::IsBack(void* pointer) const
	{
		return _dictionary.IsBack(pointer);
	}

	template<class TKey, class TValue>
	KeyValuePair<TKey, SingleList<TValue>>
		MultiDictionary<TKey, TValue>::TakeValue(void* pointer) const
	{
		return _dictionary.TakeValue(pointer);
	}

	template<class TKey, class TValue>
	const KeyValuePair<TKey, SingleList<TValue>>&
		MultiDictionary<TKey, TValue>::TakeConstItem(void* pointer) const
	{
		return _dictionary.TakeConstItem(pointer);
	}

	template<class TKey, class TValue>
	ConstForwardIterator<KeyValuePair<TKey, SingleList<TValue>>>
		MultiDictionary<TKey, TValue>::CreateConstForwardBegin() const
	{
		return _dictionary.CreateConstForwardBegin();
	}

	template<class TKey, class TValue>
	ConstForwardIterator<KeyValuePair<TKey, SingleList<TValue>>>
		MultiDictionary<TKey, TValue>::CreateConstForwardEnd() const
	{
		return _dictionary.CreateConstForwardEnd();
	}

	template<class TKey, class TValue>
	ConstBackIterator<KeyValuePair<TKey, SingleList<TValue>>>
		MultiDictionary<TKey, TValue>::CreateConstBackBegin() const
	{
		return _dictionary.CreateConstBackBegin();
	}

	template<class TKey, class TValue>
	ConstBackIterator<KeyValuePair<TKey, SingleList<TValue>>>
		MultiDictionary<TKey, TValue>::CreateConstBackEnd() const
	{
		return _dictionary.CreateConstBackEnd();
	}
}