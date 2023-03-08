#include <iostream>

#include "Containers.h"

using namespace std;
using namespace Containers;

int main()
{
	Array<double> array = Array<double>();
	for (int n = 0; n < 10; ++n)
	{
		array.AddValueEnd(n);
		FullIterator<double> begin = array.CreateFullBegin();
		while (begin.IsForward())
		{
			cout << begin.TakeItem()++ << "\t";
			begin.Forward();
		}
		cout << endl;
	}
	for (int n = 0; n < 10; ++n)
	{
		array.RemoveEnd();
		ConstFullIterator<double> begin = array.CreateConstFullBegin();
		while (begin.IsForward())
		{
			cout << begin.TakeValue() << "\t";
			begin.Forward();
		}
		cout << endl;
	}
	cout << endl;

	DoubleList<double> doubleList = DoubleList<double>();
	for (int n = 0; n < 10; ++n)
	{
		doubleList.AddValueEnd(n);
		FullIterator<double> begin = doubleList.CreateBackFullBegin();
		while (begin.IsBack())
		{
			cout << begin.TakeItem()-- << "\t";
			begin.Back();
		}
		cout << endl;
	}
	for (int n = 0; n < 10; ++n)
	{
		doubleList.RemoveEnd();
		ConstFullIterator<double> begin = doubleList.CreateConstBackFullBegin();
		while (begin.IsBack())
		{
			cout << begin.TakeValue() << "\t";
			begin.Back();
		}
		cout << endl;
	}
	cout << endl;

	SingleList<double> singleList = SingleList<double>();
	for (int n = 0; n < 10; ++n)
	{
		singleList.AddValueEnd(n);
		ForwardIterator<double> begin = singleList.CreateForwardBegin();
		while (begin.IsForward())
		{
			cout << begin.TakeItem()-- << "\t";
			begin.Forward();
		}
		cout << endl;
	}
	for (int n = 0; n < 10; ++n)
	{
		singleList.RemoveEnd();
		ConstForwardIterator<double> begin = singleList.CreateConstForwardBegin();
		while (begin.IsForward())
		{
			cout << begin.TakeValue() << " ";
			begin.Forward();
		}
		cout << endl;
	}
	cout << endl;

	SingleList<double> stackList = SingleList<double>();
	SingleList<double> minStackList = SingleList<double>();
	SingleList<double> maxStackList = SingleList<double>();
	MinMaxStack<double> stack = MinMaxStack<double>(stackList, minStackList, maxStackList);
	for (int n = 0; n < 10; ++n)
	{
		cout << "Push:" << n << endl;
		stack.PushValue(n);
	}
	cout << endl;
	for (int n = 0; n < 10; ++n)
	{
		cout << "Min:" << stack.GetMin() << endl;
		cout << "Max:" << stack.GetMax() << endl;
		cout << "Pop:" << stack.Pop() << endl;
		cout << endl;
	}

	SingleList<double> enqueueList = SingleList<double>();
	SingleList<double> dequeueList = SingleList<double>();
	StacksQueue<double> queue = StacksQueue<double>(enqueueList, dequeueList);
	for (int n = 0; n < 10; ++n)
	{
		cout << "Enqueue:" << n << endl;
		queue.EnqueueValue(n);
	}
	cout << endl;
	for (int n = 0; n < 10; ++n)
	{
		cout << "Dequeue:" << queue.Dequeue() << endl;
	}
	cout << endl;

	Array<KeyValuePair<string, string>> pairArray = Array<KeyValuePair<string, string>>();
	pairArray.AddValueEnd(KeyValuePair<string, string>("a", "1"));
	pairArray.AddValueEnd(KeyValuePair<string, string>("b", "2"));
	pairArray.AddValueEnd(KeyValuePair<string, string>("c", "3"));
	pairArray.AddValueEnd(KeyValuePair<string, string>("u", "4"));
	pairArray.AddValueEnd(KeyValuePair<string, string>("e", "5"));
	pairArray.AddValueEnd(KeyValuePair<string, string>("a", "6"));
	pairArray.AddValueEnd(KeyValuePair<string, string>("w", "7"));
	pairArray.AddValueEnd(KeyValuePair<string, string>("a", "8"));
	pairArray.AddValueEnd(KeyValuePair<string, string>("b", "9"));
	pairArray.AddValueEnd(KeyValuePair<string, string>("p", "10"));
	pairArray.AddValueEnd(KeyValuePair<string, string>("c", "11"));
	pairArray.AddValueEnd(KeyValuePair<string, string>("c", "12"));
	MultiDictionary<string, string> dictionary = MultiDictionary<string, string>();
	for (int n = 0; n < 12; ++n)  
	{
		KeyValuePair<string, string> pair = pairArray.TakeItem(n);
		dictionary.AddItem(pair.Value, pair.Key);
		ConstForwardIterator<KeyValuePair<string, SingleList<string>>> begin =
			dictionary.CreateConstForwardBegin();
		while (begin.IsForward())
		{
			cout << begin.TakeConstItem().Key << "\t" << endl;
			ConstForwardIterator<string> listBegin =
				begin.TakeConstItem().Value.CreateConstForwardBegin();
			cout << "\t";
			while (listBegin.IsForward())
			{
				cout << listBegin.TakeConstItem() << "\t";
				listBegin.Forward();
			}
			cout << endl;
			begin.Forward();
		}
		cout << endl;
	}
	KeyValuePair<string, string> pair = KeyValuePair<string, string>("c");
	IForwardIterable<KeyValuePair<string, string>&> &result = LinearFindItems(pairArray,
		pair);
	ForwardIterator<KeyValuePair<string, string>&> begin = result.CreateForwardBegin();
	while (begin.IsForward())
	{
		cout << (begin.TakeItem().Key += "fdasjlk") << "\t" << begin.TakeItem().Value << endl;
		begin.Forward();
	}
	cout << endl;
	ForwardIterator<KeyValuePair<string, string>> defaultBegin = pairArray.CreateForwardBegin();
	while (defaultBegin.IsForward())
	{
		cout << defaultBegin.TakeValue().Key << "\t" << defaultBegin.TakeValue().Value << endl;
		defaultBegin.Forward();
	}
	cout << endl;

	MultiHashTable<string, string> hashTable = MultiHashTable<string, string>(PearsonHash);
	for (int n = 0; n < pairArray.GetSize(); ++n)
	{
		KeyValuePair<string, string> pair = pairArray.TakeValue(n);
		hashTable.AddItem(pair.Value, pair.Key);
		for (int k = 0; k < n + 1; ++k)
		{
			SingleList<string>& value = hashTable.TakeItem(pairArray[k].Key);
			ConstForwardIterator<string> begin = value.CreateConstForwardBegin();
			while (begin.IsForward())
			{
				cout << begin.TakeConstItem() << "\t";
				begin.Forward();
			}
			cout << endl;
		}
		cout << endl;
	}

	BinaryTree<double> tree = BinaryTree<double>();
	for (int n = 0; n < 12; ++n)
	{
		tree.AddValue(n);
		for (int k = 0; k < n + 1; ++k)
		{
			const double& value = tree.TakeConstItem(k);
			cout << value << "\t";
		}
		cout << endl;
	}
}