#pragma once

#include "ISpecificAddable.h"
#include "ISpecificRemoveable.h"
#include "ISpecificValueTakeable.h"
#include "ISizeGetable.h"

namespace Containers
{
	template<class T>
	class IQueueContainer : public ISpecificAddable<T>, public ISpecificValueTakeable<T>, public
		ISpecificRemoveable, public ISizeGetable {};
}