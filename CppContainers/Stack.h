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

		void CreateByStack(const Stack<T>& other);
	public:
		size_t GetSize() const override;

		bool IsEmpty() const override;

		Stack(IStackContainer<T>& container);

		Stack(const Stack<T>& other);

		~Stack();

		Stack<T>& operator=(const Stack<T>& other);

		virtual void PushValue(T value) override;

		virtual void PushItem(T& item) override;

		virtual T Pop() override;
	};
}