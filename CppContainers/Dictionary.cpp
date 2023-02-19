#pragma once

#include "Dictionary.h"

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
		int index = _dictionary.BinaryFindIndex(pair, _sortFunction);
		if (index == -1)
		{
			_dictionary.AddEnd(pair);
			_dictionary.Sort(_sortFunction);
		}
	}

	template<class TKey, class TValue>
	void Dictionary<TKey, TValue>::Remove(TKey key)
	{
		KeyValuePair<TKey, TValue> pair = KeyValuePair<TKey, TValue>(key);
		int index = _dictionary.BinaryFindIndex(pair, _sortFunction);
		if (index != -1)
		{
			_dictionary.Remove(index);
			_dictionary.Sort(_sortFunction);
		}
	}

	template<class TKey, class TValue>
	TValue Dictionary<TKey, TValue>::ValueTake(TKey key)
	{
		return TValue();
	}

	template<class TKey, class TValue>
	TValue& Dictionary<TKey, TValue>::ItemTake(TKey key)
	{
		// TODO: вставьте здесь оператор return
	}
}