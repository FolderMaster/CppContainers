#pragma once

namespace Containers
{
	template<class T>
	struct DoubleLinkedListSegment
	{
	public:
		T Item;

		DoubleLinkedListSegment<T>* Back = nullptr;

		DoubleLinkedListSegment<T>* Next = nullptr;

		DoubleLinkedListSegment(T item);

		DoubleLinkedListSegment(T item, DoubleLinkedListSegment<T>* back);

		DoubleLinkedListSegment(T item, DoubleLinkedListSegment<T>* back, DoubleLinkedListSegment<T>*
			next);
	};

	template<class T>
	using DoubleSegment = DoubleLinkedListSegment<T>;
}