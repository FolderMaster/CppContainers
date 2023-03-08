#pragma once

#include "ISingleLinkedList.h"
#include "SingleLinkedListSegment.h"

namespace Containers
{
	template <class T>
	class SingleLinkedList : public ISingleLinkedList<T, int>
	{
	private:
		SingleSegment<T>* _head = nullptr;

		SingleSegment<T>* _tail = nullptr;

		SingleSegment<T>* GetPointerOfIndex(int index) const;

		void CreateBySingleLinkedList(const SingleLinkedList<T>& other);
	public:
		size_t GetSize() const override;

		bool IsEmpty() const override;

		T& operator[](int index);

		SingleLinkedList();

		SingleLinkedList(const SingleLinkedList<T>& other);

		~SingleLinkedList();

		SingleLinkedList<T>& operator=(const SingleLinkedList<T>& other);

		void AddValue(T value, int index) override;

		void AddValueBegin(T value) override;

		void AddValueEnd(T value) override;

		void AddItem(T& item, int index) override;

		void AddItemBegin(T& item) override;

		void AddItemEnd(T& item) override;

		void Remove(int index) override;

		void RemoveBegin() override;

		void RemoveEnd() override;

		void Clear() override;

		T TakeValue(int index) const override;

		T TakeValueBegin() const override;

		T TakeValueEnd() const override;

		T& TakeItem(int index) override;

		T& TakeItemBegin() override;

		T& TakeItemEnd() override;

		const T& TakeConstItem(int index) const override;

		const T& TakeConstItemBegin() const override;

		const T& TakeConstItemEnd() const override;

		void* Forward(void* pointer) const override;

		bool IsForward(void* pointer) const override;

		T TakeValue(void* pointer) const override;

		T& TakeItem(void* pointer) override;

		const T& TakeConstItem(void* pointer) const override;

		ConstForwardIterator<T> CreateConstForwardBegin() const override;

		ConstForwardIterator<T> CreateConstForwardEnd() const override;

		ForwardIterator<T> CreateForwardBegin() override;

		ForwardIterator<T> CreateForwardEnd() override;
	};

	template<class T>
	using SingleList = SingleLinkedList<T>;
}