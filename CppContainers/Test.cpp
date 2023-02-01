#include <iostream>

#include "Containers.h"

using namespace std;
using namespace Containers;

int main()
{
	Array<double> array = Array<double>();
	for (int n = 0; n < 10; ++n)
	{
		array.Add(n, n);
		ConstBackIterator<double> begin = array.CreateConstBackBegin();
		ConstBackIterator<double> end = array.CreateConstBackEnd();
		while (begin != end)
		{
			cout << begin.TakeValue() << " ";
			begin.Back();
		}
		cout << endl;
	}
	for (int n = 0; n < 10; ++n)
	{
		array.Remove(10 - n - 1);
		ConstBackIterator<double> begin = array.CreateConstBackBegin();
		ConstBackIterator<double> end = array.CreateConstBackEnd();
		while (begin != end)
		{
			cout << begin.TakeValue() << " ";
			begin.Back();
		}
		cout << endl;
	}
	DoubleList<double> list = DoubleList<double>();
	for (int n = 0; n < 10; ++n)
	{
		list.Add(n, 0);
		ConstBackIterator<double> begin = list.CreateConstBackBegin();
		ConstBackIterator<double> end = list.CreateConstBackEnd();
		while (begin != end)
		{
			cout << begin.TakeValue() << " ";
			begin.Back();
		}
		cout << endl;
	}
	for (int n = 0; n < 10; ++n)
	{
		list.Remove(0);
		ConstBackIterator<double> begin = list.CreateConstBackBegin();
		ConstBackIterator<double> end = list.CreateConstBackEnd();
		while (begin != end)
		{
			cout << begin.TakeValue() << " ";
			begin.Back();
		}
		cout << endl;
	}
}