#pragma once

#include "HashFunctions.h"
#include "AdditionalFunctions.h"

using namespace std;

namespace Containers
{
	int PearsonHash(string key, size_t size)
	{
		const int coprime = Find—oprime(size);
		int result = 0;
		int coprimeNumber = 1;
		for (int n = 0; n < key.size(); ++n, coprimeNumber *= coprime)
		{
			result += key[n] * coprimeNumber;
		}
		return result % size;
	}
}