#pragma once

#include "AdditionalFunctions.h"

namespace Containers
{
	int Find—oprime(int number)
	{
		for (int result = 2; true; ++result)
		{
			bool isCompire = true;
			for (int n = 2; n < result && n < number; ++n)
			{
				if (result % n == 0 && number % n == 0)
				{
					isCompire = false;
					break;
				}
			}
			if (isCompire)
			{
				return result;
			}
			++result;
		}
	}
}