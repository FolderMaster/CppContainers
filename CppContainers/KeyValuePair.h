#pragma once

namespace Containers
{
	template<class TKey, class TValue>
	class KeyValuePair
	{
	public:
		TKey Key;

		TValue Value;

		KeyValuePair();

		KeyValuePair(const KeyValuePair<TKey, TValue>& other);

		KeyValuePair(TKey key);

		KeyValuePair(TKey key, TValue value);

		KeyValuePair<TKey, TValue>& operator=(const KeyValuePair<TKey, TValue>& other);

		bool operator>(const KeyValuePair<TKey, TValue>& other) const;

		bool operator==(const KeyValuePair<TKey, TValue>& other) const;

		bool operator<(const KeyValuePair<TKey, TValue>& other) const;
	};
}