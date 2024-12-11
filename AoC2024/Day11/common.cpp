// common.cpp 
// common code for day 1 and 2

#include "common.h"

std::map<unsigned long long int, unsigned long long> Stone::next()
{
	if (!m_children.empty())
		return m_children;

	const int digitNum = static_cast<uint8_t>(floor(log10(val) + 1));
	if (val == 0)
	{
		m_children[1]++;
	}
	else if (digitNum % 2 == 0)
	{
		const uint32_t powOfTen = static_cast<uint32_t>(pow(10.0, digitNum / 2));
		m_children[val / powOfTen]++;
		m_children[val % powOfTen]++;
	}
	else
	{
		m_children[val * 2024]++;
	}

	return m_children;
}

Stones::Stones(const std::vector<int>& numbers)
{
	for (const auto& num : numbers)
		m_stoneCount[num]++;
}

void Stones::blink()
{
	auto temp = m_stoneCount;
	m_stoneCount.clear();
	for (const auto& [stone, count] : temp)
	{
		if (!m_flow.contains(stone))
			m_flow[stone] = Stone(stone);

		auto newVals = m_flow[stone].next();
		for (const auto& [stoneChildren, childrenCount] : newVals)
		    m_stoneCount[stoneChildren] += childrenCount * count;
	}
}

unsigned long long Stones::getNumberOfStones() const
{
	unsigned long long sum = 0;

	for (const auto& count : m_stoneCount | std::views::values)
		sum += count;

	return sum;
}

std::ostream& operator<<(std::ostream& os, const Stones& stones)
{
	for (const auto& [stone, count] : stones.m_stoneCount)
		os << stone << " x " << count << " | ";

	os << "\n";
	return os;
}
