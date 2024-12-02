// part2.cpp
// code specific to part 2

#include "common.h"

bool isSafe(const std::vector<uint16_t>& nums, const bool recursed = false)
{
    const int8_t ascending = nums[1] > nums[0] ? 1 : -1;
	bool safe = true;

	for (int i = 1; i < nums.size() && safe; ++i)
	{
		const int16_t diff = ascending * (nums[i] - nums[i - 1]);

		if (!(diff >= 1 && diff <= 3))
			safe = false;
	}

	if (safe)
		return true;

	if (recursed)
		return false;

	for (int index = 0; index < nums.size(); ++index)
	{
	    std::vector<uint16_t> smallerNums = nums;
		smallerNums.erase(smallerNums.begin() + index);

		if (isSafe(smallerNums, true))
			return true;
	}

	return false;
}

std::string part2()
{
	uint16_t numSafe = 0;

	while (InputTaker::get().moreToRead())
	{
		if (isSafe(getNumbers(InputTaker::get().readLine())))
			++numSafe;
	}

	std::stringstream retStr;
	retStr << "number of safe reports is " << numSafe << std::endl;

	return retStr.str();
}