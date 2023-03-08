#pragma once

namespace Containers
{
	template<class T>
	struct DoubleLinkedListSegment
	{
	public:
		T Item;

		DoubleLinkedListSegment<T>* Back;

		DoubleLinkedListSegment<T>* Next;

		DoubleLinkedListSegment(const T& item);

		DoubleLinkedListSegment(const T& item, DoubleLinkedListSegment<T>* back);

		DoubleLinkedListSegment(const T& item, DoubleLinkedListSegment<T>* back,
			DoubleLinkedListSegment<T>* next);
	};

	template<class T>
	using DoubleSegment = DoubleLinkedListSegment<T>;
}