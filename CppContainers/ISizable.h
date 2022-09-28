#pragma once

namespace Containers
{
	class ISizable
	{
	public:
		virtual int GetSize() = 0;

		virtual bool IsEmpty() = 0;
	};
}