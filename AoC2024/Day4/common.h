// common.h

#include <iostream>
#include <sstream>
#include <cstdint>

#include "inputtaker.h"

#include <vector>

typedef struct direction_t
{
    int16_t del_x;
    int16_t del_y;

    direction_t operator*(const int& rhs)
    {
        return {static_cast<int16_t>(del_x * rhs), static_cast<int16_t>(del_y * rhs)};
    }
} Direction;

typedef struct position_t
{
    int16_t x;
    int16_t y;

    position_t operator+(const Direction& dir) const
    {
        return {static_cast<int16_t>(x + dir.del_x), static_cast<int16_t>(y + dir.del_y)};
    }
} Position;

class Matrix : public std::vector<std::string>
{
public:
    std::string& operator[](const size_type pos)
    {
        return std::vector<std::string>::operator[](pos);
    }

    char operator[](const Position& pos) const
    {
        return at(pos.x)[pos.y];
    }
};