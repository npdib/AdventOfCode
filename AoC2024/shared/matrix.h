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

    int x;
    int y;
};

class Pos
{
public:
    constexpr Pos(int _x, int _y)
        : x(_x)
            , y(_y)
    {
    }

    Pos& operator+=(const Vec& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Pos operator+(const Vec& rhs) const
    {
        return {x + rhs.x, y + rhs.y};
    }

    int x;
    int y;
};

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