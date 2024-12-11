// part1.cpp
// code specific to part 1

#include "common.h"

namespace Part1
{
    std::string run()
	{
		std::vector<int> numbers = util::getNumbersFromLine(InputTaker::get().readLine());
		Stones stones(numbers);

		for (int i = 0; i < 25; ++i)
		    stones.blink();

		std::stringstream retStr;
		retStr << "after 25 blinks, there are " << stones.getNumberOfStones() << " stones." << std::endl;

		return retStr.str();
	}
}
