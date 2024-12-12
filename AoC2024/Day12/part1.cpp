// part1.cpp
// code specific to part 1

#include "common.h"

namespace Part1
{
	std::string run()
	{
		auto regions = getRegions();

		uint64_t sum = 0;
		for (const auto& region : regions)
			sum += region.getArea() * region.getPerimeter();

		std::stringstream retStr;
		retStr << "total price is " << sum << std::endl;

		return retStr.str();
	}
}