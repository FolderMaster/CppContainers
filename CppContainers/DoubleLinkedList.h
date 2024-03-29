#pragma once

#include "IFullContainer.h"

#include "DoubleLinkedListSegment.h"

namespace Containers
{
	template <class T>
	class DoubleLinkedList : public IFullContainer<T, int>
	{
	private:
		DoubleSegment<T>* _head;

		DoubleSegment<T>* _tail;

		DoubleSegment<T>* GetPointerOfIndex(int index) const;

		void CreateByDoubleLinkedList(const DoubleLinkedList<T>& other);
	public:
		size_t GetSize() const override;

		bool IsEmpty() const override;

		T& operator[](int index);

		DoubleLinkedList();

		DoubleLinkedList(const DoubleLinkedList<T>& other);

		~DoubleLinkedList();

		DoubleLinkedList<T>& operator=(const DoubleLinkedList<T>& other);

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

		void* Back(void* pointer) const override;

		bool IsBack(void* pointer) const override;

		T TakeValue(void* pointer) const override;

		T& TakeItem(void* pointer) override;

		const T& TakeConstItem(void* pointer) const override;

		ConstForwardIterator<T> CreateConstForwardBegin() const override;

		ConstForwardIterator<T> CreateConstForwardEnd() const override;

		ConstBackIterator<T> CreateConstBackBegin() const override;

		ConstBackIterator<T> CreateConstBackEnd() const override;

		ConstFullIterator<T> CreateConstFullBegin() const override;

		ConstFullIterator<T> CreateConstFullEnd() const override;

		ConstFullIterator<T> CreateConstBackFullBegin() const override;

		ConstFullIterator<T> CreateConstBackFullEnd() const override;

		ForwardIterator<T> CreateForwardBegin() override;

		ForwardIterator<T> CreateForwardEnd() override;

		BackIterator<T> CreateBackBegin() override;

		BackIterator<T> CreateBackEnd() override;

		FullIterator<T> CreateFullBegin() override;

		FullIterator<T> CreateFullEnd() override;

		FullIterator<T> CreateBackFullBegin() override;

		FullIterator<T> CreateBackFullEnd() override;
	};

	template<class T>
	using DoubleList = DoubleLinkedList<T>;
}