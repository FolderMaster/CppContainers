#pragma once

#include "BinaryTreeSegment.h"

namespace Containers
{
	template<class T>
	BinaryTreeSegment<T>::BinaryTreeSegment() : Parent(nullptr), Left(nullptr), Right(nullptr) {}

	template<class T>
	BinaryTreeSegment<T>::BinaryTreeSegment(const T& item) : Item(item), Parent(nullptr),
		Left(nullptr), Right(nullptr) {}

	template<class T>
	BinaryTreeSegment<T>::BinaryTreeSegment(const T& item, BinaryTreeSegment<T>* parent) :
		Item(item), Parent(parent), Left(nullptr), Right(nullptr) {}
}