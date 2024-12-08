// part2.cpp
// code specific to part 2

#include "common.h"

namespace Part2
{
	std::string run()
	{
		Map map(InputTaker::readAllAsVector());

		while (map.update(true) == Map::UpdateState::Running) ;
		    //std::cout << map << "------------------------------";

		std::stringstream retStr;
		retStr << "guard could have been in " << map.getNumberOfLoops() << " loops" << std::endl;

		return retStr.str();
	}
}