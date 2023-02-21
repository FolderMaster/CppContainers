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

		KeyValuePair(TKey key);

		KeyValuePair(TKey key, TValue value);

		bool operator>(const KeyValuePair<TKey, TValue>& other) const;

		bool operator==(const KeyValuePair<TKey, TValue>& other) const;

		bool operator<(const KeyValuePair<TKey, TValue>& other) const;
	};
}