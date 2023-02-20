#pragma once

#include "ISingleLinkedList.h"
#include "SingleLinkedListSegment.cpp"

namespace Containers
{
	template <class T>
	class SingleLinkedList : ISingleLinkedList<T, int>
	{
	private:
		SingleSegment<T>* _head = nullptr;

		SingleSegment<T>* _tail = nullptr;

		SingleSegment<T>* GetPointerOfIndex(int index) const;
	public:
		size_t GetSize() const override;

		bool IsEmpty() const override;

		SingleLinkedList();

		~SingleLinkedList();

		T& operator[](int index);

		void Add(T value, int index) override;

		void AddBegin(T value) override;

		void AddEnd(T value) override;

		void Remove(int index) override;

		void RemoveBegin() override;

		void RemoveEnd() override;

		void Clear() override;

		T TakeValue(int index) const override;

		T TakeValueBegin() const override;

		T TakeValueEnd() const override;

		T& TakeItem(int index) override;

		void* Forward(void* pointer) const override;

		bool IsForward(void* pointer) const override;

		T TakeValue(void* pointer) const override;

		T& TakeItem(void* pointer) override;

		ConstForwardIterator<T> CreateConstForwardBegin() const override;

		ConstForwardIterator<T> CreateConstForwardEnd() const override;

		ForwardIterator<T> CreateForwardBegin() override;

		ForwardIterator<T> CreateForwardEnd() override;
	};

	template<class T>
	using SingleList = SingleLinkedList<T>;
}