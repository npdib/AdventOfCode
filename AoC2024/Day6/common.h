// common.h

#include <iostream>
#include <sstream>
#include <cstdint>

#include "inputtaker.h"

#include <vector>

#include "matrix.h"

class Guard
{
public:
    Guard(const Vec& pos, const char& dir);

    Vec getNextLocation() const;
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
    explicit Map(const std::vector<std::string>& map);
    bool update();
    [[nodiscard]] int getNumberOfPatrolledSquares() const { return m_patrolledSquares; }

    friend std::ostream& operator<<(std::ostream& os, const Map& map);

private:
    void findGuards();
    void markAsPatrolled(const Vec& pos);

    std::vector<std::string> m_map;
    std::vector<Guard> m_guards;

    int m_patrolledSquares = 0;
};

std::ostream& operator<<(std::ostream& os, const Map& map);
