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

    Vec& operator+=(const Vec& rhs)
    {
        *this = *this + rhs;
        return *this;
    }

    Vec operator%(const Vec& rhs) const
    {
        return {x % rhs.x, y % rhs.y};
    }

    Vec& operator%=(const Vec& rhs)
    {
        *this = *this % rhs;
        return *this;
    }

    bool operator<(const Vec& rhs) const
    {
        if (x == rhs.x)
            return y < rhs.y;

        return x < rhs.x;
    }

    int x;
    int y;
};

constexpr Vec up = {0, -1};
constexpr Vec down = {0, 1};
constexpr Vec left = {-1, 0};
constexpr Vec right = {1, 0};

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

    std::string& operator[](const size_type pos)
    {
        return std::vector<std::string>::operator[](pos);
    }

    const char& operator[](const Vec& pos) const
    {
        return (*this)[pos.y][pos.x];
    }

    char& operator[](const Vec& pos)
    {
        return (*this)[pos.y][pos.x];
    }
};