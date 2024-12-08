// common.cpp 
// common code for day 1 and 2

#include "common.h"

Guard::Guard()
    : m_guardLocation({0, 0})
        , m_guardDirection(Direction::Up)
{
}

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

Vec Guard::getDirection() const
{
    switch (m_guardDirection)
    {
    case Direction::Up:
        return {0, -1};
    case Direction::Down:
        return {0, 1};
    case Direction::Left:
        return {-1, 0};
    case Direction::Right:
        return {1, 0};
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
    findGuard();
}

void Map::findGuard()
{
    for (int i = 0; i < m_map.size(); ++i)
    {
        for (const auto& symbol : {'>', '<', '^', 'V'})
        {
            if (m_map[i].find(symbol) != std::string::npos)
            {
                const Vec location = {static_cast<int>(m_map[i].find(symbol)), i};

                m_guard = Guard(location, symbol);
                markAsPatrolled(location);
                addToHistory();
            }
        }
    }
}

Map::UpdateState Map::update(bool isPart2)
{
    const Vec& nextLocation = m_guard.getLocation() + m_guard.getDirection();

    if (m_history[{nextLocation.x, nextLocation.y}].contains({m_guard.getDirection().x, m_guard.getDirection().y}))
        return UpdateState::RepeatedSquare;

    if (!isValidLocation(nextLocation))
        return UpdateState::OutOfBounds;

    if (const char icon = m_map[nextLocation.y][nextLocation.x]; icon == '#')
    {
        m_guard.rotate();
    }
    else
    {
        // not already an obstacle so potential to see what happens if an obstacle is put there

        if (isPart2 && icon == '.') // require to have not been there before
        {
            MapCache cache(*this);

            m_map[nextLocation.y][nextLocation.x] = '#';

            m_guard.rotate();
            addToHistory();

            bool finished = false;
            while (!finished)
            {
                switch (update())
                {
                case UpdateState::Running:
                    break;
                case UpdateState::RepeatedSquare:
                    m_loops.insert({nextLocation.x, nextLocation.y});
                    //std::cout << *this;
                case UpdateState::OutOfBounds:
                    finished = true;
                    break;
                }
            }
        }

        m_guard.move();
        if (icon == '.')
            markAsPatrolled(nextLocation);
    }

    addToHistory();
    return UpdateState::Running;
}

bool Map::isValidLocation(const Vec& pos) const
{
    return (pos.x >= 0 && pos.x < m_map[0].size()
            && pos.y >= 0 && pos.y < m_map.size());
}

void Map::markAsPatrolled(const Vec& pos)
{
    m_map[pos.y][pos.x] = 'X';
    ++m_patrolledSquares;
}

void Map::addToHistory()
{
    m_history[{m_guard.getLocation().x, m_guard.getLocation().y}].insert({m_guard.getDirection().x, m_guard.getDirection().y});
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
