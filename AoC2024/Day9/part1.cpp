// part1.cpp
// code specific to part 1

#include "common.h"

namespace Part1
{
	std::string run()
	{
		std::string hardDrive = InputTaker::readAll();

		bool empty = false;

		unsigned long long int sum = 0;

		size_t frontIndex = 0;
		size_t backIndex = hardDrive.size() - 2;
		unsigned int frontId = 0;
		unsigned int backId = ((hardDrive.size()) / 2) - 1;
		uint8_t backLeft = hardDrive[backIndex] - '0';

		bool finished = false;

		for (int i = 0; i < hardDrive.size(); ++i)
		{
			if (finished)
				break;

			if (i == backIndex)
			{
				for (uint8_t j = 0; j < backLeft; ++j)
				{
				    sum += frontIndex * frontId;
					++frontIndex;
				}
				break;
			}

			const uint8_t num = hardDrive[i] - '0';
			if (!empty)
			{
				for (uint8_t j = 0; j < num; ++j)
				{
				    sum += frontIndex * frontId;
					++frontIndex;
				}
				++frontId;
			}
			else
			{
			    for (uint8_t j = 0; !finished && j < num; ++j)
				{
				    if (backLeft > 0)
				    {
				        sum += frontIndex * backId;
						--backLeft;
						++frontIndex;
				    }
					else
					{
					    backIndex -= 2;
						--backId;

						if (backIndex < i)
						{
						    finished = true;
							continue;
						}

						backLeft = hardDrive[backIndex] - '0';
						--j;
					}
				}
			}


			empty = !empty;
		}

		std::stringstream retStr;
		retStr << "sum is " << sum << std::endl;

		return retStr.str();
	}
}