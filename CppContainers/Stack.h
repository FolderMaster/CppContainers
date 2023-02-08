#pragma once

#include "IStackContainer.h"
#include "ISimpleAddable.h"
#include "ISimpleValueTakeable.h"

namespace Containers
{
	template<class T>
	class Stack : public ISimpleValueTakeable<T>, public ISimpleAddable<T>
	{
	public:
		IStackContainer<T>& _container;
	public:
		Stack(IStackContainer<T>& container);

		~Stack();

		virtual void Add(T value) override;

		virtual T TakeValue() override;
	};
}