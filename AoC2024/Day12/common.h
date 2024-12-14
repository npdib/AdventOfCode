// common.h

#include <iostream>
#include <sstream>
#include <cstdint>
#include <set>

#include "inputtaker.h"
#include "matrix.h"

class Region
{
public:
    Region(Matrix map, const Vec& pos);

    std::set<Vec> getRegion();
    void addNeighbouringTiles(const Vec& pos);
    uint32_t getArea() const { return m_tiles.size(); };
    uint32_t getPerimeter() const;
    uint32_t getSides() const;

private:
    const char m_char;
    Matrix m_map;
    std::set<Vec> m_tiles;
};

std::vector<Region> getRegions();
