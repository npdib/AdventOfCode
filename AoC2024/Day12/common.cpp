// common.cpp 
// common code for day 1 and 2

#include "common.h"

Region::Region(Matrix map, const Vec& pos)
    : m_char(map[pos])
        , m_map(std::move(map))
{
    m_tiles.insert(pos);
}

std::set<Vec> Region::getRegion()
{
    addNeighbouringTiles(*m_tiles.begin());

    return m_tiles;
}

void Region::addNeighbouringTiles(const Vec& pos)
{
    for (const auto& dir : {up, down, left, right})
    {
        const Vec newLoc = pos + dir;
        const bool valid = m_map.isValidCoord(newLoc);
        const char newChar = valid ? m_map[newLoc] : ' ';
        const bool contains = m_tiles.contains(newLoc);

        if (valid && newChar == m_char && !contains)
        {
            m_tiles.insert(newLoc);
            addNeighbouringTiles(newLoc);
        }
    }
}

uint32_t Region::getPerimeter() const
{
    uint16_t perimeter = 0;

    for (const auto& tile : m_tiles)
    {
        perimeter += 4;

        for (const auto& dir : {up, down, left, right})
        {
            if (m_tiles.contains(tile + dir))
                --perimeter;
        }
    }

    return perimeter;
}

uint32_t Region::getSides() const
{
    uint32_t sides = 0;
    for (int i = 0; i <= m_map[0].size(); ++i)
    {
        for (int j = 0; j <= m_map.size(); ++j)
        {
            bool tl = false;
            bool tr = false;
            bool bl = false;
            bool br = false;
            int count = 0;

            if (i != 0 && j != 0 && m_tiles.contains({i - 1, j - 1}))
            {
                tl = true;
                ++count;
            }

            if (i != 0 && j != m_map.size() && m_tiles.contains({i - 1, j}))
            {
                bl = true;
                ++count;
            }

            if (i != m_map[0].size() && j != 0 && m_tiles.contains({i, j - 1}))
            {
                tr = true;
                ++count;
            }

            if (i != m_map[0].size() && j != m_map.size() && m_tiles.contains({i, j}))
            {
                br = true;
                ++count;
            }

            if (count % 2 == 1)
                ++sides;
            if ((tl && br && !tr && !bl)
                || (!tl && !br && tr && bl))
                sides += 2;
        }
    }

    //std::cout << sides << " sides\n";
    return sides;
}

std::vector<Region> getRegions()
{
	std::vector<Region> regions;
    std::set<Vec> accountedForTiles;

	const Matrix map(InputTaker::readAllAsVector());

	for (int j = 0; j < map.size(); ++j)
	{
		for (int i = 0; i < map[0].size(); ++i)
		{
		    if (!accountedForTiles.contains({i, j}))
		    {
		        Region region(map, Vec(i, j));
				accountedForTiles.merge(region.getRegion());
				regions.push_back(region);
		    }
		}
	}

    return regions;
}
