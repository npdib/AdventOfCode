#include "utils.h"

namespace util
{
    std::vector<uint16_t> getNumbersFromLine(const std::string& line)
    {
	    size_t spaceIndex = 0;
	    std::vector<uint16_t> nums;

	    do
	    {
		    size_t nextSpaceIndex = line.find(' ', spaceIndex + 1);

		    nums.emplace_back(std::stoi(line.substr(spaceIndex, nextSpaceIndex - spaceIndex)));

		    spaceIndex = nextSpaceIndex;
	    } while (spaceIndex != std::string::npos);

	    return nums;
    }
}
