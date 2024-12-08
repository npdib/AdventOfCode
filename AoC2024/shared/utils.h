#pragma once
#include <string>
#include <vector>
#include <chrono>

namespace util
{
    std::vector<int> getNumbersFromLine(const std::string& line);

    class SimpleTimer
    {
    public:
	    void start();
	    void stop();
	    auto duration() const;

	    [[nodiscard]] bool running() const { return m_running; }

    private:
	    bool m_running = false;
        std::chrono::time_point<std::chrono::steady_clock> m_start, m_stop;
    };

    std::ostream& operator<<(std::ostream& os, SimpleTimer& tim);
}
