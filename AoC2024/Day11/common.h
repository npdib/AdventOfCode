// common.h

#include <iostream>
#include <sstream>
#include <cstdint>

#include "inputtaker.h"
#include "utils.h"

#include <ranges>
#include <map>

class Stone
{
public:
	Stone() = default;

	Stone(const unsigned long long& _val)
		: val(_val)
	{
	}

	std::map<unsigned long long int, unsigned long long> next();
	
private:
	unsigned long long val;
	std::map<unsigned long long int, unsigned long long> m_children;
};

class Stones
{
public:
	Stones(const std::vector<int>& numbers);

	void blink();
	[[nodiscard]] unsigned long long getNumberOfStones() const;

	friend std::ostream& operator<<(std::ostream& os, const Stones& stones);

private:
	std::map<unsigned long long int, unsigned long long> m_stoneCount;
	std::map<unsigned long long, Stone> m_flow;
};