// common.h

#include <iostream>
#include <sstream>
#include <cstdint>
#include <set>

#include "inputtaker.h"
#include "matrix.h"

class Trailhead
{
public:
	Trailhead(const Matrix& map, const Vec& loc)
		: m_map(map)
	        , m_location(loc)
	{
	}

	[[nodiscard]] int getScore() { return calculateScore(); }
	[[nodiscard]] int getRating() { return calculateRating(); }

private:
	int calculateScore();
	int calculateRating();
	int findValidOnwardPaths(const uint8_t& val, const Vec& pos);

	std::set<std::tuple<int, int>> m_accessibleEndPoints;

	const Matrix& m_map;
	Vec m_location;
};

std::vector<Trailhead> findTrailheads(const Matrix& map);