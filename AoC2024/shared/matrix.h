#pragma once

#include <cstdint>
#include <vector>
#include <string>

typedef struct vector_t
{
    int16_t x;
    int16_t y;

    vector_t operator*(const int& rhs)
    {
        return {static_cast<int16_t>(x * rhs), static_cast<int16_t>(y * rhs)};
    }
} Vec;

typedef struct position_t
{
    int16_t x;
    int16_t y;

    position_t operator+(const Vec& dir) const
    {
        return {static_cast<int16_t>(x + dir.x), static_cast<int16_t>(y + dir.y)};
    }
} Pos;

class Matrix : public std::vector<std::string>
{
public:
    const std::string& operator[](const size_type pos) const
    {
        return std::vector<std::string>::operator[](pos);
    }

    const char& operator[](const Pos& pos) const
    {
        return (*this)[pos.x][pos.y];
    }
};