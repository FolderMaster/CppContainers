#pragma once

namespace Containers
{
	template<class T>
	class IAddable
	{
	public:
		virtual void Add() = 0;
		virtual void Add(T value) = 0;
	};
}