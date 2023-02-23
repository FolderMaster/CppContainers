#include <iostream>

#include "Containers.h"

using namespace std;
using namespace Containers;

//int value = 10;
//
//const int& GetValue()
//{
//	return value;
//}

int main()
{
	//For remembering! Do it for const container method TakeConstItem! Future me need this!
	/*const int& item = GetValue();
	cout << ++value << endl;
	cout << item << endl;*/

	Array<double> array = Array<double>();
	for (int n = 0; n < 10; ++n)
	{
		array.AddEnd(n);
		ForwardIterator<double> begin = array.CreateForwardBegin();
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
		ConstForwardIterator<double> begin = array.CreateConstForwardBegin();
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
		doubleList.AddEnd(n);
		BackIterator<double> begin = doubleList.CreateBackBegin();
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
		ConstBackIterator<double> begin = doubleList.CreateConstBackBegin();
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
		singleList.AddEnd(n);
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

	SingleList<double> enqueueList = SingleList<double>();
	SingleList<double> dequeueList = SingleList<double>();
	StacksQueue<double> queue = StacksQueue<double>(enqueueList, dequeueList);
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
	cout << endl;

	Array<KeyValuePair<string, string>> pairArray = Array<KeyValuePair<string, string>>();
	pairArray.AddEnd(KeyValuePair<string, string>("a", "1"));
	pairArray.AddEnd(KeyValuePair<string, string>("b", "2"));
	pairArray.AddEnd(KeyValuePair<string, string>("c", "3"));
	pairArray.AddEnd(KeyValuePair<string, string>("u", "4"));
	pairArray.AddEnd(KeyValuePair<string, string>("e", "5"));
	pairArray.AddEnd(KeyValuePair<string, string>("q", "6"));
	pairArray.AddEnd(KeyValuePair<string, string>("w", "7"));
	pairArray.AddEnd(KeyValuePair<string, string>("i", "8"));
	pairArray.AddEnd(KeyValuePair<string, string>("o", "9"));
	pairArray.AddEnd(KeyValuePair<string, string>("p", "10"));
	pairArray.AddEnd(KeyValuePair<string, string>("c", "11"));
	pairArray.AddEnd(KeyValuePair<string, string>("c", "12"));
	Dictionary<string, string> dictionary = Dictionary<string, string>();
	for (int n = 0; n < 10; ++n)  
	{
		KeyValuePair<string, string> pair = pairArray.TakeItem(n);
		dictionary.Add(pair.Value, pair.Key);
		ConstForwardIterator<KeyValuePair<string, string>> begin =
			dictionary.CreateConstForwardBegin();
		while (begin.IsForward())
		{
			cout << begin.TakeValue().Key << "\t" << begin.TakeValue().Value << endl;
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

	HashTable<string, string> hashTable = HashTable<string, string>(PearsonHash);
	for (int n = 0; n < 10; ++n)
	{
		KeyValuePair<string, string> pair = pairArray.TakeValue(n);
		hashTable.Add(pair.Value, pair.Key);
		for (int k = 0; k < n + 1; ++k)
		{
			string value = hashTable.TakeItem(pairArray.TakeValue(k).Key);
			cout << value << "\t";
		}
		cout << endl;
	}
}