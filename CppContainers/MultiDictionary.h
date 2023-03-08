#pragma once

#include "IMultiDictonary.h"

#include "KeyValuePair.h"

#include "DynamicArray.h"
#include "SingleLinkedList.h"

#include "SortFunctions.h"

namespace Containers
{
	template<class TKey, class TValue>
	class MultiDictionary : IMultiDictionary<TKey, TValue>
	{
	private:
		bool (*_sortFunction)(KeyValuePair<TKey, SingleList<TValue>>,
			KeyValuePair<TKey, SingleList<TValue>>) = IsLess;

		Array<KeyValuePair<TKey, SingleList<TValue>>> _dictionary;
	public:
		size_t GetSize() const override;

		bool IsEmpty() const override;

		MultiDictionary();

		MultiDictionary(const MultiDictionary<TKey, TValue>& other);

		~MultiDictionary();

		MultiDictionary<TKey, TValue>& operator=(const MultiDictionary<TKey, TValue>& other);

		void AddValue(TValue value, TKey key) override;

		void AddItem(TValue& item, TKey key) override;

		void Remove(TKey key) override;

		void Clear() override;

		SingleList<TValue> TakeValue(TKey key) const override;

		SingleList<TValue>& TakeItem(TKey key) override;

		const SingleList<TValue>& TakeConstItem(TKey key) const override;

		void* Forward(void* pointer) const override;

		bool IsForward(void* pointer) const override;

		void* Back(void* pointer) const override;

		bool IsBack(void* pointer) const override;

		KeyValuePair<TKey, SingleList<TValue>> TakeValue(void* pointer) const override;

		const KeyValuePair<TKey, SingleList<TValue>>& TakeConstItem(void* pointer) const override;

		ConstForwardIterator<KeyValuePair<TKey, SingleList<TValue>>>
			CreateConstForwardBegin() const override;

		ConstForwardIterator<KeyValuePair<TKey, SingleList<TValue>>>
			CreateConstForwardEnd() const override;

		ConstBackIterator<KeyValuePair<TKey, SingleList<TValue>>>
			CreateConstBackBegin() const override;

		ConstBackIterator<KeyValuePair<TKey, SingleList<TValue>>>
			CreateConstBackEnd() const override;
	};
}