// part2.cpp
// code specific to part 2

#include "common.h"

namespace Part2
{
	std::string run()
	{
		BathroomArea bathroom({101, 103});

	    while (InputTaker::get().moreToRead())
	    {
		    std::string line = InputTaker::get().readLine();

		    const size_t spaceIndex = line.find(' ');
		    const size_t firstComma = line.find(',');
		    const size_t secondComma = line.find(',', firstComma + 1);
		    const size_t firstEquals = line.find('=');
		    const size_t secondEquals = line.find('=', firstEquals + 1);

		    const Vec pos = {
			    std::stoi(line.substr(firstEquals + 1, firstComma - firstEquals - 1)),
			    std::stoi(line.substr(firstComma + 1, spaceIndex - firstComma - 1))
		    };

		    const Vec vel = {
			    std::stoi(line.substr(secondEquals + 1, secondComma - secondEquals - 1)),
			    std::stoi(line.substr(secondComma + 1))
		    };

		    bathroom.addGuard(pos, vel);
	    }

		// set up

		int seconds = 0;

        std::ofstream output("output.txt");


		while (seconds < 7000)
		{
		    output << ++seconds << '\n';
			bathroom.update();
            output << bathroom;
			output << "\n\n---------------------------------------------------------------------------------------------\n\n";
		}

        output.close();

		std::stringstream retStr;
		retStr << seconds << " outputs written to output.txt" << std::endl;

		return retStr.str();
	}
}