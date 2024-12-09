// part2.cpp
// code specific to part 2

#include "common.h"

namespace Part2
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

			for (uint64_t map = 0; map < pow(3.0, numbers.size() - 1); ++map)
			{
			    if (calculateSumWithConcatenation(target, numbers, map) == target)
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