#pragma once

#include <exception>

namespace Containers
{
	const std::exception ValueNotFoundException = std::exception("Value is not found.");

	const std::exception ConstItemNotFoundException = std::exception("Const item is not found.");

	const std::exception ItemNotFoundException = std::exception("Item is not found.");

	const std::exception OccupiedKeyException = std::exception("Key is occupied.");

	const std::exception KeyNotFoundException = std::exception("Key is not found.");
}