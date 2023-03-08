#pragma once

#include "IMultiHashTable.h"

#include "DynamicArray.h"
#include "SingleLinkedList.h"
#include "KeyValuePair.h"

namespace Containers
{
	template<class TKey, class TValue>
	class MultiHashTable : IMultiHashTable<TKey, TValue>
	{
	protected:
		const double _growFactor = 1.5;

		const double _resizeCoefficient = 1;

		Array<SingleList<KeyValuePair<TKey, SingleList<TValue>>>> _hashTable;

		int (*_hashFunction)(TKey, size_t);

		void Rehash();

		bool IsNeedRehash();
	public:
		size_t GetSize() const override;

		bool IsEmpty() const override;

		MultiHashTable(int (*hashFucntion)(TKey, size_t));

		MultiHashTable(const MultiHashTable<TKey, TValue>& other);

		~MultiHashTable();

		MultiHashTable<TKey, TValue>& operator=(const MultiHashTable<TKey, TValue>& other);

		void AddValue(TValue value, TKey key) override;

		void AddItem(TValue& item, TKey key) override;

		void Remove(TKey key) override;

		void Clear() override;

		SingleList<TValue> TakeValue(TKey key) const override;

		SingleList<TValue>& TakeItem(TKey key) override;

		const SingleList<TValue>& TakeConstItem(TKey key) const override;
	};
}