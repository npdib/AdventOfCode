// part1.cpp
// code specific to part 1

#include "common.h"


namespace Part1
{
    uint8_t validXmas(const Matrix& grid, const Pos& pos)
    {
        if (grid[pos] != 'X')
            return 0;

        uint8_t validDirs = 0;

        for (int16_t u = -1; u <= 1; ++u)
        {
            for (int16_t v = -1; v <= 1; ++v)
            {
                if (u == 0 && v == 0)
                    continue;

                Vec dir(u, v);

                const Pos finalPos = pos + (dir * 3);

                if (finalPos.x < 0 || finalPos.x >= grid[0].size())
                    continue;

                if (finalPos.y < 0 || finalPos.y >= grid.size())
                    continue;

                if (grid[pos + dir] == 'M'
                    && grid[pos + (dir * 2)] == 'A'
                    && grid[pos + (dir * 3)] == 'S')
                {
                    ++validDirs;
                }            
            }
        }

        return validDirs;
    }

    std::string run()
    {
	    Matrix grid;

	    while (InputTaker::get().moreToRead())
	        grid.push_back(InputTaker::get().readLine());

        uint16_t sum = 0;

        for (int j = 0; j < grid.size(); ++j)
        {
            for (int i = 0; i < grid[j].size(); ++i)
            {
                sum += validXmas(grid, {i, j});
            }
        }

	    std::stringstream retStr;
	    retStr << "number of instances of XMAS is " << sum << std::endl;

	    return retStr.str();
    }
}