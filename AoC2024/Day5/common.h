// common.h

#include <iostream>
#include <sstream>
#include <cstdint>
#include <map>
#include <vector>

#include "inputtaker.h"

class PageSorter
{
public:
	void addRule(const std::pair<uint16_t, uint16_t>& rule)
	{
		m_SortRules.push_back(rule);
	}

    void sort(std::vector<uint16_t>& nums);
	bool checkOrder(const std::vector<uint16_t>& nums) const;

private:
	uint16_t nItems = 0;
	std::vector<std::pair<uint16_t, uint16_t>> m_SortRules;
};