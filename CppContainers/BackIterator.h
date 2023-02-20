#pragma once

#include "IBackIterator.h"

namespace Containers
{
	template <class TValue>
	class IBackIterable;

	template <class T>
	class BackIterator : public IBackIterator<T, T>
	{
	private:
		void* _pointer;

		IBackIterable<T>& _iterable;
	public:
		BackIterator(void* pointer, IBackIterable<T>& iterable);

		bool operator!=(BackIterator<T> it);

		void Back() override;

		bool IsBack() const override;

		T TakeValue() const override;

		T& TakeItem() override;
	};
}