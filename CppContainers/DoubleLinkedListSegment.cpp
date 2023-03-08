#pragma once

#include "DoubleLinkedListSegment.h"

namespace Containers
{
	template<class T>
	DoubleLinkedListSegment<T>::DoubleLinkedListSegment(const T& item) : Item(item), Back(nullptr),
		Next(nullptr) {}

	template<class T>
	DoubleLinkedListSegment<T>::DoubleLinkedListSegment(const T& item,
		DoubleLinkedListSegment<T>* back) : Item(item), Back(back), Next(nullptr) {};

	template<class T>
	DoubleLinkedListSegment<T>::DoubleLinkedListSegment(const T& item,
		DoubleLinkedListSegment<T>* back, DoubleLinkedListSegment<T>* next) : Item(item),
		Back(back), Next(next) {}
}