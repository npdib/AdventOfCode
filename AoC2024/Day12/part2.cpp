// part2.cpp
// code specific to part 2

#include "common.h"

namespace Part2
{
	std::string run()
	{
		auto regions = getRegions();

		uint64_t sum = 0;
		for (const auto& region : regions)
			sum += region.getArea() * region.getSides();

		std::stringstream retStr;
		retStr << "total price is " << sum << std::endl;

		return retStr.str();
	}
}