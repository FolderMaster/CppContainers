#pragma once

#include "IRemovable.h"

namespace Containers
{
    template <class T>
    class IIndexRemovable : public IRemovable<T>
    {
    public:
        virtual void Remove(int index) = 0;

        virtual void RemoveBegin() = 0;

        virtual void RemoveEnd() = 0;
    };
}