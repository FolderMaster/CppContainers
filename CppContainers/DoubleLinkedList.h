#pragma once

#include "IFullContainer.h"
#include "DoubleLinkedListSegment.cpp"

namespace Containers
{
	template <class T>
	class DoubleLinkedList : public IFullContainer<T, int>
	{
	private:
		DoubleSegment<T>* _head = nullptr;

		DoubleSegment<T>* _tail = nullptr;

		DoubleSegment<T>* GetPointerOfIndex(int index);
	public:
		size_t GetSize() override;

		bool IsEmpty() override;

		T& operator[](int index);

		DoubleLinkedList();

		~DoubleLinkedList();

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

		void* Back(void* pointer) override;

		bool IsBack(void* pointer) override;

		T TakeValue(void* pointer) override;

		ConstForwardIterator<T> CreateConstForwardBegin() override;

		ConstForwardIterator<T> CreateConstForwardEnd() override;

		ConstBackIterator<T> CreateConstBackBegin() override;

		ConstBackIterator<T> CreateConstBackEnd() override;
	};

	template<class T>
	using DoubleList = DoubleLinkedList<T>;
}