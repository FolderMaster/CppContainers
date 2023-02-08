#pragma once

#include "IAddable.h"
#include "IRemoveable.h"
#include "IValueContainerTakeable.h"
#include "IItemContainerTakeable.h"
#include "ISizeGetable.h"
#include "IConstForwardIterable.h"
#include "IStackContainer.h"
#include "IConstBackIterable.h"

namespace Containers
{
	template <class T>
	class DynamicArray : IAddable<T, size_t>, IRemoveable<size_t>, ISizeGetable,
		IItemContainerTakeable<T, size_t>, IValueContainerTakeable<T, size_t>,
		IConstForwardIterable<T>, IConstBackIterable<T>, public IStackContainer<T>
	{
	private:
		const double _growthFactor = 2;

		size_t _capacity = 0;

		size_t _size = 0;

		T* _array = nullptr;

		T* Resize(size_t newSize);
	public:
		size_t GetSize();

		T& operator[](size_t index);

		DynamicArray();

		~DynamicArray();

		void Add(T value, size_t index) override;

		void AddBegin(T value) override;

		void AddEnd(T value) override;

		void Remove(size_t index) override;

		void RemoveBegin() override;

		void RemoveEnd() override;

		T TakeValue(size_t index) override;

		T TakeValueBegin() override;

		T TakeValueEnd() override;

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
	using Array = DynamicArray<T>;
}