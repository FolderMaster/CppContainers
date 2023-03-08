#pragma once

#include "IConstFullIterator.h"

namespace Containers
{
	template <class TValue>
	class IConstFullIterable;

	template<class T>
	class ConstFullIterator : IConstFullIterator<T>
	{
	private:
		void* _pointer;

		const IConstFullIterable<T>* _iterable;
	public:
		ConstFullIterator(void* pointer, const IConstFullIterable<T>* iterable);

		ConstFullIterator(const ConstFullIterator<T>& other);

		ConstFullIterator<T>& operator=(const ConstFullIterator<T>& other);

		bool operator!=(ConstFullIterator<T> it);

		void Forward() override;

		void Back() override;

		bool IsForward() const override;

		bool IsBack() const override;

		T TakeValue() const override;

		const T& TakeConstItem() const override;
	};
}