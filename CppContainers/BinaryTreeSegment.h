#pragma once

namespace Containers
{
	template<class T>
	struct BinaryTreeSegment
	{
	public:
		T Item;

		BinaryTreeSegment<T>* Parent;

		BinaryTreeSegment<T>* Left;

		BinaryTreeSegment<T>* Right;

		BinaryTreeSegment();

		BinaryTreeSegment(const T& item);

		BinaryTreeSegment(const T& item, BinaryTreeSegment<T>* parent);
	};

	template<class T>
	using TreeSegment = BinaryTreeSegment<T>;
}