#pragma once

#include "IConstForwardIterator.h"

namespace Containers
{
	template <class TValue>
	class IConstBackIterable;

	template <class T>
	class ConstBackIterator : public IConstForwardIterator<T>
	{
	private:
		void* _pointer;

		const IConstBackIterable<T>& _iterable;
	public:
		ConstBackIterator(void* pointer, const IConstBackIterable<T>& iterable);

		bool operator!=(ConstBackIterator<T> it);

		void Forward() override;

		bool IsForward() const override;

		T TakeValue() const override;

		const T& TakeConstItem() const override;
	};
}