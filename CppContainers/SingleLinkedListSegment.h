#pragma once

namespace Containers
{
	template <class T>
	struct SingleLinkedListSegment
	{
	public:
		T Item;

		SingleLinkedListSegment<T>* Next;

		SingleLinkedListSegment(const T& item);

		SingleLinkedListSegment(const T& item, SingleLinkedListSegment<T>* next);
	};

	template<class T>
	using SingleSegment = SingleLinkedListSegment<T>;
}