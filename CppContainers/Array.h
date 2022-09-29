#pragma once

#include "IFullContainer.h"

namespace Containers
{
	template <class T>
	class Array : public IFullContainer<T>
	{
	private:
		T* _pointer;

		int _size;
	public:
		int GetSize() override
		{
			return _size;
		}

		bool IsEmpty() override
		{
			return _size == 0;
		}

		bool IsInRange(int index) override
		{
			return index >= 0 && index < _size;
		}

		int GetCapacity() override
		{
			return _size * sizeof(T);
		}

		void Add(T item = T()) override
		{
		}

		void Add(int index, T item = T()) override
		{
		}

		void AddBegin(T item = T()) override
		{
		}

		void AddEnd(T item = T()) override
		{
		}

		void Remove() override
		{
		}

		void Remove(int index) override
		{
		}

		void RemoveBegin() override
		{
		}

		void RemoveEnd() override
		{
		}

		T& Take() override
		{
			if (IsEmpty())
			{
			}
			else
			{
				return _pointer[0];
			}
		}

		T& Take(int index) override
		{
			if (!IsInRange(index))
			{
			}
			else
			{
				return _pointer[index];
			}
		}

		T& TakeBegin() override
		{
			if (IsEmpty())
			{
			}
			else
			{
				return _pointer[0];
			}
		}

		T& TakeEnd() override
		{
			if (IsEmpty())
			{
			}
			else
			{
				return _pointer[_size - 1];
			}
		}

		T& Take(void* pointer) override
		{
			return *((T*)pointer);
		}

		void* Forward(void* pointer) override
		{
			return ((T*)pointer) + 1;
		}

		bool IsForward(void* pointer) override
		{
			return ((T*)pointer) + 1 >= _pointer && ((T*)pointer) + 1 < _pointer + _size;
		}

		void* Back(void* pointer) override
		{
			return ((T*)pointer) - 1;
		}

		bool IsBack(void* pointer) override
		{
			return ((T*)pointer) - 1 >= _pointer && ((T*)pointer) - 1 < _pointer + _size;
		}
	};
}