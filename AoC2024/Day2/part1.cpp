// part1.cpp
// code specific to part 1

#include "common.h"

std::string part1()
{
	uint16_t numSafe = 0;

	while (InputTaker::get().moreToRead())
	{
	    std::vector<uint16_t> nums = util::getNumbersFromLine(InputTaker::get().readLine());

		const int8_t ascending = nums[1] > nums[0] ? 1 : -1;
		bool safe = true;

		for (int i = 1; i < nums.size() && safe; ++i)
		{
		    const int16_t diff = ascending * (nums[i] - nums[i - 1]);

			if (!(diff >= 1 && diff <= 3))
				safe = false;
		}

		if (safe)
			++numSafe;
	}

	std::stringstream retStr;
	retStr << "number of safe reports is " << numSafe << std::endl;

	return retStr.str();
}