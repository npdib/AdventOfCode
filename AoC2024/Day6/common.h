// common.h

#include <iostream>
#include <sstream>
#include <cstdint>
#include <map>
#include <set>

#include "inputtaker.h"

#include <vector>

#include "matrix.h"

class Guard
{
public:
    Guard();
    Guard(const Vec& pos, const char& dir);

    [[nodiscard]] Vec getLocation() const { return m_guardLocation; }
    Vec getDirection() const;
    void move();
    void rotate();

private:
    enum class Direction
    {
        Up,
        Down,
        Left,
        Right
    };

    Vec m_guardLocation;
    Direction m_guardDirection;
};

class Map
{
public:
    enum class UpdateState
    {
        Running,
        OutOfBounds,
        RepeatedSquare
    };

    explicit Map(const std::vector<std::string>& map);
    UpdateState update(bool isPart2 = false);
    bool isValidLocation(const Vec& pos) const;
    [[nodiscard]] int getNumberOfPatrolledSquares() const { return m_patrolledSquares; }
    [[nodiscard]] size_t getNumberOfLoops() const { return m_loops.size(); }

    friend std::ostream& operator<<(std::ostream& os, const Map& map);

private:
    void findGuard();
    void markAsPatrolled(const Vec& pos);
    void addToHistory();

    using History = std::map<std::tuple<int, int>, std::set<std::tuple<int, int>>>;

    History m_history;

    std::vector<std::string> m_map;
    Guard m_guard;

    class MapCache
    {
    public:
        MapCache(Map& map)
            : obj(map)
                , m_guard(map.m_guard)
                , m_map(map.m_map)
                , m_history(map.m_history)
        {
        }

        ~MapCache()
        {
            obj.m_guard = m_guard;
            obj.m_map = m_map;
            obj.m_history = m_history;
        }

    private:
        Map& obj;
        Guard m_guard;
        std::vector<std::string> m_map;
        History m_history;
    };

    friend class MapCache;

    int m_patrolledSquares = 0;
    std::set<std::tuple<int, int>> m_loops;
};

std::ostream& operator<<(std::ostream& os, const Map& map);
