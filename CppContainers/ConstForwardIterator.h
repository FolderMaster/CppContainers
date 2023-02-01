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
		void* _pointer = nullptr;

		IConstForwardIterable<T>& _iterable;
	public:
		ConstForwardIterator(void* pointer, IConstForwardIterable<T>& iterable);

		bool operator!=(ConstForwardIterator<T> it);

		void Forward() override;

		bool IsForward() override;

		T TakeValue() override;
	};
}