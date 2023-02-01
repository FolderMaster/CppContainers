#pragma once

#include "IAddable.h"
#include "IRemoveable.h"
#include "IValueContainerTakeable.h"
#include "IItemContainerTakeable.h"
#include "ISizeGetable.h"
#include "IConstForwardIterable.h"

namespace Containers
{
	template <class T>
	class DynamicArray : IAddable<T, size_t>, IRemoveable<size_t>, ISizeGetable,
		IItemContainerTakeable<T, size_t>, IValueContainerTakeable<T, size_t>,
		IConstForwardIterable<T>
	{
	private:
		const double _growthFactor = 2;

		size_t _capacity = 0;

		size_t _size = 0;

		T* _array = nullptr;

		T* Resize(int newSize);
	public:
		size_t GetSize();

		T& operator[](size_t index);

		DynamicArray();

		~DynamicArray();

		void Add(T value, size_t index) override;

		void Remove(size_t index) override;

		T TakeValue(size_t index) override;

		T& TakeItem(size_t index) override;

		void* Forward(void* pointer) override;

		bool IsForward(void* pointer) override;

		T TakeValue(void* pointer) override;

		ConstForwardIterator<T> CreateConstForwardBegin() override;

		ConstForwardIterator<T> CreateConstForwardEnd() override;
	};
}