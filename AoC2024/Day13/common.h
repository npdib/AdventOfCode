// common.h

#include <iostream>
#include <sstream>
#include <cstdint>

#include "inputtaker.h"

#include <optional>

class Machine
{
public:
	uint64_t x1, y1, U, x2, y2, V;

	std::optional<std::pair<uint64_t, uint64_t>> calculateMoves();
};