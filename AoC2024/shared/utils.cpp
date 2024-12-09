#include "utils.h"

#include <iostream>

namespace util
{
    std::vector<int> getNumbersFromLine(const std::string& line)
    {
	    size_t spaceIndex = 0;
	    std::vector<int> nums;

	    do
	    {
		    size_t nextSpaceIndex = line.find(' ', spaceIndex + 1);

		    nums.emplace_back(std::stoi(line.substr(spaceIndex, nextSpaceIndex - spaceIndex)));

		    spaceIndex = nextSpaceIndex;
	    } while (spaceIndex != std::string::npos);

	    return nums;
    }

    void SimpleTimer::start()
	{
	    m_start = std::chrono::steady_clock::now();
		m_running = true;
	}

	void SimpleTimer::stop()
    {
	    m_stop = std::chrono::steady_clock::now();
		m_running = false;
    }

	auto SimpleTimer::duration() const
    {
	    return std::chrono::duration_cast<std::chrono::milliseconds>(m_stop - m_start);
    }

	SimpleTimer::~SimpleTimer()
    {
		if (running())
		{
		    stop();
		    std::cout << " -\t" << duration() << " when timer was destroyed\n";
	    }
    }

    std::ostream& operator<<(std::ostream& os, SimpleTimer& tim)
    {
	    if (!tim.running())
	    {
		    tim.start();
	    }
	    else
	    {
		    tim.stop();
		    os << " -\t" << tim.duration();
	    }

	    return os;
    }
}
