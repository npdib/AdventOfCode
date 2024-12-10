// common.cpp 
// common code for day 1 and 2

#include "common.h"

int Trailhead::calculateScore()
{
    findValidOnwardPaths(0, m_location);

	return m_accessibleEndPoints.size();
}

int Trailhead::calculateRating()
{
	return findValidOnwardPaths(0, m_location);
}

int Trailhead::findValidOnwardPaths(const uint8_t& val, const Vec& pos)
{
    constexpr Vec up = {0, -1};
    constexpr Vec down = {0, 1};
    constexpr Vec left = {-1, 0};
    constexpr Vec right = {1, 0};

	if (val == 9)
	{
		m_accessibleEndPoints.insert({pos.x, pos.y});
		return 1;
	}

	int validOnwardPaths = 0;

	for (auto& dir : {up, down, left, right})
	{
		const Vec newPos = pos + dir;
		if (m_map.isValidCoord(newPos))
		{
			const uint8_t newVal = m_map[newPos] - '0';
			if (newVal == val + 1)
		    {
		        validOnwardPaths += findValidOnwardPaths(val + 1, pos + dir);
		    }
		}
	}

	return validOnwardPaths;
}

std::vector<Trailhead> findTrailheads(const Matrix& map)
{
	std::vector<Trailhead> trailheads;

	for (int i = 0; i < map.size(); ++i)
	{
		size_t pos, prevPos = -1;

		while ((pos = map[i].find('0', prevPos + 1)) != std::string::npos)
		{
			prevPos = pos;

			trailheads.emplace_back(map, Vec(pos, i));
		}
	}

	return trailheads;
}
