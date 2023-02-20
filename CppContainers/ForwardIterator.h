#pragma once

#include "IForwardIterator.h"

namespace Containers
{
	template <class TValue>
	class IForwardIterable;

	template <class T>
	class ForwardIterator : public IForwardIterator<T, T>
	{
	private:
		void* _pointer;

		IForwardIterable<T>& _iterable;
	public:
		ForwardIterator(void* pointer, IForwardIterable<T>& iterable);

		bool operator!=(ForwardIterator<T> it);

		void Forward() override;

		bool IsForward() const override;

		T TakeValue() const override;

		T& TakeItem() override;
	};
}