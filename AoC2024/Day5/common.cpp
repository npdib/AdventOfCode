// common.cpp 
// common code for day 1 and 2

#include "common.h"

#include <algorithm>

bool PageSorter::checkOrder(const std::vector<uint16_t>& nums) const
{
	for (const auto& rule : m_SortRules)
	{
	    const auto left = std::ranges::find(nums, rule.first);
	    const auto right = std::ranges::find(nums, rule.second);

		if (left != nums.end() && right != nums.end())
	    {
	        if (left > right)
				return false;
	    }
	}

	return true;
}

 void PageSorter::sort(std::vector<uint16_t>& nums)
{
	bool sorted = false;

	while (!sorted)
	{
		sorted = true;

		for (const auto& rule : m_SortRules)
		{
		    const auto left = std::ranges::find(nums, rule.first);
	        const auto right = std::ranges::find(nums, rule.second);

		    if (left != nums.end() && right != nums.end())
	        {
	            if (left > right)
	            {
				    std::iter_swap(left, right);
					sorted = false;
				}
	        }
		}
	}
}