// common.cpp 
// common code for day 1 and 2

#include "common.h"

Guard::Guard(const Vec& pos, const char& dir)
    : m_guardLocation(pos)
{
    switch (dir)
    {
    case '^':
        m_guardDirection = Direction::Up;
        break;
    case '>':
        m_guardDirection = Direction::Right;
        break;
    case 'V':
        m_guardDirection = Direction::Down;
        break;
    case '<':
        m_guardDirection = Direction::Left;
        break;
    default:
        std::cout << "unexpected direction\n";
        break;
    }
}

Vec Guard::getNextLocation() const
{
    switch (m_guardDirection)
    {
    case Direction::Up:
        return (m_guardLocation - Vec(0, 1));
        break;
    case Direction::Down:
        return (m_guardLocation + Vec(0, 1));
        break;
    case Direction::Left:
        return (m_guardLocation - Vec(1, 0));
        break;
    case Direction::Right:
        return (m_guardLocation + Vec(1, 0));
        break;
    }

    return {0, 0};
}

void Guard::move()
{
    switch (m_guardDirection)
    {
    case Direction::Up:
        --m_guardLocation.y;
        break;
    case Direction::Down:
        ++m_guardLocation.y;
        break;
    case Direction::Left:
        --m_guardLocation.x;
        break;
    case Direction::Right:
        ++m_guardLocation.x;
        break;
    }
}

void Guard::rotate()
{
    switch (m_guardDirection)
    {
    case Direction::Up:
        m_guardDirection = Direction::Right;
        break;
    case Direction::Down:
        m_guardDirection = Direction::Left;
        break;
    case Direction::Left:
        m_guardDirection = Direction::Up;
        break;
    case Direction::Right:
        m_guardDirection = Direction::Down;
        break;
    }
}

Map::Map(const std::vector<std::string>& map)
    : m_map(map)
{
    findGuards();
}

void Map::findGuards()
{
    for (int i = 0; i < m_map.size(); ++i)
    {
        for (const auto& symbol : {'>', '<', '^', 'V'})
        {
            size_t pos, prevPos = -1;
            while ((pos = m_map[i].find(symbol, prevPos + 1)) != std::string::npos)
            {
                const Vec location = {static_cast<int>(pos), i};

                m_guards.emplace_back(location, symbol);
                markAsPatrolled(location);
                prevPos = pos;
            }
        }
    }
}

bool Map::update()
{
    for (auto it = m_guards.begin(); !m_guards.empty() && it != m_guards.end();)
    {
        const Vec& nextLocation = it->getNextLocation();

        if (nextLocation.x < 0 || nextLocation.x >= m_map[0].size()
            || nextLocation.y < 0 || nextLocation.y >= m_map.size())
        {
            m_guards.erase(it);
            continue;
        }

        const char icon = m_map[nextLocation.y][nextLocation.x];

        if (icon == '#')
        {
            it->rotate();
        }
        else
        {
            it->move();
            if (icon == '.')
                markAsPatrolled(nextLocation);
        }

        ++it;
    }

    return m_guards.empty();
}

void Map::markAsPatrolled(const Vec& pos)
{
    m_map[pos.y][pos.x] = 'X';
    ++m_patrolledSquares;
}

std::ostream& operator<<(std::ostream& os, const Map& map)
{
    os << '\n';

    for (const auto& line : map.m_map)
    {
        os << line << '\n';
    }

    return os;
}
