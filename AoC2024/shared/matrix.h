#pragma once

#include <vector>
#include <string>

class Vec
{
public:
    constexpr Vec(int _x, int _y)
        : x(_x)
            , y(_y)
    {
    }

    Vec operator*(const int& rhs) const
    {
        return {x * rhs, y * rhs};
    }

    Vec operator-(const Vec& rhs) const
    {
        return {x - rhs.x, y - rhs.y};
    }

    Vec operator+(const Vec& rhs) const
    {
        return {x + rhs.x, y + rhs.y};
    }

    int x;
    int y;
};

class Matrix : public std::vector<std::string>
{
public:
    bool isValidCoord(const Vec& pos) const
    {
        return pos.x >= 0 && pos.x < (*this)[0].size() && pos.y >= 0 && pos.y < size();
    }

    const std::string& operator[](const size_type pos) const
    {
        return std::vector<std::string>::operator[](pos);
    }

    const char& operator[](const Vec& pos) const
    {
        return (*this)[pos.y][pos.x];
    }
};