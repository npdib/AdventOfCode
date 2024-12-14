// common.h
#pragma once

#include <iostream>
#include <sstream>
#include <cstdint>

#include "inputtaker.h"
#include "matrix.h"

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

class BathroomArea
{
public:
	BathroomArea(const Vec& size)
		: m_size(size)
	{
	}

	void update();

	void addGuard(const Vec& pos, const Vec& vel) { m_guards.emplace_back(pos, vel, m_size); }

    [[nodiscard]] uint32_t getSafetyScore();
    friend std::ostream& operator<<(std::ostream& os, const BathroomArea& ba);
private:

	const Vec& m_size;

	std::vector<Guard> m_guards;
	std::vector<uint16_t> m_quadrants = {0, 0, 0, 0};
};