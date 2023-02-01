#include <iostream>

#include "Containers.h"

using namespace std;
using namespace Containers;

int main()
{
	DynamicArray<double> array = DynamicArray<double>();
	for (int n = 0; n < 10; ++n)
	{
		array.Add(n, n);
		ConstForwardIterator<double> begin = array.CreateConstForwardBegin();
		ConstForwardIterator<double> end = array.CreateConstForwardEnd();
		while (begin != end)
		{
			cout << begin.TakeValue() << " ";
			begin.Forward();
		}
		cout << endl;
	}
}