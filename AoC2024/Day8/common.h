// common.h

#include <iostream>
#include <sstream>
#include <set>
#include <ranges>
#include <map>
#include <cstdint>
#include "matrix.h"

#include "inputtaker.h"

class AntennaeGroup
{
public:
    AntennaeGroup() = default;
    AntennaeGroup(const char& c, const Matrix& map);
    [[nodiscard]] std::set<std::tuple<int, int>> getAntinodes() const { return m_antinodes; }
    [[nodiscard]] std::set<std::tuple<int, int>> getHarmonicAntinodes() const { return m_harmonicAntinodes; }

private:
    void computeAntinodes();
    void computeHarmonicAntinodes();

    [[nodiscard]] bool containedInGrid(const Vec& pos) const;

    uint16_t m_mapWidth, m_mapHeight;

    std::vector<Vec> m_locations;
    std::set<std::tuple<int, int>> m_antinodes;
    std::set<std::tuple<int, int>> m_harmonicAntinodes;
};