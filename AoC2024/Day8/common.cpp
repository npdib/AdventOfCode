// common.cpp 
// common code for day 1 and 2

#include "common.h"

AntennaeGroup::AntennaeGroup(const char& c, const Matrix& map)
    : m_mapWidth(map[0].size())
        , m_mapHeight(map.size())
{
    for (int y = 0; y < map.size(); ++y)
    {
        size_t pos, prevPos = -1;
        while ((pos = map[y].find(c, prevPos + 1)) != std::string::npos)
        {
            prevPos = pos;
            m_locations.emplace_back(static_cast<int>(pos), y);
        }
    }

    computeAntinodes();
    computeHarmonicAntinodes();
}

void AntennaeGroup::computeAntinodes()
{
    for (int i = 0; i < m_locations.size(); ++i)
    {
        for (int j = i + 1; j < m_locations.size(); ++j)
        {
            Vec pos1 = m_locations[i] * 2 - m_locations[j];
            Vec pos2 = m_locations[j] * 2 - m_locations[i];

            if (containedInGrid(pos1))
                m_antinodes.insert({pos1.x, pos1.y});

            if (containedInGrid(pos2))
                m_antinodes.insert({pos2.x, pos2.y});
        }
    }
}

void AntennaeGroup::computeHarmonicAntinodes()
{
    for (int i = 0; i < m_locations.size(); ++i)
    {
        m_harmonicAntinodes.insert({m_locations[i].x, m_locations[i].y});

        for (int j = i + 1; j < m_locations.size(); ++j)
        {
            Vec pos1 = m_locations[i];
            Vec pos2 = m_locations[j];
            Vec diff = pos1 - pos2;

            while (containedInGrid(pos1 + diff))
            {
                pos1 = pos1 + diff;
                m_harmonicAntinodes.insert({pos1.x, pos1.y});
            }

            while (containedInGrid(pos2 - diff))
            {
                pos2 = pos2 - diff;
                m_harmonicAntinodes.insert({pos2.x, pos2.y});
            }
        }
    }
}

bool AntennaeGroup::containedInGrid(const Vec& pos) const
{
    return pos.x >= 0 && pos.x < m_mapWidth && pos.y >= 0 && pos.y < m_mapHeight;
}
