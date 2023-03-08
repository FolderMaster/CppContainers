#pragma once

#include "IBinaryTree.h"

#include "BinaryTreeSegment.h"

namespace Containers
{
	template<class T>
	class BinarySearchTree : public IBinaryTree<T>
	{
	private:
		TreeSegment<T>* _root;

		void RemoveSegment(TreeSegment<T>* current, TreeSegment<T>* change);

		void ReplaceSegment(TreeSegment<T>* current, TreeSegment<T>* change);

		TreeSegment<T>* FindMinSegment(TreeSegment<T>* pointer);

		TreeSegment<T>* FindSegment(const T& value) const;

		void CreateByBinarySearchTree(const BinarySearchTree<T>& other);
	public:
		size_t GetSize() const override;

		bool IsEmpty() const override;

		BinarySearchTree();

		BinarySearchTree(const BinarySearchTree<T>& other);

		~BinarySearchTree();

		BinarySearchTree<T>& operator=(const BinarySearchTree<T>& other);

		void AddValue(T value) override;

		void Remove(T value) override;

		void Clear() override;

		T TakeValue(T value) const override;

		const T& TakeConstItem(T value) const override;
	};

	template<class T>
	using BinaryTree = BinarySearchTree<T>;
}