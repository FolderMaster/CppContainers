#pragma once

#include "MinStack.h"
#include "MaxStack.h"

namespace Containers
{
	template <class T>
	class MinMaxStack : public MinStack<T>, public MaxStack<T>
	{
	public:
		MinMaxStack(IStackContainer<T>& container, IStackContainer<T>& minContainer,
			IStackContainer<T>& maxContainer);

		~MinMaxStack();

		virtual void Add(T value) override;

		virtual T TakeValue() override;
	};
}