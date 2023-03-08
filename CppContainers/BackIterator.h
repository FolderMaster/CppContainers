#pragma once

#include "IForwardIterator.h"

namespace Containers
{
	template <class TValue>
	class IBackIterable;

	template <class T>
	class BackIterator : public IForwardIterator<T, T>
	{
	private:
		void* _pointer;

		IBackIterable<T>* _iterable;
	public:
		BackIterator(void* pointer, IBackIterable<T>* iterable);

		BackIterator(const BackIterator<T>& other);

		BackIterator<T>& operator=(const BackIterator<T>& other);

		bool operator!=(BackIterator<T> it);

		void Forward() override;

		bool IsForward() const override;

		T TakeValue() const override;

		T& TakeItem() override;

		const T& TakeConstItem() const override;
	};
}