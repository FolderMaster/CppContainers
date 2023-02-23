#pragma once

#include "HashFunctions.h"

#include "AdditionalFunctions.h"

namespace Containers
{
	inline int PearsonHash(std::string key, size_t size)
	{
		const int coprime = FindCoprime(size);
		int result = 0;
		int coprimeNumber = 1;
		for (int n = 0; n < key.size(); ++n, coprimeNumber *= coprime)
		{
			result += key[n] * coprimeNumber;
		}
		return result % size;
	}
}