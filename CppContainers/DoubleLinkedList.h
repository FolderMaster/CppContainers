#pragma once

#include "IAddable.h"
#include "IRemoveable.h"
#include "IValueContainerTakeable.h"
#include "IItemContainerTakeable.h"
#include "ISizeGetable.h"
#include "IConstForwardIterable.h"
#include "IConstBackIterable.h"
#include "DoubleLinkedListSegment.cpp"

namespace Containers
{
	template <class T>
	class DoubleLinkedList : IAddable<T, size_t>, IRemoveable<size_t>, ISizeGetable,
		IItemContainerTakeable<T, size_t>, IValueContainerTakeable<T, size_t>,
		IConstForwardIterable<T>, IConstBackIterable<T>
	{
	private:
		DoubleSegment<T>* _head = nullptr;

		DoubleSegment<T>* _tail = nullptr;

		DoubleSegment<T>* GetPointerOfIndex(int index);
	public:
		size_t GetSize();

		T& operator[](size_t index);

		DoubleLinkedList();

		~DoubleLinkedList();

		void Add(T value, size_t index) override;

		void Remove(size_t index) override;

		T TakeValue(size_t index) override;

		T& TakeItem(size_t index) override;

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