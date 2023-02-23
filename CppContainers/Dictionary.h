#pragma once

#include "IDictonary.h"
#include "SortFunctions.h"
#include "DynamicArray.h"
#include "KeyValuePair.h"

namespace Containers
{
	template<class TKey, class TValue>
	class Dictionary : IDictionary<TKey, TValue>
	{
	private:
		bool (*_sortFunction)(KeyValuePair<TKey, TValue>, KeyValuePair<TKey, TValue>) =
			IsLess;

		Array<KeyValuePair<TKey, TValue>> _dictionary;
	public:
		size_t GetSize() const override;

		bool IsEmpty() const override;

		Dictionary();

		~Dictionary();

		void Add(TValue value, TKey key) override;

		void Remove(TKey key) override;

		TValue TakeValue(TKey key) const override;

		TValue& TakeItem(TKey key) override;

		void* Forward(void* pointer) const override;

		bool IsForward(void* pointer) const override;

		void* Back(void* pointer) const override;

		bool IsBack(void* pointer) const override;

		KeyValuePair<TKey, TValue> TakeValue(void* pointer) const override;

		ConstForwardIterator<KeyValuePair<TKey, TValue>> CreateConstForwardBegin() const override;

		ConstForwardIterator<KeyValuePair<TKey, TValue>> CreateConstForwardEnd() const override;

		ConstBackIterator<KeyValuePair<TKey, TValue>> CreateConstBackBegin() const override;

		ConstBackIterator<KeyValuePair<TKey, TValue>> CreateConstBackEnd() const override;
	};
}