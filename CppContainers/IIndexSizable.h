#pragma once

#include "ISizable.h"

namespace Containers
{
	class IIndexSizable : public ISizable
	{
	public:
		virtual bool IsInRange(int index) = 0;
	};
}