// part1.cpp
// code specific to part 1

#include "common.h"

namespace Part1
{
	std::string run()
	{
		Map map(InputTaker::readAllAsVector());

		while (map.update() == Map::UpdateState::Running) ;
		    //std::cout << map << "------------------------------";

		std::stringstream retStr;
		retStr << "guard visited " << map.getNumberOfPatrolledSquares() << " distinct squares" << std::endl;

		return retStr.str();
	}
}