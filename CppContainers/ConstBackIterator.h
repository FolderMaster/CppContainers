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
		void* _pointer;

		const IConstBackIterable<T>& _iterable;
	public:
		ConstBackIterator(void* pointer, const IConstBackIterable<T>& iterable);

		bool operator!=(ConstBackIterator<T> it);

		void Back() override;

		bool IsBack() const override;

		T TakeValue() const override;
	};
}