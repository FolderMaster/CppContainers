#pragma once

#include "IAddable.h"

namespace Containers
{
    template <class T>
    class IIndexAddable : public IAddable<T>
    {
		virtual void Add(int index, T item = T()) = 0;

		virtual void AddBegin(T item = T()) = 0;

		virtual void AddEnd(T item = T()) = 0;
    };
}