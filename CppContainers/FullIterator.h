#pragma once

#include "IFullIterator.h"

namespace Containers
{
	template <class TValue>
	class IFullIterable;

	template<class T>
	class FullIterator : IFullIterator<T, T>
	{
	private:
		void* _pointer;

		IFullIterable<T>& _iterable;
	public:
		FullIterator(void* pointer, IFullIterable<T>& iterable);

		bool operator!=(FullIterator<T> it);

		void Forward() override;

		void Back() override;

		bool IsForward() const override;

		bool IsBack() const override;

		T TakeValue() const override;

		T& TakeItem() override;

		const T& TakeConstItem() const override;
	};
}