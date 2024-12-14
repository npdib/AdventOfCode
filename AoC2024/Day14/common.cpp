// common.cpp 
// common code for day 1 and 2

#include "common.h"

#include <iomanip>

void Guard::update()
{
	m_position += m_velocity;  // update the position of the guard

	if (m_position.x < 0)
		m_position.x += m_boardSize.x;

	if (m_position.y < 0)
		m_position.y += m_boardSize.y;

	m_position %= m_boardSize; // wrap the guard if necessary
}


void BathroomArea::update()
{
	for (auto& guard : m_guards)
		guard.update();
}

uint32_t BathroomArea::getSafetyScore()
{
	for (const auto& guard : m_guards)
	{
		const Vec pos = guard.getPosition();

		if (pos.x == m_size.x / 2 || pos.y == m_size.y / 2)
			continue;

		uint8_t quad = 0;

		if (pos.y > (m_size.y / 2))
			quad += 2;

		if (pos.x > (m_size.x / 2))
			quad += 1;

		++m_quadrants[quad];
	}

	uint32_t safetyScore = 1;

	for (const auto& quadrant : m_quadrants)
		safetyScore *= quadrant;

	return safetyScore;
}

std::ostream& operator<<(std::ostream& os, const BathroomArea& ba)
{
	std::vector<std::vector<uint16_t>> map;

	for (int j = 0; j < ba.m_size.y; ++j)
	{
		std::vector<uint16_t> row;
	    for (int i = 0; i < ba.m_size.x; ++i)
	    {
	        row.emplace_back(0);
	    }

		map.emplace_back(row);
	}

	for (const auto& guard : ba.m_guards)
	{
	    const Vec pos = guard.getPosition();
		++map[pos.y][pos.x];
	}

	std::stringstream ss;

	for (const auto& row : map)
	{
	    for (const auto& c : row)
	    {
			if (c > 0)
	            ss << c;
			else
	            ss << " ";
	    }

		ss << "\n";
	}

	os << ss.str();

    return os;
}