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
