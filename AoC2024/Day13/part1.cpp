// part1.cpp
// code specific to part 1

#include "common.h"

namespace Part1
{
    std::string run()
	{
		Machine currentMachine;

		uint64_t sum = 0;

		while (InputTaker::get().moreToRead())
		{
            if (std::string line = InputTaker::get().readLine(); line.find('A') != std::string::npos)
			{
			    const size_t firstPlus = line.find('+');
			    const size_t secondPlus = line.find('+', firstPlus + 1);
				const size_t comma = line.find(',');

				currentMachine.x1 = std::stoll(line.substr(firstPlus + 1, comma - firstPlus - 1));
				currentMachine.y1 = std::stoll(line.substr(secondPlus + 1));
			}
			else if (line.find('B') != std::string::npos)
			{
			    const size_t firstPlus = line.find('+');
			    const size_t secondPlus = line.find('+', firstPlus + 1);
				const size_t comma = line.find(',');

				currentMachine.x2 = std::stoll(line.substr(firstPlus + 1, comma - firstPlus - 1));
				currentMachine.y2 = std::stoll(line.substr(secondPlus + 1));
			}
			else if (line.find('X') != std::string::npos)
			{
			    const size_t firstEquals = line.find('=');
			    const size_t secondEquals = line.find('=', firstEquals + 1);
				const size_t comma = line.find(',');

				currentMachine.U = std::stoll(line.substr(firstEquals + 1, comma - firstEquals - 1));
				currentMachine.V = std::stoll(line.substr(secondEquals + 1));

                if (auto moves = currentMachine.calculateMoves(); moves != std::nullopt)
				{
					constexpr uint8_t A_COST = 3;
		            constexpr uint8_t B_COST = 1;

					sum += moves->first * A_COST + moves->second * B_COST;
			    }
			}
			else
			{
				continue;
			}
			
		}

		std::stringstream retStr;
		retStr << "total cost is " << sum << std::endl;

		return retStr.str();
	}
}
