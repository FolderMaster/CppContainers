#pragma once

#include "Stack.h"

namespace Containers
{
	template <class T>
	class MinStack : public Stack<T>
	{
	protected:
		IStackContainer<T>& _minContainer;
	public:
		MinStack(IStackContainer<T>& container, IStackContainer<T>& minContainer);

		~MinStack();

		virtual void Add(T value) override;

		virtual T TakeValue() override;

		T GetMin();
	};
}