// part1.cpp
// code specific to part 1

#include "common.h"

namespace Part1
{
	std::string run()
	{
		Matrix map(InputTaker::readAllAsVector());

		std::map<char, AntennaeGroup> antennae;

		for (const auto& row : map)
        {
            for (const auto& c : row)
            {
	            if (c == '.' || antennae.contains(c))
					continue;

				antennae[c] = {c, map};
            }
        }

		std::set<std::tuple<int, int>> antinodes;

		for (const auto& ag : antennae | std::views::values)
		    antinodes.merge(ag.getAntinodes());

        std::stringstream retStr;
		retStr << "there are " << antinodes.size() << " unique locations of antinodes" << std::endl;

		return retStr.str();
	}
}