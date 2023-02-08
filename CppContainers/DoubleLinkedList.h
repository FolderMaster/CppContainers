#pragma once

#include "IAddable.h"
#include "IRemoveable.h"
#include "IValueContainerTakeable.h"
#include "IItemContainerTakeable.h"
#include "ISizeGetable.h"
#include "IConstForwardIterable.h"
#include "IConstBackIterable.h"
#include "IStackContainer.h"
#include "DoubleLinkedListSegment.cpp"

namespace Containers
{
	template <class T>
	class DoubleLinkedList : IAddable<T, int>, IRemoveable<int>, ISizeGetable,
		IItemContainerTakeable<T, int>, IValueContainerTakeable<T, int>,
		IConstForwardIterable<T>, IConstBackIterable<T>, public IStackContainer<T>
	{
	private:
		DoubleSegment<T>* _head = nullptr;

		DoubleSegment<T>* _tail = nullptr;

		DoubleSegment<T>* GetPointerOfIndex(int index);
	public:
		size_t GetSize();

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