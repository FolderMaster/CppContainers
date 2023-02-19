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

		SingleSegment<T>* GetPointerOfIndex(int index);
	public:
		size_t GetSize() override;

		bool IsEmpty() override;

		SingleLinkedList();

		~SingleLinkedList();

		T& operator[](int index);

		void Add(T value, int index) override;

		void AddBegin(T value) override;

		void AddEnd(T value) override;

		void Remove(int index) override;

		void RemoveBegin() override;

		void RemoveEnd() override;

		T TakeValue(int index) override;

		T TakeValueBegin() override;

		T TakeValueEnd() override;

		T& TakeItem(int index) override;

		void* Forward(void* pointer) override;

		bool IsForward(void* pointer) override;

		T TakeValue(void* pointer) override;

		ConstForwardIterator<T> CreateConstForwardBegin() override;

		ConstForwardIterator<T> CreateConstForwardEnd() override;
	};

	template<class T>
	using SingleList = SingleLinkedList<T>;
}