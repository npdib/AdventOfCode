// part1.cpp
// code specific to part 1

#include "common.h"

std::string part1()
{
	std::string input = InputTaker::readAll();

	size_t pos, prev_pos = -1;

	int64_t sum = 0;


	while ((pos = input.find("mul(", prev_pos + 1)) != std::string::npos)
	{
		prev_pos = pos;

		sum += parseMulCommand(input, pos);
	}

	std::stringstream retStr;
	retStr << "sum of all multiplications is " << sum << std::endl;

	return retStr.str();
}