// part2.cpp
// code specific to part 2

#include "common.h"

std::string part2()
{
	std::string input = InputTaker::readAll();

	size_t prev_pos = -1;

	int64_t sum = 0;

	bool enabled = true;

	do
	{
	    if (enabled)
	    {
	        size_t mulPos = input.find("mul(", prev_pos + 1);
	        size_t disablePos = input.find("don't()", prev_pos + 1);

			if (mulPos == std::string::npos)
			    break; // no more multiplications

			if (disablePos != std::string::npos && disablePos < mulPos)
			{
				prev_pos = disablePos;
				enabled = false;
			}
			else
			{
				prev_pos = mulPos;
			    sum += parseMulCommand(input, mulPos);
			}
	    }
	    else
	    {
	        prev_pos = input.find("do()", prev_pos + 1);
			if (prev_pos != std::string::npos)
				enabled = true;
        }
	}
	while (prev_pos != std::string::npos);

	std::stringstream retStr;
	retStr << "sum of all multiplications is " << sum << std::endl;

	return retStr.str();
}