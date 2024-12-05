// part2.cpp
// code specific to part 2

#include "common.h"

namespace Part2
{
	std::string run()
	{
		PageSorter pageSorter;

		int32_t sum = 0;

		while (InputTaker::get().moreToRead())
		{
		    std::string line = InputTaker::get().readLine();

			if (line.empty())
				continue;

			if (line[2] == '|')
			{
			    const uint16_t lhs = std::stoi(line.substr(0, 2));
			    const uint16_t rhs = std::stoi(line.substr(3, 2));

				pageSorter.addRule({lhs, rhs});
			}
			else if (line[2] == ',')
			{
			    size_t index = 0;
				std::vector<uint16_t> nums;

				while (index <= line.size())
				{
				    nums.push_back(std::stoi(line.substr(index, 2)));
					index += 3;
				}

				if (!pageSorter.checkOrder(nums))
				{
					pageSorter.sort(nums);
				    sum += nums[(nums.size() - 1) / 2];
			    }
			}
		}

		std::stringstream retStr;
		retStr << "total sum is " << sum << std::endl;

		return retStr.str();
	}
}