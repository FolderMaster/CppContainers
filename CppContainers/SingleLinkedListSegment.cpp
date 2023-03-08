#include "SingleLinkedListSegment.h"

namespace Containers
{
	template<class T>
	SingleLinkedListSegment<T>::SingleLinkedListSegment(const T& item) : Item(item), Next(nullptr)
	{}

	template<class T>
	SingleLinkedListSegment<T>::SingleLinkedListSegment(const T& item,
		SingleLinkedListSegment<T>* next) : Item(item), Next(next) {}
}