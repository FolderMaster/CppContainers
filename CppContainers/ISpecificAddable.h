#pragma once

#include "IAddable.h"

namespace Containers
{
	template<class T>
	class ISpecificAddable : public IAddable<T>
	{
	public:
		virtual void Add(int index) = 0;
		virtual void Add(int index, T item) = 0;

		virtual void AddBegin() = 0;
		virtual void AddBegin(T item) = 0;

		virtual void AddEnd() = 0;
		virtual void AddEnd(T item) = 0;
	};
}