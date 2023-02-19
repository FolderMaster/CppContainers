#include "KeyValuePair.h"

namespace Containers
{
	template<class TKey, class TValue>
	KeyValuePair<TKey, TValue>::KeyValuePair() {}

	template<class TKey, class TValue>
	KeyValuePair<TKey, TValue>::KeyValuePair(TKey key, TValue value) : Key(key), Value(value) {}
}