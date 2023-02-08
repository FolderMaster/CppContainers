#pragma once

#include "Stack.h"

namespace Containers
{
	template <class T>
	class MaxStack : public Stack<T>
	{
	protected:
		IStackContainer<T>& _maxContainer;
	public:
		MaxStack(IStackContainer<T>& container, IStackContainer<T>& maxContainer);

		~MaxStack();

		virtual void Add(T value) override;

		virtual T TakeValue() override;

		T GetMax();
	};
}