// part1.cpp
// code specific to part 1

#include <algorithm>

#include "common.h"
#include "matrix.h"

namespace Part1
{
	class Guard
	{
	public:
		Guard(const Vec& pos, const Vec& vel, const Vec& boardSize)
		    : m_position(pos)
		        , m_velocity(vel)
		        , m_boardSize(boardSize)
		{
		}

		void update();

		[[nodiscard]] Vec getPosition() const { return m_position; }

	private:
	    Vec m_position;
		Vec m_velocity;
		Vec m_boardSize;
	};

    void Guard::update()
    {
		m_position += m_velocity;  // update the position of the guard

		if (m_position.x < 0)
			m_position.x += m_boardSize.x;

		if (m_position.y < 0)
			m_position.y += m_boardSize.y;

		m_position %= m_boardSize; // wrap the guard if necessary
    }

    class BathroomArea
	{
    public:
		BathroomArea(const Vec& size)
		    : m_size(size)
		{
		}

		void update();

		void addGuard(const Vec& pos, const Vec& vel) { m_guards.emplace_back(pos, vel, m_size); }

		uint32_t getSafetyScore();
    private:

		const Vec& m_size;

	    std::vector<Guard> m_guards;
		std::vector<uint16_t> m_quadrants = {0, 0, 0, 0};
	};

    void BathroomArea::update()
    {
		for (auto& guard : m_guards)
		    guard.update();
    }

    uint32_t BathroomArea::getSafetyScore()
    {
		for (const auto& guard : m_guards)
		{
		    const Vec pos = guard.getPosition();

			if (pos.x == m_size.x / 2 || pos.y == m_size.y / 2)
				continue;

			uint8_t quad = 0;

			if (pos.y > (m_size.y / 2))
				quad += 2;

			if (pos.x > (m_size.x / 2))
				quad += 1;

			++m_quadrants[quad];
		}

		uint32_t safetyScore = 1;

		for (const auto& quadrant : m_quadrants)
			safetyScore *= quadrant;

		return safetyScore;
    }

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

		for (int i = 0; i < 100; ++i)
			bathroom.update();

		std::stringstream retStr;
		retStr << "safety score is " << bathroom.getSafetyScore() << std::endl;

		return retStr.str();
	}
}
