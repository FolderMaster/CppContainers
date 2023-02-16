#include "SingleLinkedListSegment.h"

namespace Containers
{
	template<class T>
	SingleLinkedListSegment<T>::SingleLinkedListSegment(T item) : Item(item) {}

	template<class T>
	SingleLinkedListSegment<T>::SingleLinkedListSegment(T item, SingleLinkedListSegment<T>* next) :
		Item(item), Next(next) {}
}