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

		KeyValuePair(TKey key, TValue value);
	};
}