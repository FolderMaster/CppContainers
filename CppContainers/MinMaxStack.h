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

		void CreateByMinMaxStack(const MinMaxStack<T>& other);
	public:
		MinMaxStack(IStackContainer<T>& container, IStackContainer<T>& minContainer,
			IStackContainer<T>& maxContainer);

		MinMaxStack(const MinMaxStack<T>& other);

		~MinMaxStack();

		MinMaxStack<T>& operator=(const MinMaxStack<T>& other);

		void PushValue(T value) override;

		void PushItem(T& item) override;

		T Pop() override;

		T GetMin();

		T GetMax();
	};
}