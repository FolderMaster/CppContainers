#pragma once

#include "Stack.h"

namespace Containers
{
	template <class T>
	class MinMaxStack : public Stack<T>
	{
	protected:
		IStackContainer<T>& _minContainer;

		IStackContainer<T>& _maxContainer;
	public:
		MinMaxStack(IStackContainer<T>& container, IStackContainer<T>& minContainer,
			IStackContainer<T>& maxContainer);

		~MinMaxStack();

		virtual void Push(T value) override;

		virtual T Pop() override;

		T GetMin();

		T GetMax();
	};
}