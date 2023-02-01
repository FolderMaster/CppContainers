#pragma once

#include "IConstBackIterator.h"

namespace Containers
{
	template <class TValue>
	class IConstBackIterable;

	template <class T>
	class ConstBackIterator : public IConstBackIterator<T>
	{
	private:
		void* _pointer = nullptr;

		IConstBackIterable<T>& _iterable;
	public:
		ConstBackIterator(void* pointer, IConstBackIterable<T>& iterable);

		bool operator!=(ConstBackIterator<T> it);

		void Back() override;

		bool IsBack() override;

		T TakeValue() override;
	};
}