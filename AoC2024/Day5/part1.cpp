// part1.cpp
// code specific to part 1

#include <map>
#include <vector>

#include "common.h"

namespace Part1
{
    std::string run()
	{
		PageSorter pageSorter;

		int32_t sum = 0;

		while (InputTaker::get().moreToRead())
		{
		    std::string line = InputTaker::get().readLine();

			if (line.empty())
			{
			    /*if (!pageSorter.sorted())
					pageSorter.sort();*/

				continue;
			}

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

				if (pageSorter.checkOrder(nums))
				    sum += nums[(nums.size() - 1) / 2];
			}
		}

		std::stringstream retStr;
		retStr << "total sum is " << sum << std::endl;

		return retStr.str();
	}
}