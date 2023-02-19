#pragma once

#include "IStackContainer.h"
#include "IStack.h"

namespace Containers
{
	template<class T>
	class Stack : public IStack<T>
	{
	protected:
		IStackContainer<T>& _container;
	public:
		size_t GetSize() override;

		bool IsEmpty() override;

		Stack(IStackContainer<T>& container);

		~Stack();

		virtual void Push(T value) override;

		virtual T Pop() override;
	};
}