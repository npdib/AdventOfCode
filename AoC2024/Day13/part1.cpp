// part1.cpp
// code specific to part 1

#include "common.h"
#include "matrix.h"
#include <optional>

namespace Part1
{
    class Machine
    {
    public:
		uint64_t x1, y1, U, x2, y2, V;

		std::optional<std::pair<uint64_t, uint64_t>> calculateMoves();
    };

    std::optional<std::pair<uint64_t, uint64_t>> Machine::calculateMoves()
    {
		const int64_t bLhs = y2 * x1 - y1 * x2;
		const int64_t bRhs = V * x1 - U * y1;
		const int64_t b = bRhs / bLhs;

		if (bRhs % bLhs != 0 || b < 0)
		    return std::nullopt;


		const int64_t aLhs = x1;
		const int64_t aRhs = U - b * x2;
		const int64_t a = aRhs / aLhs;

		if (aRhs % aLhs != 0 || a < 0)
		    return std::nullopt;

		return std::pair(a, b);
    }


    std::string run()
	{
		std::vector<Machine> machines;
		Machine* currentMachine = nullptr;

		uint64_t sum = 0;

		while (InputTaker::get().moreToRead())
		{
            if (std::string line = InputTaker::get().readLine(); line.find('A') != std::string::npos)
			{
				machines.emplace_back();
				currentMachine = &machines.back();

			    const size_t firstPlus = line.find('+');
			    const size_t secondPlus = line.find('+', firstPlus + 1);
				const size_t comma = line.find(',');

				currentMachine->x1 = std::stoll(line.substr(firstPlus + 1, comma - firstPlus - 1));
				currentMachine->y1 = std::stoll(line.substr(secondPlus + 1));
			}
			else if (line.find('B') != std::string::npos)
			{
			    const size_t firstPlus = line.find('+');
			    const size_t secondPlus = line.find('+', firstPlus + 1);
				const size_t comma = line.find(',');

				currentMachine->x2 = std::stoll(line.substr(firstPlus + 1, comma - firstPlus - 1));
				currentMachine->y2 = std::stoll(line.substr(secondPlus + 1));
			}
			else if (line.find('X') != std::string::npos)
			{
			    const size_t firstEquals = line.find('=');
			    const size_t secondEquals = line.find('=', firstEquals + 1);
				const size_t comma = line.find(',');

				currentMachine->U = std::stoll(line.substr(firstEquals + 1, comma - firstEquals - 1));
				currentMachine->V = std::stoll(line.substr(secondEquals + 1));

                if (auto moves = currentMachine->calculateMoves(); moves != std::nullopt)
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
