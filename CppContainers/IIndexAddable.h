#pragma once

#include "ISpecificAddable.h"

namespace Containers
{
    template<class T>
    class IIndexAddable : public ISpecificAddable<T>
    {
        virtual void Add(int index) = 0;
        virtual void Add(int index, T item) = 0;
    };
}