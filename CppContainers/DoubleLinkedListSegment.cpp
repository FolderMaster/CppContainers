#pragma once

#include "DoubleLinkedListSegment.h"

namespace Containers
{
	template<class T>
	DoubleLinkedListSegment<T>::DoubleLinkedListSegment(T item) : Item(item) {}

	template<class T>
	DoubleLinkedListSegment<T>::DoubleLinkedListSegment(T item, DoubleLinkedListSegment<T>* back,
		DoubleLinkedListSegment<T>* next) : Item(item), Back(back), Next(next) {}
}