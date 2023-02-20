#include <iostream>

#include "Containers.h"

using namespace std;
using namespace Containers;

int main()
{
	Array<double> array = Array<double>();
	for (int n = 0; n < 10; ++n)
	{
		array.AddEnd(n);
		ForwardIterator<double> begin = array.CreateForwardBegin();
		while (begin.IsForward())
		{
			cout << begin.TakeItem()++ << " ";
			begin.Forward();
		}
		cout << endl;
	}
	for (int n = 0; n < 10; ++n)
	{
		array.RemoveEnd();
		ConstForwardIterator<double> begin = array.CreateConstForwardBegin();
		while (begin.IsForward())
		{
			cout << begin.TakeValue() << " ";
			begin.Forward();
		}
		cout << endl;
	}

	DoubleList<double> doubleList = DoubleList<double>();
	for (int n = 0; n < 10; ++n)
	{
		doubleList.AddEnd(n);
		BackIterator<double> begin = doubleList.CreateBackBegin();
		while (begin.IsBack())
		{
			cout << begin.TakeItem()-- << " ";
			begin.Back();
		}
		cout << endl;
	}
	for (int n = 0; n < 10; ++n)
	{
		doubleList.RemoveEnd();
		ConstBackIterator<double> begin = doubleList.CreateConstBackBegin();
		while (begin.IsBack())
		{
			cout << begin.TakeValue() << " ";
			begin.Back();
		}
		cout << endl;
	}

	SingleList<double> singleList = SingleList<double>();
	for (int n = 0; n < 10; ++n)
	{
		singleList.AddBegin(n);
		ConstForwardIterator<double> begin = singleList.CreateConstForwardBegin();
		while (begin.IsForward())
		{
			cout << begin.TakeValue() << " ";
			begin.Forward();
		}
		cout << endl;
	}
	/*for (int n = 0; n < 10; ++n)
	{
		singleList.Remove(10 - n - 1);
		ConstForwardIterator<double> begin = singleList.CreateConstForwardBegin();
		while (begin.IsForward())
		{
			cout << begin.TakeValue() << " ";
			begin.Forward();
		}
		cout << endl;
	}*/

	Array<double> stackArray = Array<double>();
	Array<double> minStackArray = Array<double>();
	Array<double> maxStackArray = Array<double>();
	MinMaxStack<double> stack = MinMaxStack<double>(stackArray, minStackArray, maxStackArray);
	for (int n = 0; n < 10; ++n)
	{
		cout << "Push:" << n << endl;
		stack.Push(n);
	}
	cout << endl;
	for (int n = 0; n < 10; ++n)
	{
		cout << "Min:" << stack.GetMin() << endl;
		cout << "Max:" << stack.GetMax() << endl;
		cout << "Pop:" << stack.Pop() << endl;
		cout << endl;
	}

	DoubleList<double> enqueueArray = DoubleList<double>();
	DoubleList<double> dequeueArray = DoubleList<double>();
	StacksQueue<double> queue = StacksQueue<double>(enqueueArray, dequeueArray);
	for (int n = 0; n < 10; ++n)
	{
		cout << "Enqueue:" << n << endl;
		queue.Enqueue(n);
	}
	cout << endl;
	for (int n = 0; n < 10; ++n)
	{
		cout << "Dequeue:" << queue.Dequeue() << endl;
	}
}