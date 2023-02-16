#pragma once

#include "IAddable.h"
#include "IRemoveable.h"
#include "IValueContainerTakeable.h"
#include "IItemContainerTakeable.h"
#include "ISizeGetable.h"
#include "IConstForwardIterable.h"
#include "IStackContainer.h"
#include "IQueueContainer.h"
#include "SingleLinkedListSegment.cpp"

namespace Containers
{
	template <class T>
	class SingleLinkedList : IAddable<T, int>, IRemoveable<int>, ISizeGetable,
		IItemContainerTakeable<T, int>, IValueContainerTakeable<T, int>,
		IConstForwardIterable<T>, public IStackContainer<T>, public IQueueContainer<T>
	{
	private:
		SingleSegment<T>* _head = nullptr;

		SingleSegment<T>* _tail = nullptr;

		SingleSegment<T>* GetPointerOfIndex(int index);
	public:
		size_t GetSize();

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