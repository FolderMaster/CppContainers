#pragma once

#include "ISpecificRemovable.h"

namespace Containers
{
    template<class T>
    class IIndexRemovable : public ISpecificRemovable<T>
    {
    public:
        virtual void Remove(int index) = 0;
    };
}