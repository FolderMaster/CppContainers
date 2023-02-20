#pragma once

#include "IFullContainer.h"

namespace Containers
{
	template <class T>
	class DynamicArray : public IFullContainer<T, size_t>
	{
	private:
		const double _growthFactor = 2;

		size_t _capacity;

		size_t _size;

		T* _array;

		T* Resize(size_t newSize);
	public:
		size_t GetSize() const override;

		bool IsEmpty() const override;

		T& operator[](size_t index);

		DynamicArray();

		DynamicArray(const DynamicArray<T>& other);

		~DynamicArray();

		DynamicArray<T>& operator=(const DynamicArray<T>& other);

		void Add(T value, size_t index) override;

		void AddBegin(T value) override;

		void AddEnd(T value) override;

		void Remove(size_t index) override;

		void RemoveBegin() override;

		void RemoveEnd() override;

		void Clear() override;

		T TakeValue(size_t index) const override;

		T TakeValueBegin() const override;

		T TakeValueEnd() const override;

		T& TakeItem(size_t index) override;

		void* Forward(void* pointer) const override;

		bool IsForward(void* pointer) const override;

		void* Back(void* pointer) const override;

		bool IsBack(void* pointer) const override;

		T TakeValue(void* pointer) const override;

		T& TakeItem(void* pointer) override;

		ConstForwardIterator<T> CreateConstForwardBegin() const override;

		ConstForwardIterator<T> CreateConstForwardEnd() const override;

		ConstBackIterator<T> CreateConstBackBegin() const override;

		ConstBackIterator<T> CreateConstBackEnd() const override;

		ForwardIterator<T> CreateForwardBegin() override;

		ForwardIterator<T> CreateForwardEnd() override;

		BackIterator<T> CreateBackBegin() override;

		BackIterator<T> CreateBackEnd() override;
	};

	template<class T>
	using Array = DynamicArray<T>;
}