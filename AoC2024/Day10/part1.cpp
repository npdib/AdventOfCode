// part1.cpp
// code specific to part 1

#include <set>

#include "common.h"

namespace Part1
{
	std::string run()
	{
		Matrix map(InputTaker::readAllAsVector());
		std::vector<Trailhead> trailheads = findTrailheads(map);

		int totalScore = 0;

		for (auto& trailhead : trailheads)
		    totalScore += trailhead.getScore();

		std::stringstream retStr;
		retStr << "total score is " << totalScore << std::endl;

		return retStr.str();
	}
}