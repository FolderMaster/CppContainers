#pragma once

#include "IConstForwardIterator.h"

namespace Containers
{
	template <class TValue>
	class IConstForwardIterable;

	template <class T>
	class ConstForwardIterator : public IConstForwardIterator<T>
	{
	private:
		void* _pointer;

		const IConstForwardIterable<T>& _iterable;
	public:
		ConstForwardIterator(void* pointer, const IConstForwardIterable<T>& iterable);

		bool operator!=(ConstForwardIterator<T> it);

		void Forward() override;

		bool IsForward() const override;

		T TakeValue() const override;

		const T& TakeConstItem() const override;
	};
}