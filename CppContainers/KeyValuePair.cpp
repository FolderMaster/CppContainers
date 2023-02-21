#include "KeyValuePair.h"

namespace Containers
{
	template<class TKey, class TValue>
	KeyValuePair<TKey, TValue>::KeyValuePair() {}

	template<class TKey, class TValue>
	KeyValuePair<TKey, TValue>::KeyValuePair(TKey key) : Key(key) {}

	template<class TKey, class TValue>
	KeyValuePair<TKey, TValue>::KeyValuePair(TKey key, TValue value) : Key(key), Value(value) {}

	template<class TKey, class TValue>
	bool KeyValuePair<TKey, TValue>::operator>(const KeyValuePair<TKey, TValue>& other) const
	{
		return Key > other.Key;
	}

	template<class TKey, class TValue>
	bool KeyValuePair<TKey, TValue>::operator==(const KeyValuePair<TKey, TValue>& other) const
	{
		return Key == other.Key;
	}

	template<class TKey, class TValue>
	bool KeyValuePair<TKey, TValue>::operator<(const KeyValuePair<TKey, TValue>& other) const
	{
		return Key < other.Key;
	}
}