// part2.cpp
// code specific to part 2

#include "common.h"

namespace Part2
{
    std::string run()
	{
		std::vector<int> numbers = util::getNumbersFromLine(InputTaker::get().readLine());
		Stones stones(numbers);

		for (int i = 0; i < 75; ++i)
		    stones.blink();

		std::stringstream retStr;
		retStr << "after 75 blinks, there are " << stones.getNumberOfStones() << " stones." << std::endl;

		return retStr.str();
	}
}
