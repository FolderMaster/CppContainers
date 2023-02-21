#pragma once

#include <iostream>

using namespace std;

namespace Containers
{
	const exception ValueNotFoundException = exception("Value is not found.");

	const exception ItemNotFoundException = exception("Item is not found.");

	const exception OccupiedKeyException = exception("Key is occupied.");

	const exception KeyNotFoundException = exception("Key is not found.");
}