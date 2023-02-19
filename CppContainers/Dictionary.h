#pragma once

#include "IDictonary.h"
#include "SortFunctions.cpp"
#include "DynamicArray.cpp"
#include "KeyValuePair.cpp"

namespace Containers
{
	template<class TKey, class TValue>
	class Dictionary : IDictionary<TKey, TValue>
	{
	private:
		const bool (*_sortFunction)(KeyValuePair<TKey, TValue> a, KeyValuePair<TKey, TValue> b) =
			IsLess;

		Array<KeyValuePair<TKey, TValue>> _dictionary;
	public:
		Dictionary();

		~Dictionary();

		void Add(TValue value, TKey key) override;

		void Remove(TKey key) override;

		TValue ValueTake(TKey key) override;

		TValue& ItemTake(TKey key) override;
	};
}