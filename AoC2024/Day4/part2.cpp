// part2.cpp
// code specific to part 2

#include "common.h"

namespace Part2
{
    uint8_t validXMAS(const Matrix& grid, Position pos)
    {
        if (grid[pos] != 'A')
            return 0;

        constexpr Direction UL = {-1, -1};
        constexpr Direction UR = {1, -1};
        constexpr Direction DL = {-1, 1};
        constexpr Direction DR = {1, 1};

        if ((grid[pos + UL] != 'M' && grid[pos + UL] != 'S')
            || (grid[pos + UR] != 'M' && grid[pos + UR] != 'S'))
            return 0;

        if (grid[pos + UL] == 'M')
        {
            if (grid[pos + DR] != 'S')
                return 0;
        }
        else
        {
            if (grid[pos + DR] != 'M')
                return 0;
        }

        if (grid[pos + UR] == 'M')
            return grid[pos + DL] == 'S';
        else
            return grid[pos + DL] == 'M';
    }

     std::string run()
    {
	    Matrix grid;

	    while (InputTaker::get().moreToRead())
	        grid.push_back(InputTaker::get().readLine());

        uint16_t sum = 0;

        for (int16_t j = 1; j < grid.size() - 1; ++j)
        {
            for (int16_t i = 1; i < grid.at(j).size() - 1; ++i)
            {
                sum += validXMAS(grid, {i, j});
            }
        }

	    std::stringstream retStr;
	    retStr << "number of instances of XMAS is " << sum << std::endl;

	    return retStr.str();
    }
}