#pragma once

#include "IHashTable.h"

#include "DynamicArray.h"
#include "SingleLinkedList.h"
#include "KeyValuePair.h"

namespace Containers
{
	template<class TKey, class TValue>
	class HashTable : IHashTable<TKey, TValue>
	{
	protected:
		const double _growFactor = 1.5;

		const double _resizeCoefficient = 1;

		Array<SingleList<KeyValuePair<TKey, TValue>>> _hashTable;

		int (*_hashFunction)(TKey, size_t);

		void Rehash();

		bool IsNeedRehash();
	public:
		size_t GetSize() const override;

		bool IsEmpty() const override;

		HashTable(int (*hashFucntion)(TKey, size_t));

		HashTable(const HashTable<TKey, TValue>& other);

		~HashTable();

		HashTable<TKey, TValue>& operator=(const HashTable<TKey, TValue>& other);

		void Add(TValue value, TKey key) override;

		void Remove(TKey key) override;

		TValue TakeValue(TKey key) const override;

		TValue& TakeItem(TKey key) override;

		const TValue& TakeConstItem(TKey key) const override;
	};
}