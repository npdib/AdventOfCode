// common.cpp 
// common code for day 1 and 2

#include "common.h"

std::optional<std::pair<uint64_t, uint64_t>> Machine::calculateMoves()
{
	const int64_t bLhs = y2 * x1 - y1 * x2;
	const int64_t bRhs = V * x1 - U * y1;
	const int64_t b = bRhs / bLhs;

	if (bRhs % bLhs != 0 || b < 0)
		return std::nullopt;


	const int64_t aLhs = x1;
	const int64_t aRhs = U - b * x2;
	const int64_t a = aRhs / aLhs;

	if (aRhs % aLhs != 0 || a < 0)
		return std::nullopt;

	return std::pair(a, b);
}
