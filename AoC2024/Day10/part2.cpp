// part2.cpp
// code specific to part 2

#include "common.h"

namespace Part2
{
	std::string run()
	{
		Matrix map(InputTaker::readAllAsVector());

		std::vector<Trailhead> trailheads = findTrailheads(map);

		int totalRating = 0;

		for (auto& trailhead : trailheads)
		    totalRating += trailhead.getRating();

		std::stringstream retStr;
		retStr << "total rating is " << totalRating << std::endl;

		return retStr.str();
	}
}