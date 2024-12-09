// part1.cpp
// code specific to part 1

#include "common.h"

namespace Part1
{
	std::string run()
	{
		unsigned long long int sum = 0;

		while (InputTaker::get().moreToRead())
		{
		    std::string line = InputTaker::get().readLine();

			const size_t colon = line.find(':');

			const unsigned long long int target = std::stoll(line.substr(0, colon));

			std::vector<int> numbers = util::getNumbersFromLine(line.substr(colon + 1));

			for (uint32_t map = 0; map < static_cast<uint32_t>(1 << (numbers.size() - 1)); ++map)
			{
			    if (calculateSum(target, numbers, map) == target)
			    {
			        sum += target;
					break;
			    }
			}
		}

		std::stringstream retStr;
		retStr << "sum of reached targets is " << sum << std::endl;

		return retStr.str();
	}
}
